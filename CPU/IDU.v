// 译码器
// 符号扩展宏：signExtend(num, n)
`define signExtend(num, n)  {{(32 - n){num[n-1]}}, num}

// 零扩展宏：zeroExtend(num, n)
`define zeroExtend(num, n)  {{(32 - n){1'b0}}, num}

module IDU (
        input wire rst,               // 复位信号

        input wire [31:0] pc,
        input wire [31:0] inst,             // 输入指令
        input wire [31:0] regaData_i,       // 寄存器 A 数据
        input wire [31:0] regbData_i,       // 寄存器 B 数据, 这个输出还要负责处理立即数的传递

        output reg jCe,                    // 跳转使能
        output reg [31:0] jAddr,            // 跳转地址，为了利用 case 语法特性，这里使用 reg

        output reg [4:0] op,               // 计算类型，不是简单的 opcode ,为了利用 case 语法特性，这里使用 reg
        output reg [31:0] regaData,        // 源寄存器 A 数据
        output reg [31:0] regbData,        // 源寄存器 B 数据,为了利用 case 语法特性，这里使用 reg
        output reg  regcWr_i,              // 写使能信号
        output reg [4:0] regcAddr_i,       // 目标寄存器地址

        // 连接 RegFile
        output wire  regaRd,                // 读使能
        output wire [4:0] regaAddr,         // 读地址 a
        output wire  regbRd,                // 读使能
        output wire [4:0] regbAddr          // 读地址 b
    );
    // 提取指令字段

    // 默认 指令存储器 使能为 1
    assign regaRd = 1'b1;
    assign regbRd = 1'b1;

    wire [5:0] funct = inst[5:0];
    wire [5:0] opcode = inst[31:26];
    wire [4:0] rs = inst[25:21];
    wire [4:0] rt = inst[20:16];
    wire [4:0] rd = inst[15:11];
    wire [15:0] imm = inst[15:0]; // 也是 offset
    wire [25:0] target = inst[25:0];


    // 跳转信号
    // 跳转信号
    always @(*) begin
        case (opcode)
            6'b000010: // j
                jCe = 1'b1;
            6'b000011: // jal
                jCe = 1'b1;
            6'b000100: // beq
                jCe = (regaData_i == regbData_i); // rs 和 rt 寄存器中的值相等时跳转
            6'b000101: // bne
                jCe = (regaData_i != regbData_i); // rs 和 rt 寄存器中的值不相等时跳转
            default:
                jCe = 1'b0;
        endcase
    end


    // 跳转地址
    always @(*) begin
        case (opcode)
            6'b000010: // j
                jAddr = {pc[31:28], target, 2'b00};
            6'b000011: // jal
                jAddr = {pc[31:28], target, 2'b00};
            6'b000100: // beq
                jAddr = `signExtend({imm << 2}, 16) + pc;
            6'b0000101: // bne
                jAddr = `signExtend({imm << 2}, 16) + pc;
            default:
                jAddr = 32'b0;
        endcase
    end


    // 第一操作数
    always @(*) begin
        case (opcode)
            6'b000011: // jal
                regaData = pc;
            6'b000010: // j
                regaData = 32'd0;
            6'b000100: // beq
                regaData = 32'd0;
            6'b000101: // bne
                regaData = 32'd0;
            default:
                regaData = regaData_i;
        endcase
    end

    // 第二操作数
    always @(*) begin
        case (opcode)
            6'b001000: // addi
                regbData = `signExtend(imm, 16);
            6'b001100: // andi
                regbData = `signExtend(imm, 16);
            6'b001101: // ori
                regbData = `signExtend(imm, 16);
            6'b001110: // xori
                regbData = `signExtend(imm, 16);
            6'b000011: // jal
                regbData = 32'd4;
            6'b000010: // j
                regbData = 32'd0;
            6'b000100: // beq
                regbData = 32'd0;
            6'b000101: // bne
                regbData = 32'd0;
            default:
                regbData = regbData_i;
        endcase
    end
    // 寄存器写使能信号
    // 多路选择器
    always @(*) begin
        case (opcode)
            6'b000000: // R 型指令
                regcWr_i = 1'b1;
            6'b001000: // addi
                regcWr_i = 1'b1;
            6'b001100: // andi
                regcWr_i = 1'b1;
            6'b001101: // ori
                regcWr_i = 1'b1;
            6'b001110: //xori
                regcWr_i = 1'b1;
            6'b000011: // jal
                regcWr_i = 1'b1;
            default:
                regcWr_i = 1'b0;
        endcase
    end
    // 寄存器写地址
    always @(*) begin
        case (opcode)
            6'b000000: // R 型指令
                regcAddr_i = rd;
            6'b000011: // jal
                regcAddr_i = 5'd31;
            default:
                regcAddr_i = rt;
        endcase
    end

    // ALU
    // 定义 op
    // 5'd0: 加法
    // 5'd1: 减法
    // 5'd2: 与
    // 5'd3: 或
    // 5'd4: 异或
    // 5'd5: 逻辑左移
    // 5'd6: 逻辑右移
    // 5'd7: 算数右移

    // ALU：对于每一类或者一个命令，导向到 ALU 中的具体的操作
    always @(*) begin
        case (opcode)
            6'b000000: // R 型指令
            begin
                case (funct[5:0])
                    6'b100000: // add
                        op = 5'd0;
                    6'b100010: //sub
                        op = 5'd1;
                    6'b100100: // and
                        op = 5'd2;
                    6'b100101: // or
                        op = 5'd3;
                    6'b100110: // xor
                        op = 5'd4;
                    6'b000000: // sll
                        op = 5'd5;
                    6'b000010: // srl
                        op = 5'd6;
                    6'b000011: // sra
                        op = 5'd7;
                    default:
                        op = 5'd0;
                endcase
            end

            6'b001000: // addi
                op = 5'd0;
            6'b001100: // andi
                op = 5'd2;
            6'b001101: // ori
                op = 5'd3;
            6'b001110: // xori
                op = 5'd4;
            6'b000011: // jal，使用加法
                op = 5'd0;
            default:
                op = 5'd0;
        endcase
    end


    // RegFile 地址
    assign regaAddr = rs;
    assign regbAddr = rt;

endmodule
