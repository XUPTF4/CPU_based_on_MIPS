#include <stdbool.h>
#include <stdint.h>
#include "VCPU.h"
#include "VCPU___024root.h"

#include <sys/time.h>  // 添加头文件

#include "verilated_fst_c.h"
VerilatedFstC* tfp = new VerilatedFstC;

vluint64_t main_time = 0;  // initial 仿真时间

VCPU* top = new VCPU;

void step() {
    top->clk = 0;
    top->eval();

    tfp->dump(main_time);  // 记录波形数据
    main_time++;           // 时间递增

    top->clk = 1;
    top->eval();

    tfp->dump(main_time);
    main_time++;
}
void reset(int n) {
    top->rst = 1;
    while (n--) {
        step();
    }
    top->rst = 0;
}

// 执行一步
// int i = 0;
void stepi() {
    step();
}

// 执行 CPU
int cpu_exec(uint64_t n) {
    struct timeval start, end;
    gettimeofday(&start, NULL);  // 记录起始时间
    double elapsed_time, mips;

    int ret = 0;

    while (n) {
        stepi();
        if (top->rootp->CPU__DOT__idu__DOT__is_break) {
            if (top->rootp->CPU__DOT__idu_regaData == 1) {  // 标记退出信号
                printf("\n\033[31mHIT bad trap!\033[0m\n");

                ret = 1;
            } else {
                printf("\n\033[32mHIT good trap!\033[0m\n");

                ret = 0;
            }

            // 计数器
            gettimeofday(&end, NULL);
            elapsed_time = (end.tv_sec - start.tv_sec) +
                           (end.tv_usec - start.tv_usec) / 1e6;
            mips = ((uint64_t(-1) - n) / elapsed_time) / 1e6;
            printf("\nMIPS: %.6f MIPS\n", mips);
            break;
        } else if (top->rootp->CPU__DOT__idu__DOT__is_unknown) {
            printf(
                "\n\033[35munknown instruction----> "
                "PC:0x%08x--->INST:0x%08x\033[0m\n",
                top->rootp->CPU__DOT__ifu_pc,
                top->rootp->CPU__DOT__instMem_data);

            // 计数器
            gettimeofday(&end, NULL);
            elapsed_time = (end.tv_sec - start.tv_sec) +
                           (end.tv_usec - start.tv_usec) / 1e6;
            mips = ((uint64_t(-1) - n) / elapsed_time) / 1e6;
            printf("\nMIPS: %.6f MIPS\n", mips);
            ret = 1;
        }
        n--;
    }
    top->final();
    tfp->close();
    return ret;
}

int main(int argc, char* argv[]) {
    Verilated::traceEverOn(true);  //导出 FST 波形需要加此语句
    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    reset(5);

    int ret = cpu_exec(200);

    return ret;
}
