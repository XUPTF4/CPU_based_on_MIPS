.DEFAULT_GOAL := build

# MIPS 工具链
MIPS_GCC = mips-linux-gnu-gcc
OBJCOPY = mips-linux-gnu-objcopy
HEXDUMP = hexdump

OBJDUMP = mips-linux-gnu-objdump

# 文件路径设置
CPU_HOME = /home/luyoung/CPU_based_on_MIPS
CSRC = $(wildcard $(CPU_HOME)/test_bench/am/*.c)  # 获取所有 .c 文件
ASM_SRC = $(CPU_HOME)/test_bench/am/start.S  # 汇编文件

LD_FALGS = -T $(CPU_HOME)/test_bench/am/link.ld -nostartfiles -nodefaultlibs

C_FLAGS = -O2 -mlong-calls

# 十六进制转储选项
FLAGS_HDUMP = -v -e '4/1 "%02x " "\n"'

# 输出目录
BUILD_DIR = build

# 默认目标
ALL ?= return

# C 文件和汇编文件
C_FILE = tests/$(ALL).c $(CSRC)

# 包含目录和标志
INCLUDE = include
INCFLAGS = $(addprefix -I, $(INCLUDE))

# 汇编文件路径
ASM_FILE = $(BUILD_DIR)/$(ALL)_mips.txt

# 编译目标
$(BUILD_DIR)/$(ALL).o: $(C_FILE) $(ASM_SRC)
	mkdir -p $(BUILD_DIR)

	# 针对每个源文件单独编译成 .o 文件
	for file in $(C_FILE); do \
		$(MIPS_GCC) -c $(C_FLAGS) $$file $(INCFLAGS) -o $(BUILD_DIR)/$$(basename $$file).o; \
	done

	# 编译 .S 汇编文件为 .o 文件
	$(MIPS_GCC) -mlong-calls -c $(ASM_SRC) $(INCFLAGS) -o $(BUILD_DIR)/$(ALL).asm.o

	# 链接所有目标文件（.c 和 .S 文件）生成一个单独的目标文件 (.o)
	$(MIPS_GCC) $(LD_FALGS) $(BUILD_DIR)/*.o -o $(BUILD_DIR)/$(ALL).o -Wl,-verbose
	# $(MIPS_GCC) $(LD_FALGS) $(BUILD_DIR)/$(ALL).asm.o $(BUILD_DIR)/*.o -o $(BUILD_DIR)/$(ALL).o

	# 使用 objcopy 提取 .text 段并生成二进制文件
	$(OBJCOPY) -O binary -j .text $(BUILD_DIR)/$(ALL).o $(BUILD_DIR)/$(ALL).bin

	# 使用 hexdump 转换为十六进制文件
	$(HEXDUMP) $(FLAGS_HDUMP) $(BUILD_DIR)/$(ALL).bin > $(BUILD_DIR)/$(ALL).hex

	# 反汇编 .o 文件
	$(OBJDUMP) -D -j .text $(BUILD_DIR)/$(ALL).o > $(ASM_FILE)

	# 处理汇编文件
	@echo "Processing $(ASM_FILE)..."
	@if [ -f $(ASM_FILE) ]; then \
		cp $(ASM_FILE) $(BUILD_DIR)/; \
		echo "$(ASM_FILE) copied to $(BUILD_DIR)"; \
	else \
		echo "$(ASM_FILE) not found."; \
	fi

build: $(BUILD_DIR)/$(ALL).o

clean:
	rm -rf build
