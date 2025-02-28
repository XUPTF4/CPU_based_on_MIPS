// 运算单元
// 这里主要实现 `ALU
// 发出跳转信号：跳转地址信号的生成需要 `ALU，放在 IDU 是不合理的
`include "Helpers.v"  // 包含 constants.v 文件
module EXU (
        input wire rst,                     // 复位信号
        // for reg
        output reg [31:0] regcData,         // 寄存器写数据
        output wire [4:0] regcAddr,         // 寄存器写地址
        output wire regcWr,                 // 寄存器写使能

        // for mem
        output wire [31:0] memAddr,         // 内存访问地址
        output wire [31:0] memData,         // 内存写数据
        output wire readWr,                 // 内存读使能
        output wire writeWr,                // 内存写使能
        output wire [3:0] rmask,            // 读掩码
        output wire [3:0] wmask,            // 写掩码


        // 来自上游的信号
        input wire [5:0] op_i,              // `ALU 功能 (输入信号)
        input wire [0:0] memWr_i,           // 内存写使能 (输入信号)
        input wire [0:0] memRr_i,           // 内存读使能 (输入信号)
        input wire [3:0] w_mask_i,          // w_mask (输入信号)
        input wire [3:0] r_mask_i,          // r_mask (输入信号)

        input wire [31:0] regaData_i,       // 源 A 数据
        input wire [31:0] regbData_i,       // 源 B 数据
        input wire [0:0] regcWr_i,          // 寄存器写使能 (输入信号)
        input wire [4:0] regcAddr_i,        // WB 数据地址
        input wire [31:0] rt_data_i,        // store 指令写入的数据，for MEM

        // HiLo
        input [31:0] rLoData_i,
        input [31:0] rHiData_i,

        output reg [31:0] wLoData,
        output reg wlo,
        output reg [31:0] wHiData,
        output reg whi

    );
    reg [31:0] alu_out;

    // WB
    assign regcAddr = regcAddr_i;
    assign regcWr = rst ? 1'b0 : regcWr_i;

    // 内存信号
    assign memAddr = alu_out; // 如果是 load：OK；如果是 store：
    assign memData = rt_data_i; // 那也 OK
    assign readWr = rst ? 1'b0 : memRr_i;
    assign writeWr = rst ? 1'b0 : memWr_i;
    assign rmask = r_mask_i;
    assign wmask = w_mask_i;


    // `ALU
    always @(*) begin
        if (rst) begin
            alu_out = 32'b0; // 复位时 `ALU 输出为 0
        end
        else begin
            case (op_i)
                `ALU_ADD:
                    alu_out = regaData_i + regbData_i;
                `ALU_LW:
                    alu_out = regaData_i + regbData_i; // LW
                `ALU_SW:
                    alu_out = regaData_i + regbData_i; // SW
                `ALU_JAL:
                    alu_out = regaData_i + regbData_i; // JAL
                `ALU_JALR:
                    alu_out = regaData_i + regbData_i; // JALR
                `ALU_BGEZAL:
                    alu_out = regaData_i + regbData_i;

                `ALU_SUB:
                    alu_out = regaData_i - regbData_i;
                `ALU_AND:
                    alu_out = regaData_i & regbData_i;
                `ALU_OR:
                    alu_out = regaData_i | regbData_i;
                `ALU_XOR:
                    alu_out = regaData_i ^ regbData_i;
                `ALU_SLL:
                    alu_out = regbData_i << regaData_i[4:0];
                `ALU_SRL:
                    alu_out = regbData_i >> regaData_i[4:0];
                `ALU_SRA:
                    alu_out = regbData_i >>> regaData_i[4:0]; // 数学右移
                `ALU_LUI:
                    alu_out = regaData_i;
                `ALU_SLTIU:
                    alu_out = regaData_i < regbData_i ? 32'b1 : 32'b0;
                `ALU_SLT:
                    alu_out = regaData_i < regbData_i ? 32'b1 : 32'b0;
                `ALU_SLTI:
                    alu_out = regaData_i < regbData_i ? 32'b1 : 32'b0;
                default:
                    alu_out = 32'b0;
            endcase
        end
    end

    // HiLo
    wire signed [63:
                 0] s_product = $signed( regaData_i) *  $signed(regbData_i);
    wire  [63:
           0] u_product = regaData_i * regbData_i;
    always @(*) begin
        case(op_i)
            `ALU_MULT:begin
                wLoData = s_product[31:0];   // LO寄存器写入低32位
                wHiData = s_product[63:32];  // HI寄存器写入高32位
                wlo = 1'b1;
                whi = 1'b1;
            end
            `ALU_MULTU:begin
                wLoData = u_product[31:0];
                wHiData = u_product[63:32];
                wlo = 1'b1;
                whi = 1'b1;
            end
            `ALU_DIV:begin
                if (regbData_i == 0) begin
                    wLoData = 32'hFFFFFFFF;  // 商为全1
                    wHiData = regaData_i;      // 余数保持被除数
                end
                else begin
                    wLoData = $signed(regaData_i) / $signed(regbData_i);
                    wHiData = $signed(regaData_i) % $signed(regbData_i);
                end
                wlo = (regbData_i != 0);  // 除零时不更新寄存器
                whi = (regbData_i != 0);
            end
            `ALU_DIVU:begin
                if (regbData_i == 0) begin
                    wLoData = 32'hFFFFFFFF;  // 商为全1
                    wHiData = regaData_i;      // 余数保持被除数
                end
                else begin
                    wLoData = regaData_i / regbData_i;
                    wHiData = regaData_i % regbData_i;
                end
                wlo = (regbData_i != 0);  // 除零时不更新寄存器
                whi = (regbData_i != 0);
            end
            `ALU_MTHI:begin
                wHiData = regaData_i;
                wLoData = 32'b0;
                wlo = 1'b0;
                whi = 1'b1;
            end
            `ALU_MTLO:begin
                wLoData = regaData_i;
                wHiData = 32'b0;
                whi = 1'b0;
                wlo = 1'b1;
            end
            default:begin
                wLoData = 32'b0;
                wHiData = 32'b0;
                wlo = 1'b0;
                whi = 1'b0;
            end
        endcase
    end

    // 数据移动指令
    always @(*) begin
        case(op_i)
            `ALU_MFHI:begin
                regcData = rHiData_i; // HI 寄存器写入 WB 数据
            end
            `ALU_MFLO:begin
                regcData = rLoData_i; // LO 寄存器写入 WB 数据
            end
            default:begin
                regcData = alu_out;
            end
        endcase
    end

endmodule
