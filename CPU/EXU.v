// 运算单元
// 这里主要实现 ALU
// 发出跳转信号：跳转信号的生成需要 ALU，放在 IDU 是不合理的

`include "Helpers.v"  // 包含 constants.v 文件
module EXU (
        input wire [31:0] regaData,         // 源 A 数据
        input wire [31:0] regbData,         // 源 B 数据
        input wire  regcWr_i,               // 写使能
        input wire [4:0] regcAddr_i,        // 寄存器写地址

        // for reg
        output reg [31:0] regcData,         // 寄存器写数据
        output wire [4:0] regcAddr,         // 寄存器写地址
        output wire regcWr,                   // 寄存器写使能

        output reg [31:0] jAddr, 	        // 跳转地址

        // for mem
        output wire [31:0] memAddr,         // 内存访问地址
        output wire [31:0] memData,         // 内存访问数据
        output wire readWr,                 // 内存读使能
        output wire writeWr,                // 内存写使能
        output wire [3:0] rmask,            // 读掩码
        output wire [3:0] wmask,            // 写掩码

        // 来自上游的信号
        input wire [5:0] EXE_FUNC,    // ALU 功能 (输入信号)
        input wire [0:0] W_MEM_EN,      // 内存写使能 (输入信号)
        input wire [0:0] R_MEM_EN,      // 内存读使能 (输入信号)
        input wire [1:0] W_MASK,      // w_mask (输入信号)
        input wire [1:0] R_MASK,      // r_mask (输入信号)
        input wire [0:0] W_TYPE,      // 写入数据类型 (输入信号)
        input wire [0:0] REG_EN,      // 寄存器写使能 (输入信号)
        input wire [1:0] WB_SEL,      // WB 数据来源 (输入信号)
        input wire [4:0] Reg_Target     // WB 数据地址
    );

    assign regcWr = regcWr_i;
    assign regcAddr = regcAddr_i;
    reg [31:0] alu_out; // 为了利用 case，这里使用 reg。最终会被优化为 wire 的网表


    // ALU
    always @(*) begin
        case (EXE_FUNC)
            ALU_ADD:
                alu_out = regaData + regbData;
            ALU_JAL:
                alu_out = regaData + regbData; // JAL
            ALU_LW:
                alu_out = regaData + regbData; // LW
            ALU_SW:
                alu_out = regaData + regbData; // SW
            ALU_BEQ:
                // offset 左移两位，符号扩展 + PC -> 先扩展再左移
                // 该地址不一定跳转，还需要满足 jCe
                jAddr = (regaData << 2) + regbData;
            ALU_BNE:
                jAddr = (regaData << 2) + regbData;

            ALU_SUB:
                alu_out = regaData - regbData;
            ALU_AND:
                alu_out = regaData & regbData;
            ALU_OR:
                alu_out = regaData | regbData;
            ALU_XOR:
                alu_out = regaData ^ regbData;
            ALU_SLL:
                alu_out = regbData << regaData;
            ALU_SRL:
                alu_out = regbData >> regaData;
            ALU_SRA:
                alu_out = regbData >>> regaData; // 数学右移
            ALU_LUI:
                alu_out = regaData;

            default:
                alu_out = 32'b0;
        endcase
    end

    // 跳转目标
    always @(*) begin
        case (EXE_FUNC)
            ALU_J:
                jAddr = {regaData[31:28],regbData[25:0],2'b00};
            ALU_JAL:
                jAddr = {regaData[31:28],regbData[25:0],2'b00};
            ALU_JR:
                jAddr = {regaData[31:28],regbData[25:0],2'b00};
            default:
                jAddr = 32'd0;
        endcase
    end

    //



endmodule
