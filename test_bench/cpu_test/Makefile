.DEFAULT_GOAL := build
MIPS_GCC = mips-linux-gnu-gcc
OBJCOPY = mips-linux-gnu-objcopy
HEXDUMP = hexdump

FLAGS_HDUMP = -v -e '4/1 "%02x " "\n"'

BUILD_DIR = build

ALL ?= return

C_FILE = tests/$(ALL).c
ASM_FILE = $(BUILD_DIR)/$(ALL)_mips.txt

# 编译目标
$(BUILD_DIR)/$(ALL): $(C_FILE)
	mkdir -p $(BUILD_DIR)

	$(MIPS_GCC) -S $(C_FILE) -o $(BUILD_DIR)/$(ALL).s

	mv $(BUILD_DIR)/$(ALL).s $(ASM_FILE)

	$(MIPS_GCC) -c $(C_FILE) -o $(BUILD_DIR)/$(ALL).o

	$(OBJCOPY) -O binary -j .text $(BUILD_DIR)/$(ALL).o $(BUILD_DIR)/$(ALL).bin

	$(HEXDUMP) $(FLAGS_HDUMP) $(BUILD_DIR)/$(ALL).bin > $(BUILD_DIR)/$(ALL).hex

	@echo "Processing $(ASM_FILE)..."
	@if [ -f $(ASM_FILE) ]; then \
		cp $(ASM_FILE) $(BUILD_DIR)/; \
		echo "$(ASM_FILE) copied to $(BUILD_DIR)"; \
	else \
		echo "$(ASM_FILE) not found."; \
	fi
build: $(BUILD_DIR)/$(ALL)

clean:
	rm -rf build
