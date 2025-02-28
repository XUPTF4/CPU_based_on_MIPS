// 回写
module WB (
        input wire clk,
        input wire rst,             // 复位信号
        input wire [0:0] regWr,
        input wire [4:0] regAddr,
        input wire [31:0] regData,

        output wire [0:0] we,
        output wire [4:0] wAddr,
        output wire [31:0] wData

    );

    // 寄存器组
    reg [0:0] reg_regWr_mem;
    reg [4:0] reg_regAddr_mem;
    reg [31:0] reg_regData_mem;

    always @(posedge clk or posedge rst) begin
        if(rst) begin
            reg_regWr_mem <= 1'b0;
            reg_regAddr_mem <= 5'd0;
            reg_regData_mem <= 32'd0;

        end
        else begin
            reg_regWr_mem <= regWr;
            reg_regAddr_mem <= regAddr;
            reg_regData_mem <= regData;
        end
    end
    wire [0:0] wb_regWr;
    wire [4:0] wb_regAddr;
    wire [31:0] wb_regData;

    assign wb_regWr = reg_regWr_mem;
    assign wb_regAddr = reg_regAddr_mem;
    assign wb_regData = reg_regData_mem;

    assign we = rst ? 1'b0:wb_regWr;
    assign wAddr = wb_regAddr;
    assign wData = wb_regData;

endmodule

