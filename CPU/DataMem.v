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
        memory[0]  = 32'h00000000;
        memory[1]  = 32'h00000001;
        memory[2]  = 32'h00000002;
        memory[3]  = 32'h7fffffff;
        memory[4]  = 32'h80000000;
        memory[5]  = 32'h80000001;
        memory[6]  = 32'hfffffffe;
        memory[7]  = 32'hffffffff;
        memory[8]  = 32'h00000001;
        memory[9]  = 32'h00000002;
        memory[10]  = 32'h00000003;
        memory[11]  = 32'h80000000;
        memory[12]  = 32'h80000001;
        memory[13]  = 32'h80000002;
        memory[14]  = 32'hffffffff;
        memory[15]  = 32'h00000000;
        memory[16]  = 32'h00000002;
        memory[17]  = 32'h00000003;
        memory[18]  = 32'h00000004;
        memory[19]  = 32'h80000001;
        memory[20]  = 32'h80000002;
        memory[21]  = 32'h80000003;
        memory[22]  = 32'h00000000;
        memory[23]  = 32'h00000001;
        memory[24]  = 32'h7fffffff;
        memory[25]  = 32'h80000000;
        memory[26]  = 32'h80000001;
        memory[27]  = 32'hfffffffe;
        memory[28]  = 32'hffffffff;
        memory[29]  = 32'h00000000;
        memory[30]  = 32'h7ffffffd;
        memory[31]  = 32'h7ffffffe;
        memory[32]  = 32'h80000000;
        memory[33]  = 32'h80000001;
        memory[34]  = 32'h80000002;
        memory[35]  = 32'hffffffff;
        memory[36]  = 32'h00000000;
        memory[37]  = 32'h00000001;
        memory[38]  = 32'h7ffffffe;
        memory[39]  = 32'h7fffffff;
        memory[40]  = 32'h80000001;
        memory[41]  = 32'h80000002;
        memory[42]  = 32'h80000003;
        memory[43]  = 32'h00000000;
        memory[44]  = 32'h00000001;
        memory[45]  = 32'h00000002;
        memory[46]  = 32'h7fffffff;
        memory[47]  = 32'h80000000;
        memory[48]  = 32'hfffffffe;
        memory[49]  = 32'hffffffff;
        memory[50]  = 32'h00000000;
        memory[51]  = 32'h7ffffffd;
        memory[52]  = 32'h7ffffffe;
        memory[53]  = 32'h7fffffff;
        memory[54]  = 32'hfffffffc;
        memory[55]  = 32'hfffffffd;
        memory[56]  = 32'hffffffff;
        memory[57]  = 32'h00000000;
        memory[58]  = 32'h00000001;
        memory[59]  = 32'h7ffffffe;
        memory[60]  = 32'h7fffffff;
        memory[61]  = 32'h80000000;
        memory[62]  = 32'hfffffffd;
        memory[63]  = 32'hfffffffe;
        memory[64]  = 32'h00000000;
        memory[65]  = 32'h00000001;
        memory[66]  = 32'h00000002;
        memory[67]  = 32'h7fffffff;
        memory[68]  = 32'h80000000;
        memory[69]  = 32'h80000001;
        memory[70]  = 32'hfffffffe;
        memory[71]  = 32'hffffffff;
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
