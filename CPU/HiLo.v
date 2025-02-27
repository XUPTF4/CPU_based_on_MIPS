module HiLo (
        input        rst,        // 复位信号
        input        clk,        // 时钟信号
        input [31:0] wLoData_i,  // 低位数据输入
        input        wlo_i,      // 低位写使能
        input [31:0] wHiData_i,  // 高位数据输入
        input        whi_i,      // 高位写使能

        output reg [31:0] rLoData,  // 低位数据输出
        output reg [31:0] rHiData   // 高位数据输出
    );

    // 内部寄存器定义
    reg [31:0] reg_wLoData; // 低位寄存器
    reg [31:0] reg_wHiData; // 高位寄存器

    // 时序逻辑块
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_wLoData <= 32'h0;
            reg_wHiData <= 32'h0;
        end
        else begin
            if (wlo_i) begin
                reg_wLoData <= wLoData_i;
            end
            if (whi_i) begin
                reg_wHiData <= wHiData_i;
            end
        end
    end

    // 组合逻辑输出
    always @(*) begin
        rLoData = reg_wLoData;
        rHiData = reg_wHiData;
    end

endmodule
