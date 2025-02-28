#!/bin/bash
# 配置区域
CPU_HOME=$(pwd)  # 获取当前工作目录
TEST_DIR="$CPU_HOME/test_bench/cpu_test/tests"
BUILD_DIR="$CPU_HOME/test_bench/cpu_test"
ROOT_DIR="$CPU_HOME"  # 注意这里不需要额外的斜杠
LOG_DIR="$CPU_HOME/test_logs"
MAX_PARALLEL=1  # 最大并行任务数


# 初始化日志目录
mkdir -p "$LOG_DIR"

# 颜色初始化
init_colors() {
    if [ -t 1 ]; then
        GREEN=$(tput setaf 2)
        RED=$(tput setaf 1)
        YELLOW=$(tput setaf 3)
        BOLD=$(tput bold)
        RESET=$(tput sgr0)
    else
        GREEN=""; RED=""; YELLOW=""; BOLD=""; RESET=""
    fi
}

# 打印带时间戳的信息
log() {
    local level=$1
    local message=$2
    local timestamp=$(date "+%Y-%m-%d %H:%M:%S")
    case $level in
        "INFO") echo -e "${BOLD}[${timestamp}] ${message}${RESET}" ;;
        "ERROR") echo -e "${RED}${BOLD}[${timestamp}] ERROR: ${message}${RESET}" >&2 ;;
        "WARN") echo -e "${YELLOW}${BOLD}[${timestamp}] WARNING: ${message}${RESET}" ;;
    esac
}

# 清理函数
cleanup() {
    log "INFO" "执行清理操作..."
    rm -rf "${LOG_DIR}/tmp.*"
}

# 注册退出处理
trap cleanup EXIT

# 主执行函数
run_test() {
    local test_file=$1
    local test_name=$(basename "$test_file" .c)
    local build_log="${LOG_DIR}/${test_name}.build.log"
    local run_log="${LOG_DIR}/${test_name}.run.log"
    local start_time=$(date +%s)

    # 编译阶段
    log "INFO" "开始编译测试用例: ${BOLD}${test_name}"
    cd "$BUILD_DIR" || return 1

    make clean > "$build_log" 2>&1
    if ! make build ALL="$test_name" >> "$build_log" 2>&1; then
        log "ERROR" "编译失败 - ${test_name}"
        echo "编译日志: $build_log"
        return 2
    fi

    # 运行阶段
    log "INFO" "开始运行测试用例: ${BOLD}${test_name}"
    cd "$ROOT_DIR" || return 1

    local run_status=0
    TIMEFORMAT="运行时间: %3R秒"
    time make run > "$run_log" 2>&1 || run_status=$?

    if [ $run_status -ne 0 ]; then
        log "ERROR" "运行失败 - ${test_name}"
        echo "运行日志: $run_log"
        return 3
    fi

    local end_time=$(date +%s)
    echo -e "${GREEN}${BOLD}测试通过: ${test_name} (耗时 $((end_time - start_time)) 秒)${RESET}"
    return 0
}

# 主流程
main() {
    init_colors
    log "INFO" "开始执行所有测试用例..."

    # 创建临时结果文件
    local result_file=$(mktemp "${LOG_DIR}/tmp.XXXXXXXXXX")

    mapfile -t tests < <(find "$TEST_DIR" -name "*.c")

    # 没有找到测试用例的情况
    if [ ${#tests[@]} -eq 0 ]; then
        log "ERROR" "在 ${TEST_DIR} 中没有找到任何测试用例"
        exit 1
    fi

    log "INFO" "找到以下测试用例:"
    printf ' - %s\n' "${tests[@]}"

    # 并行执行控制
    local counter=0
    for test_file in "${tests[@]}"; do
        ((counter++))
        (run_test "$test_file"; echo $? >> "$result_file") &

        # 控制并行数量
        if ((counter % MAX_PARALLEL == 0)); then
            wait
        fi
    done
    wait

    # 结果统计
    local total=0 pass=0 fail=0
    local results=()
    mapfile -t results < "$result_file"

    for code in "${results[@]}"; do
        ((total++))
        case $code in
            0) ((pass++)) ;;
            *) ((fail++)) ;;
        esac
    done

    # 打印汇总报告
    echo
    log "INFO" "测试结果汇总:"
    echo "├── 总测试用例: $total"
    echo "├── ${GREEN}通过用例: $pass${RESET}"
    echo "└── ${RED}失败用例: $fail${RESET}"

    # 返回最终状态
    [ $fail -eq 0 ] && exit 0 || exit 1
}

# 执行主函数
main