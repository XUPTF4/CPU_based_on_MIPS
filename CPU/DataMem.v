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
        memory[0]  = 32'haeb1c2aa;
        memory[1]  = 32'h4500ff2b;
        memory[2]  = 32'h877190af;
        memory[3]  = 32'h11f42438;
        memory[4]  = 32'h19d29ab9;
        memory[5]  = 32'hdb1a18e4;
        memory[6]  = 32'hea15986d;
        memory[7]  = 32'h3ac3088e;
        memory[8]  = 32'h2649e980;
        memory[9]  = 32'hfc0db236;
        memory[10]  = 32'hfa4c43da;
        memory[11]  = 32'h0a4a7d30;
        memory[12]  = 32'h1299898e;
        memory[13]  = 32'h2c56b139;
        memory[14]  = 32'hdf8123d5;
        memory[15]  = 32'h0a319e65;
        memory[16]  = 32'h04d6dfa8;
        memory[17]  = 32'h4c15dd68;
        memory[18]  = 32'h38c5d79b;
        memory[19]  = 32'h9e4357a1;
        memory[20]  = 32'hf78b91cb;
        memory[21]  = 32'h1efc4248;
        memory[22]  = 32'h014255a4;
        memory[23]  = 32'h7fdfcc40;
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
