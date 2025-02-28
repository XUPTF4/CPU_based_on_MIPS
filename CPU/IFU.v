// 取指模块
module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号
        input wire [31:0] jAddr,    // 跳转地址
        input wire jCe,             // 跳转使能
        output reg [31:0] pc,       // 程序计数器
        output reg romCe           // 指令存储器使能信号
    );

    // 状态机,使用时序电路
    assign romCe = !rst;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h0;  // 复位时PC归零:假设 rom 从 0 地址开始

        end
        else if (jCe) begin
            pc <= jAddr;  // 跳转时，直接使用跳转地址
        end
        else begin
            pc <= pc + 32'd4;
        end
    end


endmodule
