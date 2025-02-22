// 访存模块
// 这里同样使用 2K 的大小

module DataMem(
    input clk,
    input ce,
    input we,
    input [31:0] wtData,
    input [31:0] addr,
    output reg [31:0] rdData
);
    reg [31:0] memory [0:1023];

    always @(posedge clk) begin
        if (ce) begin
            if (we) begin
                // 写
                memory[addr] <= wtData;
            end
            // 读
            rdData <= memory[addr];
        end
    end

endmodule
