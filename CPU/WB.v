// 回写
module WB (
        input wire clk,
        input wire rst,             // 复位信号
        input wire [0:0] regWr,
        input wire [4:0] regAddr,
        input wire [31:0] regData,

        input wire [31:0] inst_debug_i,         // 用于 debug 的监视信号
        input wire [31:0] pc_debug_i,

        output wire [0:0] we,
        output wire [4:0] wAddr,
        output wire [31:0] wData,

        // 数据相关
        output wire wbu_regWr,
        output wire [31:0] wbu_data,
        output wire [4:0] wbu_regAddr,
        output reg is_break
    );

    // 寄存器组
    reg [0:0] reg_regWr_mem;
    reg [4:0] reg_regAddr_mem;
    reg [31:0] reg_regData_mem;

    reg [31:0] reg_inst_debug;
    reg [31:0] reg_pc_debug;

    always @(posedge clk or posedge rst) begin
        if(rst) begin
            reg_regWr_mem <= 1'b0;
            reg_regAddr_mem <= 5'd0;
            reg_regData_mem <= 32'd0;

            reg_inst_debug <= 32'd0;
            reg_pc_debug <= 32'd0;

        end
        else begin
            reg_regWr_mem <= regWr;
            reg_regAddr_mem <= regAddr;
            reg_regData_mem <= regData;

            reg_inst_debug <= inst_debug_i;
            reg_pc_debug <= pc_debug_i;
        end
    end
    wire [0:0] wb_regWr;
    wire [4:0] wb_regAddr;
    wire [31:0] wb_regData;

    wire [31:0] wb_inst_debug;
    wire [31:0] wb_pc_debug;

    assign wb_regWr = reg_regWr_mem;
    assign wb_regAddr = reg_regAddr_mem;
    assign wb_regData = reg_regData_mem;

    assign wb_inst_debug = reg_inst_debug;
    assign wb_pc_debug = reg_pc_debug;


    assign we = rst ? 1'b0:wb_regWr;
    assign wAddr = wb_regAddr;
    assign wData = wb_regData;

    // 解决数据相关
    assign wbu_regWr = wb_regWr;
    assign wbu_data = wb_regData;
    assign wbu_regAddr =wb_regAddr;

    // 如果 wbu 接收到了 break 指令，说明程序已经执行结束
    // 此时检测 X4 寄存器的值就行了

    always @(*) begin
        casez(reg_inst_debug)
            32'b000000_?????_?????_?????_?????_001101:
                is_break = 1'b1;
            default:
                is_break = 1'b0;
        endcase
    end
endmodule

