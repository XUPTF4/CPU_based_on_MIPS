.DEFAULT_GOAL := build

# MIPS 工具链
MIPS_GCC = mips-linux-gnu-gcc

MIPS_LD = mips-linux-gnu-ld

OBJCOPY = mips-linux-gnu-objcopy
HEXDUMP = hexdump

OBJDUMP = mips-linux-gnu-objdump

# 文件路径设置
CPU_HOME = $(shell pwd)/../..
CSRC = $(wildcard $(CPU_HOME)/test_bench/am/*.c)
ASM_SRC1 = $(CPU_HOME)/test_bench/am/start.S
ASM_SRC2 = $(CPU_HOME)/test_bench/am/trap.S

# 包含目录和标志
INCLUDE = include
INCFLAGS = $(addprefix -I, $(INCLUDE))

# 汇编文件路径
ASM_FILE = $(BUILD_DIR)/$(ALL)_mips.txt

LD_FALGS = -T $(CPU_HOME)/test_bench/am/link.ld --allow-multiple-definition

# 一定要关闭编译优化，不然看波形看不懂
# -march=mips1 -mfp32 用于指定编译器生成的代码适用于 MIPS I 架构，且不使用浮点寄存器
# mult：传统MIPS乘法指令，产生64位结果（HI/LO寄存器）
# mul：MIPS32新增指令，直接产生32位结果（不涉及HI/LO）
# 这里直接使用 mips1 架构 来测试 mult 指令、mulu 指令、div 指令、divu 指令、mflo 指令、mfhi 指令，但是不支持 mtlo、mthi 指令
# mips2 架构支持 mtlo、mthi 指令，但是目前会让程序执行出错，仔细检查了原因，由于 t9 寄存器为 0，因此会跳转到 0 地址，导致程序执行出错
C_FLAGS = -O0 -MMD -Wall -march=mips1 -mfp32 -Werror -fno-asynchronous-unwind-tables \
        -ffreestanding -fno-builtin -fno-stack-protector -Wno-main -nostdlib -nodefaultlibs -fno-delayed-branch \
		-fno-inline

AS_FLAGS = -MMD $(INCFLAGS)

FLAGS_HDUMP = -v -e '4/1 "%02x " "\n"'

# 输出目录
BUILD_DIR = build

# 默认目标
ALL ?= return

# C 文件和汇编文件
C_FILE = tests/$(ALL).c $(CSRC)



# 编译目标
$(BUILD_DIR)/$(ALL).o: $(C_FILE) $(ASM_SRC1)
	@mkdir -p $(BUILD_DIR)

# 针对每个源文件单独编译成 .o 文件
	@for file in $(C_FILE); do \
		$(MIPS_GCC) -c $(C_FLAGS) $$file $(INCFLAGS) -o $(BUILD_DIR)/$$(basename $$file).o; \
	done

# 编译 .S 汇编文件为 .o 文件
	@$(MIPS_GCC) $(AS_FLAGS) -c $(ASM_SRC1) -o $(BUILD_DIR)/start.S.o
	@$(MIPS_GCC) $(AS_FLAGS) -c $(ASM_SRC2) -o $(BUILD_DIR)/trap.S.o

# 链接所有目标文件（.c 和 .S 文件）生成一个单独的目标文件 (.o)
	@$(MIPS_LD) $(LD_FALGS)  $(BUILD_DIR)/trap.S.o $(BUILD_DIR)/start.S.o $(BUILD_DIR)/trm.c.o $(BUILD_DIR)/$(ALL).c.o  -o $(BUILD_DIR)/$(ALL).o

# 使用 objcopy 提取 .text 段并生成二进制文件
	@$(OBJCOPY) -O binary -j .text $(BUILD_DIR)/$(ALL).o $(BUILD_DIR)/$(ALL).bin

# 使用 objcopy 提取 .data 段并生成二进制文件
	@$(OBJCOPY) -O binary -j .data -j .bss $(BUILD_DIR)/$(ALL).o $(BUILD_DIR)/$(ALL)_data.bin

# 使用 hexdump 转换为十六进制文件
	@$(HEXDUMP) $(FLAGS_HDUMP) $(BUILD_DIR)/$(ALL).bin > $(BUILD_DIR)/$(ALL).hex

# 使用 hexdump 转换为十六进制文件
	@$(HEXDUMP) $(FLAGS_HDUMP) $(BUILD_DIR)/$(ALL)_data.bin > $(BUILD_DIR)/$(ALL)_data.hex

# 反汇编 .o 文件
	@$(OBJDUMP) -D -j .text -M no-aliases $(BUILD_DIR)/$(ALL).o > $(ASM_FILE)

	@echo "\nConverts a hex file (.hex) to a Verilog memory initialization file (.v)."
# 这里调用 python 脚本将 .hex 文件转换为 .v 文件

	@python3 $(CPU_HOME)/scripts/build_instMemo.py $(BUILD_DIR)/$(ALL).hex $(CPU_HOME)/CPU/InstMem.v
	@python3 $(CPU_HOME)/scripts/build_dataMemo.py $(BUILD_DIR)/$(ALL)_data.hex $(CPU_HOME)/CPU/DataMem.v
	@echo "\nBuild done."

build: $(BUILD_DIR)/$(ALL).o

clean:
	@rm -rf build