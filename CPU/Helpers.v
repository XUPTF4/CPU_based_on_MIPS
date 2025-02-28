`ifndef HELPERS_V // 防止重复包含的宏定义
`define HELPERS_V

// 符号扩展宏：signExtend(num, n)
`define signExtend(num, n) {{(32 - n){num[n - 1]}}, num}

// 零扩展宏：zeroExtend(num, n)
`define zeroExtend(num, n) {{(32 - n){1'b0}}, num}

// ALU 操作码宏定义
`define ALU_X         6'b000000
`define ALU_ADD       6'b000001
`define ALU_SUB       6'b000010
`define ALU_AND       6'b000011
`define ALU_OR        6'b000100
`define ALU_XOR       6'b000101
`define ALU_SLL       6'b000110
`define ALU_SRL       6'b000111
`define ALU_SRA       6'b001000
`define ALU_JR        6'b001001
`define ALU_ADDI      6'b001010
`define ALU_ANDI      6'b001011
`define ALU_ORI       6'b001100
`define ALU_XORI      6'b001101
`define ALU_LW        6'b001110
`define ALU_SW        6'b001111
`define ALU_BEQ       6'b010000
`define ALU_BNE       6'b010001
`define ALU_LUI       6'b010010
`define ALU_J         6'b010011
`define ALU_JAL       6'b010100
`define ALU_SYSCALL   6'b010101
`define ALU_BREAK     6'b010110
`define ALU_UNKNOWN    6'b010111
`define ALU_BGEZAL    6'b011000
`define ALU_ADDIU     6'b011001
`define ALU_SLTIU     6'b011010
`define ALU_BLEZ      6'b011011
`define ALU_SLT       6'b011100
`define ALU_SLTI      6'b011101
`define ALU_BGTZ      6'b011110
`define ALU_BLTZ      6'b011111
`define ALU_JALR      6'b100000
`define ALU_MULT      6'b100001
`define ALU_MULTU     6'b100010
`define ALU_DIV       6'b100011
`define ALU_DIVU      6'b100100
`define ALU_MFHI      6'b100101
`define ALU_MFLO      6'b100110
`define ALU_MTHI      6'b100111
`define ALU_MTLO      6'b101000
`define ALU_LL        6'b101001
`define ALU_SC        6'b101010
`define ALU_MFC0      6'b101011
`define ALU_MTC0      6'b101100
`define ALU_ERET      6'b101101

// 控制信号宏定义
`define FUNCT_ADD     6'b100000
`define FUNCT_SUB     6'b100010
`define FUNCT_AND     6'b100100
`define FUNCT_OR      6'b100101
`define FUNCT_XOR     6'b100110
`define FUNCT_SLL     6'b000000  // shamt 字段区分
`define FUNCT_SRL     6'b000010  // shamt 字段区分
`define FUNCT_SRA     6'b000011  // shamt 字段区分
`define FUNCT_JR      6'b001000  // rs 字段区分

`define FUNCT_ADDI    6'b001000
`define FUNCT_ANDI    6'b001100
`define FUNCT_ORI     6'b001101
`define FUNCT_XORI    6'b001110
`define FUNCT_LW      6'b100011

// 操作码字段宏定义
`define OP1_X       3'b000
`define OP1_RS      3'b001  // RS
`define OP1_LUI     3'b010  // LUI 服务
`define OP1_IM_SA   3'b011  // SA 立即数
`define OP1_PC      3'b100  // PC
`define OP1_IMS     3'b101  // 立即数符号扩展
`define OP1_IMZ     3'b110  // 立即数 0 扩展
`define OP1_IM       3'b111  // 立即数不扩展

// 数据通路字段宏定义
`define OP2_X           3'b000
`define OP2_ADDRESS     3'b001  // 跳转立即数
`define OP2_RT          3'b010  // RT
`define OP2_IM_8        3'b011  // 自定义立即数，用于 JAL
`define OP2_IM_4        3'b000  // 自定义立即数，用于 JAL 借用 OP2_X
`define OP2_PC          3'b100  // PC
`define OP2_IMS         3'b101  // 立即数符号扩展
`define OP2_IMZ         3'b110  // 立即数 0 扩展
`define OP2_IM_OFFSET_S 3'b111  // 立即数 offset 符号扩展

// 控制信号宏定义
`define WMEN_X 1'b0
`define WMEN_S 1'b1

`define RMEN_X 1'b0
`define RMEN_S 1'b1

`define WMASK_X 4'b0000
`define WMASK_A 4'b0001  // 1 字节
`define WMASK_B 4'b0011  // 2 字节
`define WMASK_C 4'b1111  // 4 字节

`define RMASK_X 4'b0000
`define RMASK_A 4'b0001
`define RMASK_B 4'b0011
`define RMASK_C 4'b1111

`define WTYPE_X 1'b0
`define WTYPE_S 1'b1
`define WTYPE_U 1'b0

`define REN_X 1'b0
`define REN_S 1'b1

`define WB_X    2'b00
`define WB_MEM  2'b01  // 来自内存
`define WB_ALU  2'b10  // 来自 ALU

`define WB_TYPE_X 1'b0
`define WB_TYPE_S 1'b1

`endif // HELPERS_V
