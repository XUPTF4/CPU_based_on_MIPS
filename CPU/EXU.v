// 实现 `ALU
`include "Helpers.v"  // 包含 constants.v 文件
module EXU (
        input wire clk,
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
    // 寄存器组
    reg [5:0] reg_op_i_idu;
    reg [0:0] reg_memWr_i_idu;
    reg [0:0] reg_memRr_i_idu;
    reg [3:0] reg_w_mask_i_idu;
    reg [3:0] reg_r_mask_i_idu;
    reg [31:0] reg_regaData_i_idu;
    reg [31:0] reg_regbData_i_idu;
    reg [0:0] reg_regcWr_i_idu;
    reg [4:0] reg_regcAddr_i_idu;
    reg [31:0] reg_rt_data_i_idu;

    always @(posedge clk) begin
        reg_op_i_idu <= op_i;
        reg_memWr_i_idu <= memWr_i;
        reg_memRr_i_idu <= memRr_i;
        reg_w_mask_i_idu <= w_mask_i;
        reg_r_mask_i_idu <= r_mask_i;
        reg_regaData_i_idu <= regaData_i;
        reg_regbData_i_idu <= regbData_i;
        reg_regcWr_i_idu <= regcWr_i;
        reg_regcAddr_i_idu <= regcAddr_i;
        reg_rt_data_i_idu <= rt_data_i;
    end

    wire [5:0] exu_op;
    wire [0:0] exu_memWr;
    wire [0:0] exu_memRr;
    wire [3:0] exu_w_mask;
    wire [3:0] exu_r_mask;
    wire [31:0] exu_regaData;
    wire [31:0] exu_regbData;
    wire [0:0] exu_regcWr;
    wire [4:0] exu_regcAddr;
    wire [31:0] exu_rt_data;

    assign exu_op = reg_op_i_idu;
    assign exu_memWr = reg_memWr_i_idu;
    assign exu_memRr = reg_memRr_i_idu;
    assign exu_w_mask = reg_w_mask_i_idu;
    assign exu_r_mask = reg_r_mask_i_idu;
    assign exu_regaData = reg_regaData_i_idu;
    assign exu_regbData = reg_regbData_i_idu;
    assign exu_regcWr = reg_regcWr_i_idu;
    assign exu_regcAddr = reg_regcAddr_i_idu;
    assign exu_rt_data = reg_rt_data_i_idu;

    
    reg [31:0] alu_out;

    // WB
    assign regcAddr = exu_regcAddr;
    assign regcWr = rst ? 1'b0 : exu_regcWr;

    // 内存信号
    assign memAddr = alu_out; // 如果是 load：OK；如果是 store：
    assign memData = exu_rt_data; // 那也 OK
    assign readWr = rst ? 1'b0 : exu_memRr;
    assign writeWr = rst ? 1'b0 : exu_memWr;
    assign rmask = exu_r_mask;
    assign wmask = exu_w_mask;


    // `ALU
    always @(*) begin
        if (rst) begin
            alu_out = 32'b0; // 复位时 `ALU 输出为 0
        end
        else begin
            case (op_i)
                `ALU_ADD:
                    alu_out = exu_regaData + exu_regbData;
                `ALU_LW:
                    alu_out = exu_regaData + exu_regbData; // LW
                `ALU_SW:
                    alu_out = exu_regaData + exu_regbData; // SW
                `ALU_JAL:
                    alu_out = exu_regaData + exu_regbData; // JAL
                `ALU_JALR:
                    alu_out = exu_regaData + exu_regbData; // JALR
                `ALU_BGEZAL:
                    alu_out = exu_regaData + exu_regbData;

                `ALU_SUB:
                    alu_out = exu_regaData - exu_regbData;
                `ALU_AND:
                    alu_out = exu_regaData & exu_regbData;
                `ALU_OR:
                    alu_out = exu_regaData | exu_regbData;
                `ALU_XOR:
                    alu_out = exu_regaData ^ exu_regbData;
                `ALU_SLL:
                    alu_out = exu_regbData << exu_regaData[4:0];
                `ALU_SRL:
                    alu_out = exu_regbData >> exu_regaData[4:0];
                `ALU_SRA:
                    alu_out = exu_regbData >>> exu_regaData[4:0]; // 数学右移
                `ALU_LUI:
                    alu_out = exu_regaData;
                `ALU_SLTIU:
                    alu_out = exu_regaData < exu_regbData ? 32'b1 : 32'b0;
                `ALU_SLT:
                    alu_out = exu_regaData < exu_regbData ? 32'b1 : 32'b0;
                `ALU_SLTI:
                    alu_out = exu_regaData < exu_regbData ? 32'b1 : 32'b0;
                default:
                    alu_out = 32'b0;
            endcase
        end
    end

    // HiLo
    wire signed [63:
                 0] s_product = $signed( exu_regaData) *  $signed(exu_regbData);
    wire  [63:
           0] u_product = exu_regaData * exu_regbData;
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
                if (exu_regbData == 0) begin
                    wLoData = 32'hFFFFFFFF;  // 商为全1
                    wHiData = exu_regaData;      // 余数保持被除数
                end
                else begin
                    wLoData = $signed(exu_regaData) / $signed(exu_regbData);
                    wHiData = $signed(exu_regaData) % $signed(exu_regbData);
                end
                wlo = (exu_regbData != 0);  // 除零时不更新寄存器
                whi = (exu_regbData != 0);
            end
            `ALU_DIVU:begin
                if (exu_regbData == 0) begin
                    wLoData = 32'hFFFFFFFF;  // 商为全1
                    wHiData = exu_regaData;      // 余数保持被除数
                end
                else begin
                    wLoData = exu_regaData / exu_regbData;
                    wHiData = exu_regaData % exu_regbData;
                end
                wlo = (exu_regbData != 0);  // 除零时不更新寄存器
                whi = (exu_regbData != 0);
            end
            `ALU_MTHI:begin
                wHiData = exu_regaData;
                wLoData = 32'b0;
                wlo = 1'b0;
                whi = 1'b1;
            end
            `ALU_MTLO:begin
                wLoData = exu_regaData;
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
