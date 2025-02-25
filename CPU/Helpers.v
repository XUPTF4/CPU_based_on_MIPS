// Helpers.v

`ifndef HELPERS_V // 防止重复包含的宏定义
`define HELPERS_V
// 符号扩展宏：signExtend(num, n)
`define signExtend(num, n) {{(32 - n){num[n - 1]}}, num}
// 零扩展宏：zeroExtend(num, n)
`define zeroExtend(num, n) {{(32 - n){1'b0}}, num}

parameter ALU_X    = 6'b000000;
parameter ALU_ADD  = 6'b000001;
parameter ALU_SUB  = 6'b000010;
parameter ALU_AND  = 6'b000011;
parameter ALU_OR   = 6'b000100;
parameter ALU_XOR  = 6'b000101;
parameter ALU_SLL  = 6'b000110;
parameter ALU_SRL  = 6'b000111;
parameter ALU_SRA  = 6'b001000;
parameter ALU_JR   = 6'b001001;
parameter ALU_ADDI = 6'b001010;
parameter ALU_ANDI = 6'b001011;
parameter ALU_ORI  = 6'b001100;
parameter ALU_XORI = 6'b001101;

parameter ALU_LW      = 6'b001110;
parameter ALU_SW      = 6'b001111;
parameter ALU_BEQ     = 6'b010000;
parameter ALU_BNE     = 6'b010001;
parameter ALU_LUI     = 6'b010010;
parameter ALU_J       = 6'b010011;
parameter ALU_JAL     = 6'b010100;
parameter ALU_SYSCALL = 6'b010101;
parameter ALU_BREAK   = 6'b010110;
parameter ALU_UNKNOWN = 6'b010111;
parameter ALU_BGEZAL  = 6'b011000;
parameter ALU_ADDIU   = 6'b011001;
parameter ALU_SLTIU   = 6'b011010;
parameter ALU_BLEZ    = 6'b011011;
parameter ALU_SLT     = 6'b011100;
parameter ALU_SLTI    = 6'b011101;

parameter ALU_BGTZ    = 6'b011110;
parameter ALU_BLTZ    = 6'b011111;
parameter ALU_JALR    = 6'b100000;
parameter ALU_MULT    = 6'b100001;
parameter ALU_MULTU   = 6'b100010;
parameter ALU_DIV     = 6'b100011;
parameter ALU_DIVU    = 6'b100100;
parameter ALU_MFHI    = 6'b100101;
parameter ALU_MFLO    = 6'b100110;
parameter ALU_MTHI    = 6'b100111;
parameter ALU_MTLO    = 6'b101000;
parameter ALU_LL      = 6'b101001;
parameter ALU_SC      = 6'b101010;
parameter ALU_MFC0    = 6'b101011;
parameter ALU_MTC0    = 6'b101100;
parameter ALU_ERET    = 6'b101101;

//
parameter FUNCT_ADD  = 6'b100000;
parameter FUNCT_SUB  = 6'b100010;
parameter FUNCT_AND  = 6'b100100;
parameter FUNCT_OR   = 6'b100101;
parameter FUNCT_XOR  = 6'b100110;
parameter FUNCT_SLL  = 6'b000000; // shamt 字段区分
parameter FUNCT_SRL  = 6'b000010; // shamt 字段区分
parameter FUNCT_SRA  = 6'b000011; // shamt 字段区分
parameter FUNCT_JR   = 6'b001000; // rs 字段区分

parameter FUNCT_ADDI = 6'b001000;
parameter FUNCT_ANDI = 6'b001100;
parameter FUNCT_ORI  = 6'b001101;
parameter FUNCT_XORI = 6'b001110;
parameter FUNCT_LW   = 6'b100011;

parameter OP1_X     = 3'b000;
parameter OP1_RS    = 3'b001; // RS
parameter OP1_LUI   = 3'b010; // LUI 服务
parameter OP1_IM_SA = 3'b011; // SA 立即数
parameter OP1_PC    = 3'b100; // PC
parameter OP1_IMS   = 3'b101; // 立即数符号扩展
parameter OP1_IMZ   = 3'b110; // 立即数 0 扩展
parameter OP1_IM    = 3'b111; // 立即数不扩展

parameter OP2_X           = 3'b000;
parameter OP2_ADDRESS     = 3'b001; // 跳转立即数
parameter OP2_RT          = 3'b010; // RT
parameter OP2_IM_8        = 3'b011; // 自定义立即数，用于 JAL
parameter OP2_IM_4        = 3'b000; // 自定义立即数，用于 JAL 借用 OP2_X
parameter OP2_PC          = 3'b100; // PC
parameter OP2_IMS         = 3'b101; // 立即数符号扩展
parameter OP2_IMZ         = 3'b110; // 立即数 0 扩展
parameter OP2_IM_OFFSET_S = 3'b111; // 立即数 offset 符号扩展




parameter WMEN_X = 1'b0;
parameter WMEN_S = 1'b1;

parameter RMEN_X = 1'b0;
parameter RMEN_S = 1'b1;

parameter WMASK_X = 4'b0000;
parameter WMASK_A = 4'b0001; // 1 字节
parameter WMASK_B = 4'b0011; // 2 字节
parameter WMASK_C = 4'b1111; // 4 字节

parameter RMASK_X = 4'b0000;
parameter RMASK_A = 4'b0001;
parameter RMASK_B = 4'b0011;
parameter RMASK_C = 4'b1111;

parameter WTYPE_X = 1'b0;
parameter WTYPE_S = 1'b1;
parameter WTYPE_U = 1'b0;

parameter REN_X = 1'b0;
parameter REN_S = 1'b1;

parameter WB_X   = 2'b00;
parameter WB_MEM = 2'b01; // 来自内存
parameter WB_ALU = 2'b10; // 来自 ALU

parameter WB_TYPE_X = 1'b0;
parameter WB_TYPE_S = 1'b1;


`endif // HELPERS_V
