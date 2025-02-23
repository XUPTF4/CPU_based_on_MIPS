module DataMem(
    input clk,
    input ce,
    input we,
    input [31:0] wtData,
    input [31:0] addr,
    input memRr,      // 内存读使能 (输出信号)
    input [3:0] w_mask,        // w_mask (写掩码)
    input [3:0] r_mask,        // r_mask (读掩码)

    output reg [31:0] rdData // 输出给 MEM
);
    reg [31:0] memory [0:1023];  // 4KB 内存
    reg [31:0] temp_mem_data;
    reg [31:0] temp_reg_data;

    // 内存读取逻辑：同步读取
    always @(posedge clk) begin
        if (ce) begin
            temp_mem_data <= memory[addr];
        end
    end

    // 预处理
    always @(*) begin
        case(w_mask)
            4'b0001: temp_reg_data = {temp_mem_data[31:8], wtData[7:0]};    // 写入低 8 位
            4'b0011: temp_reg_data = {temp_mem_data[31:16], wtData[15:0]};   // 写入低 16 位
            default: temp_reg_data = wtData;                                // 写入整个 32 位数据
        endcase
    end

    // 写操作
    always @(posedge clk) begin
        if (ce && we) begin
            memory[addr] <= temp_reg_data;  // 写入数据到内存
        end
    end

    // 读操作：根据 r_mask 来选择读取部分
    always @(posedge clk) begin
        if (ce && memRr) begin
            case (r_mask)
                4'b0001: rdData <= {24'd0, temp_mem_data[7:0]};   // 读取低 8 位
                4'b0011: rdData <= {16'd0, temp_mem_data[15:0]};  // 读取低 16 位
                default: rdData <= temp_mem_data;                  // 默认读取完整 32 位
            endcase
        end
    end

endmodule
