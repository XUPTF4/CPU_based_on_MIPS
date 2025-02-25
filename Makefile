CPU_HOME = .
VSRC = $(CPU_HOME)/CPU/*.v

SV_SRC = $(CPU_HOME)/CPU
VERILATOR = verilator
TOP = CPU
CPPSRC = $(CPU_HOME)/Verilator/*.c*
SRC = $(CPPSRC)

V_FLAGS = --cc $(VSRC) --top $(TOP) --exe $(SRC) --trace-fst -I$(SV_SRC)

OBJ_DIR = obj_dir

EXE = $(CPU_HOME)/$(OBJ_DIR)/V$(TOP)

simu: clean
	$(VERILATOR) $(V_FLAGS)

build: simu
	bear -- make -C $(OBJ_DIR) -f V$(TOP).mk -j6

run: build
	$(EXE)

clean:
	@rm -rf $(OBJ_DIR)

.PHONY: simu build run



