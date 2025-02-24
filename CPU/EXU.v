// 运算单元
// 这里主要实现 ALU
// 发出跳转信号：跳转地址信号的生成需要 ALU，放在 IDU 是不合理的
`include "Helpers.v"  // 包含 constants.v 文件
module EXU (
        input wire rst,                     // 复位信号
        // for reg
        output reg [31:0] regcData,         // 寄存器写数据
        output wire [4:0] regcAddr,         // 寄存器写地址
        output wire regcWr,                 // 寄存器写使能

        // 跳转地址的生成
        output reg [31:0] jAddr, 	        // 跳转地址

        // for mem
        output wire [31:0] memAddr,         // 内存访问地址
        output wire [31:0] memData,         // 内存写数据
        output wire readWr,                 // 内存读使能
        output wire writeWr,                // 内存写使能
        output wire [3:0] rmask,            // 读掩码
        output wire [3:0] wmask,            // 写掩码


        // 来自上游的信号
        input wire [5:0] op_i,              // ALU 功能 (输入信号)
        input wire [0:0] memWr_i,           // 内存写使能 (输入信号)
        input wire [0:0] memRr_i,           // 内存读使能 (输入信号)
        input wire [3:0] w_mask_i,          // w_mask (输入信号)
        input wire [3:0] r_mask_i,          // r_mask (输入信号)

        input wire [31:0] regaData_i,       // 源 A 数据
        input wire [31:0] regbData_i,       // 源 B 数据
        input wire [0:0] regcWr_i,          // 寄存器写使能 (输入信号)
        input wire [4:0] regcAddr_i,        // WB 数据地址
        input wire [31:0] rt_data_i,        // store 指令写入的数据，for MEM

        output wire [1:0] is_OK             // 标记程序退出时的状态
    );

    // WB
    assign regcData = alu_out;
    assign regcAddr = regcAddr_i;
    assign regcWr = rst ? 1'b0 : regcWr_i;

    // 跳转地址
    assign jAddr = 32'd0;

    // 内存信号
    assign memAddr = alu_out; // 如果是 load：OK；如果是 store：
    assign memData = rt_data_i; // 那也 OK
    assign readWr = rst ? 1'b0 : memRr_i;
    assign writeWr = rst ? 1'b0 : memWr_i;
    assign rmask = r_mask_i;
    assign wmask = w_mask_i;

    // 默认输出
    assign is_OK = 2'b00;

    reg [31:0] alu_out;
    // ALU
    always @(*) begin
        if (rst) begin
            alu_out = 32'b0; // 复位时 ALU 输出为 0
        end
        else begin
            case (op_i)
                ALU_ADD:
                    alu_out = regaData_i + regbData_i;
                ALU_LW:
                    alu_out = regaData_i + regbData_i; // LW
                ALU_SW:
                    alu_out = regaData_i + regbData_i; // SW
                ALU_JAL:
                    alu_out = regaData_i + regbData_i; // JAL
                ALU_BEQ:
                    alu_out = (regaData_i << 2) + regbData_i;
                ALU_BNE:
                    alu_out = (regaData_i << 2) + regbData_i;
                ALU_SUB:
                    alu_out = regaData_i - regbData_i;
                ALU_AND:
                    alu_out = regaData_i & regbData_i;
                ALU_OR:
                    alu_out = regaData_i | regbData_i;
                ALU_XOR:
                    alu_out = regaData_i ^ regbData_i;
                ALU_SLL:
                    alu_out = regbData_i << regaData_i;
                ALU_SRL:
                    alu_out = regbData_i >> regaData_i;
                ALU_SRA:
                    alu_out = regbData_i >>> regaData_i; // 数学右移
                ALU_LUI:
                    alu_out = regaData_i;
                default:
                    alu_out = 32'b0;
            endcase
        end
    end


    always @(*) begin
        if (rst) begin
            jAddr = 32'b0;
        end
        else begin
            case ( op_i)
                ALU_J:
                    jAddr = {regaData_i[31:28],regbData_i[25:0],2'b00};
                ALU_JR:
                    jAddr = {regaData_i[31:28],regbData_i[25:0],2'b00};
                ALU_JAL:
                    jAddr = {regaData_i[31:28],regbData_i[25:0],2'b00};
                ALU_BEQ:
                    jAddr = alu_out; // 直接连接 alu_out
                ALU_BNE:
                    jAddr = alu_out; // 直接连接 alu_out
                default:
                    jAddr = 32'b0;
            endcase
        end
    end
    always @(*) begin
        case (op_i)
            ALU_SYSCALL:
                is_OK = 2'b00;
            ALU_BREAK:
                is_OK = alu_out[1:0];
            default:
                is_OK = 2'b00;
        endcase

    end
endmodule
