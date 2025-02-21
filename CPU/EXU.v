// 运算单元
module EXU (
        input wire [4:0] op,                // 操作码
        input wire [31:0] regaData,         // 源寄存器 A 数据
        input wire [31:0] regbData,         // 源寄存器 B 数据
        input wire  regcWr_i,               // 写使能
        input wire [4:0] regcAddr_i,        // 寄存器写地址

        output reg [31:0] regcData,         // 写数据
        output reg [4:0] regcAddr,         // 运算结果
        output reg regcWr                   // 写使能
    );

    assign regcWr = regcWr_i;
    assign regcAddr = regcAddr_i;


    // ALU
    // 定义: op
    // 5'd0: 加法
    // 5'd1: 减法
    // 5'd2: 与
    // 5'd3: 或
    // 5'd4: 异或
    // 5'd5: 逻辑左移
    // 5'd6: 逻辑右移
    // 5'd7: 算数右移

    always @(*) begin
        case (op)
            5'd0: // 加法
                regcData = regaData + regbData;
            5'd1: // 减法
                regcData = regaData - regbData;
            5'd2: // 与
                regcData = regaData & regbData;
            5'd3: // 或
                regcData = regaData | regbData;
            5'd4: // 异或
                regcData = regaData ^ regbData;
            5'd5: // 逻辑左移
                regcData = regaData << regbData;
            5'd6: // 逻辑右移
                regcData = regaData >> regbData;
            5'd7: // 算术右移
                regcData = regaData >>> regbData;

            default:
                regcData = 32'b0;
        endcase
    end

endmodule
