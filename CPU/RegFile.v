// 寄存器
module RegFile (
        input wire clk,                 // 时钟信号
        input wire rst,                 // 复位信号

        // to IDU
        output wire [31:0] regaData,    // 读端口 A 数据
        output wire [31:0] regbData,    // 读端口 B 数据

        // from IDU
        input wire [4:0] regaAddr,      // 读端口 A 地址
        input wire regaRd,              // 读使能
        input wire [4:0] regbAddr,      // 读端口 B 地址
        input wire  regbRd,             // 读使能

        // from WBU
        input wire we,                  // 写使能
        input wire [4:0] wAddr,         // 写地址
        input wire [31:0] wData         // 写数据
    );

    reg [31:0] registers [31:0];  // 32 个 32 位寄存器

    // 读操作
    assign regaData = (regaRd) ? registers[regaAddr] : 32'b0;
    assign regbData = (regbRd) ? registers[regbAddr] : 32'b0;

    // 写操作
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            registers[0] <= 32'b0;
            registers[1] <= 32'b0;
            registers[2] <= 32'b0;
            registers[3] <= 32'b0;
            registers[4] <= 32'b0;
            registers[5] <= 32'b0;
            registers[6] <= 32'b0;
            registers[7] <= 32'b0;
            registers[8] <= 32'b0;
            registers[9] <= 32'b0;
            registers[10] <= 32'b0;
            registers[11] <= 32'b0;
            registers[12] <= 32'b0;
            registers[13] <= 32'b0;
            registers[14] <= 32'b0;
            registers[15] <= 32'b0;
            registers[16] <= 32'b0;
            registers[17] <= 32'b0;
            registers[18] <= 32'b0;
            registers[19] <= 32'b0;
            registers[20] <= 32'b0;
            registers[21] <= 32'b0;
            registers[22] <= 32'b0;
            registers[23] <= 32'b0;
            registers[24] <= 32'b0;
            registers[25] <= 32'b0;
            registers[26] <= 32'b0;
            registers[27] <= 32'b0;
            registers[28] <= 32'b0;
            registers[29] <= 32'b0;
            registers[30] <= 32'b0;
            registers[31] <= 32'b0;

        end
        else if (we) begin
            registers[wAddr] <= wData;  // 写操作
        end
    end

endmodule
