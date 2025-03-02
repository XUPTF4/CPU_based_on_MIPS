module DataMem(
    input clk,
    input ce,
    input we,
    input [31:0] wtData,
    input [31:0] addr,
    input memRr,                // 内存读使能
    input [3:0] w_mask,         // 写掩码
    input [3:0] r_mask,         // 读掩码
    output reg [31:0] rdData    // 组合逻辑直接输出
);
    reg [31:0] memory [0:1023]; // 4KB 内存
// 初始化 memory

    initial begin
        memory[0]  = 32'h00000065;
        memory[1]  = 32'h00000067;
        memory[2]  = 32'h0000006b;
        memory[3]  = 32'h0000006d;
        memory[4]  = 32'h00000071;
        memory[5]  = 32'h0000007f;
        memory[6]  = 32'h00000083;
        memory[7]  = 32'h00000089;
        memory[8]  = 32'h0000008b;
        memory[9]  = 32'h00000095;
        memory[10]  = 32'h00000000;
        memory[11]  = 32'h00000000;
    end

    // 组合逻辑读操作：地址变化立即生效
    always @(*) begin
        if (ce && memRr) begin
            case (r_mask)
                4'b0001: rdData = {24'd0, memory[addr[11:2]][7:0]};   // 读低 8 位
                4'b0011: rdData = {16'd0, memory[addr[11:2]][15:0]};  // 读低 16 位
                default: rdData = memory[addr[11:2]];                 // 读全 32 位
            endcase
        end else begin
            rdData = 32'd0;  // 非读使能时输出 0
        end
    end

    // 同步写操作（需时钟）
    always @(posedge clk) begin
        if (ce && we) begin
            case(w_mask)
                4'b0001: memory[addr[11:2]][7:0]   <= wtData[7:0];    // 写低 8 位
                4'b0011: memory[addr[11:2]][15:0]  <= wtData[15:0];   // 写低 16 位
                default: memory[addr[11:2]]        <= wtData;         // 写全 32 位
            endcase
        end
    end
endmodule
