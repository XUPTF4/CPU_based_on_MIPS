// 这是回写模块，增加一个并行的部件意味着可以增加一级流水
// 这里进行修改寄存器，pc 除外，pc 的修改按照学校参考设计在了 ifu
module WB (
        input wire rst,             // 复位信号
        input wire [0:0] regWr,
        input wire [4:0] regAddr,
        input wire [31:0] regData,

        output wire [0:0] we,
        output wire [4:0] wAddr,
        output wire [31:0] wData

    );
    assign we = rst ? 1'b0:regWr;
    assign wAddr = regAddr;
    assign wData = regData;

endmodule

