`include "Helpers.v"  // 包含 constants.v 文件
module IDU (
        input wire rst,                 // 复位信号
        input wire [31:0] pc,
        input wire [31:0] inst,         // 输入指令
        input wire [31:0] regaData_i,   // 寄存器 A 数据
        input wire [31:0] regbData_i,   // 寄存器 B 数据, 这个输出还要负责处理立即数的传递

        output reg [31:0] regaData,     // 操作数 a
        output reg [31:0] regbData,     // 操作数 b, 为了利用 case 语法特性，这里使用 reg

        // 跳转使能由 IDU 生成，跳转地址由 EXU 生成
        output reg jCe,                 // 跳转使能
        output reg [31:0] jAddr,            // 跳转地址

        // 连接 RegFile
        output wire  regaRd,            // 读使能
        output wire [4:0] regaAddr,     // 读地址 a
        output wire  regbRd,            // 读使能
        output wire [4:0] regbAddr,     // 读地址 b

        // 信号传递给 EXU
        output reg [5:0] op,            // ALU 功能
        output reg [0:0] memWr,         // 内存写使能
        output reg [0:0] memRr,         // 内存读使能
        output reg [3:0] w_mask,        // w_mask
        output reg [3:0] r_mask,        // r_mask
        output reg [0:0] regcWr,        // 寄存器写使能
        output reg [4:0] regcAddr,      // WB 数据地址
        output reg [31:0] rt_data_o     // load 指令写入的地址，for WBU

    );
    // 提取指令字段
    assign jCe = 1'b0; // 默认不跳转

    // 延迟槽
    wire [31:0] pc_plus_4;
    assign pc_plus_4 = pc + 32'd4;

    // wire [5:0] funct = inst[5:0];
    // wire [5:0] opcode = inst[31:26];
    wire [4:0] rs_addr = inst[25:21];
    wire [4:0] rt_addr = inst[20:16];
    wire [4:0] rd_addr = inst[15:11];
    wire [4:0] sa     = inst[10:6]; // sll,srl,sra
    wire [25:0] address = inst[25:0]; // J,JAL

    // 提取立即数
    wire [15:0] imm = inst[15:0]; // 也是 offset
    wire [15:0] offset = inst[15:0];
    // 对立即数进行扩展
    wire [31:0] s_imm = `signExtend(imm,16); // 有符号立即数
    wire [31:0] u_imm = `zeroExtend(imm,16); // 无符号立即数
    wire [31:0] s_offset = `signExtend(offset,16); // 有符号立即数
    // wire [31:0] u_offset = `zeroExtend(offset,16); // 无符号立即数
    wire [31:0] u_sa = `zeroExtend(sa,5); // 无符号立即数
    wire [31:0] u_address = `zeroExtend(address,26); // 无符号立即数


    // 默认 指令存储器使能为 1
    assign regaRd = 1'b1;
    assign regbRd = 1'b1;
    // RegFile 地址
    assign regaAddr = is_break ? 5'd4: rs_addr; // 如果是 break，那么需要读取 4 号寄存器
    assign regbAddr = rt_addr;
    // LOAD 地址
    assign rt_data_o = regbData_i; // rt 中的数据需要传到 mem，对于 Store


    // 解析信号
    reg is_add, is_sub, is_and, is_or, is_xor,
        is_sll, is_srl, is_sra, is_jr,
        is_addi, is_andi, is_ori, is_xori,
        is_lw, is_sw, is_beq, is_bne,
        is_lui, is_j, is_jal;

    reg is_break, is_unknown;

    reg is_bgezal, is_addiu, is_addu, is_sltiu, is_subu, is_blez, is_slti;

    reg is_slt, is_bgtz, is_bltz, is_jalr, is_mult, is_multu, is_div, is_divu, is_mfhi, is_mflo, is_mthi, is_mtlo;

    reg is_ll, is_sc, is_mfc0, is_mtc0, is_eret, is_syscall;

    reg is_lb, is_sb;

    // 首先得识别是什么指令（参考给出了 38 条指令），然后根据指令解析出所需信号

    always @(*) begin
        // 20 条 I 型指令
        is_add = 1'b0;
        is_sub = 1'b0;
        is_and = 1'b0;
        is_or = 1'b0;
        is_xor = 1'b0;
        is_sll = 1'b0;
        is_srl = 1'b0;
        is_sra = 1'b0;
        is_jr = 1'b0;
        is_addi = 1'b0;
        is_andi = 1'b0;
        is_ori = 1'b0;
        is_xori = 1'b0;
        is_lw = 1'b0;
        is_sw = 1'b0;
        is_beq = 1'b0;
        is_bne = 1'b0;
        is_lui = 1'b0;
        is_j = 1'b0;
        is_jal = 1'b0;

        is_syscall = 1'b0;
        is_break = 1'b0;
        is_unknown = 1'b0;

        is_bgezal = 1'b0;
        is_addiu = 1'b0;
        is_addu = 1'b0;
        is_sltiu = 1'b0;
        is_subu = 1'b0;
        is_blez = 1'b0;
        is_slt = 1'b0;
        is_slti = 1'b0;

        is_bgtz = 1'b0;
        is_bltz = 1'b0;
        is_jalr = 1'b0;
        is_mult = 1'b0;
        is_multu = 1'b0;
        is_div = 1'b0;
        is_divu = 1'b0;
        is_mfhi = 1'b0;
        is_mflo = 1'b0;
        is_mthi = 1'b0;
        is_mtlo = 1'b0;

        is_ll = 1'b0;
        is_sc = 1'b0;
        is_mfc0 = 1'b0;
        is_mtc0 = 1'b0;
        is_eret = 1'b0;

        is_lb = 1'b0;
        is_sb = 1'b0;




        casez (inst[31:0])
            32'b000000_?????_?????_?????_00000_100000: begin
                regcAddr = rd_addr;
                is_add = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100001: begin
                regcAddr = rd_addr;
                is_addu = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100010: begin
                regcAddr = rd_addr;
                is_sub = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100011: begin
                regcAddr = rd_addr;
                is_subu = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100100: begin
                regcAddr = rd_addr;
                is_and = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100101: begin
                regcAddr = rd_addr;
                is_or = 1'b1;
            end
            32'b000000_?????_?????_?????_00000_100110: begin
                regcAddr = rd_addr;
                is_xor = 1'b1;
            end
            32'b000000_00000_?????_?????_?????_000000: begin
                regcAddr = rd_addr;
                is_sll = 1'b1;
            end
            32'b000000_00000_?????_?????_?????_000010: begin
                regcAddr = rd_addr;
                is_srl = 1'b1;
            end
            32'b000000_00000_?????_?????_?????_000011: begin
                regcAddr = rd_addr;
                is_sra = 1'b1;
            end
            // I-type instructions
            32'b001000_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_addi = 1'b1; // addi
            end

            32'b001001_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_addiu = 1'b1; // addiu
            end

            32'b001100_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_andi = 1'b1; // andi
            end
            32'b001101_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_ori  = 1'b1; // ori
            end
            32'b001110_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_xori = 1'b1; // xori
            end
            32'b100011_?????_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_lw   = 1'b1; // lw

            end
            32'b101011_?????_?????_?????_?????_??????:
                is_sw   = 1'b1; // sw
            32'b000100_?????_?????_?????_?????_??????:
                is_beq  = 1'b1; // beq
            32'b000101_?????_?????_?????_?????_??????:
                is_bne  = 1'b1; // bne
            32'b000001_?????_10001_?????_?????_??????:begin
                regcAddr = 5'd31; // jal 需要回写到 31 号寄存器
                is_bgezal = 1'b1; // bgezal
            end

            32'b001111_00000_?????_?????_?????_??????: begin
                regcAddr = rt_addr;
                is_lui  = 1'b1; // lui
            end

            // J-type instructions
            32'b000010_?????_?????_?????_?????_??????:
                is_j   = 1'b1; // j
            32'b000011_?????_?????_?????_?????_??????: begin
                regcAddr = 5'd31; // jal 需要回写到 31 号寄存器
                is_jal = 1'b1; // jal
            end
            32'b000000_?????_00000_?????_00000_001001: begin
                regcAddr = rd_addr;
                is_jalr = 1'b1; // jalr
            end

            32'b000000_?????_00000_00000_00000_001000:
                is_jr = 1'b1;
            32'b000000_?????_?????_?????_?????_001100:
                is_syscall = 1'b1;
            32'b000000_?????_?????_?????_?????_001101:
                is_break = 1'b1;

            32'b000000_?????_?????_?????_00000_101010:begin
                regcAddr = rd_addr;
                is_slt = 1'b1;
            end
            32'b001011_?????_?????_?????_?????_??????:begin
                regcAddr = rt_addr;
                is_sltiu = 1'b1;
            end
            32'b001010_?????_?????_?????_?????_??????:begin
                regcAddr = rt_addr;
                is_slti = 1'b1;
            end
            32'b000110_?????_00000_?????_?????_??????:
                is_blez = 1'b1;
            32'b000111_?????_00000_?????_?????_??????:
                is_bgtz = 1'b1;
            32'b000001_?????_00000_?????_?????_??????:
                is_bltz = 1'b1;

            // 乘除指令：需要实现 HiLo 寄存器
            32'b000000_?????_?????_00000_00000_011000:
                is_mult = 1'b1;
            32'b000000_?????_?????_00000_00000_011001:
                is_multu = 1'b1;
            32'b000000_?????_?????_00000_00000_011010:
                is_div = 1'b1;
            32'b000000_?????_?????_00000_00000_011011:
                is_divu = 1'b1;

            // 移动数据指令
            32'b000000_00000_00000_?????_00000_010000:begin
                regcAddr = rd_addr;
                is_mfhi = 1'b1;
            end
            32'b000000_00000_00000_?????_00000_010010:begin
                regcAddr = rd_addr;
                is_mflo = 1'b1;
            end
            32'b000000_?????_00000_00000_00000_010001:
                is_mthi = 1'b1;
            32'b000000_?????_00000_00000_00000_010011:
                is_mtlo = 1'b1;

            32'b110000_?????_?????_?????_?????_??????:
                is_ll = 1'b1;
            32'b111000_?????_?????_?????_?????_??????:
                is_sc = 1'b1;
            32'b010000_00000_?????_?????_?????_??????:
                is_mfc0 = 1'b1;
            32'b010000_?????_00000_?????_?????_??????:
                is_mtc0 = 1'b1;
            32'b010000_00000_00000_00000_00000_011000:
                is_eret = 1'b1;

            32'b100000_?????_?????_?????_?????_??????:
                is_lb = 1'b1;

            32'b101000_?????_?????_?????_?????_??????:
                is_sb = 1'b1;



            default: begin
                is_unknown = 1'b1; // 未实现的指令

            end
        endcase
    end

    // 根据指令的类型进行解析
    // 需要产生的信号
    // 一共 38 条指令，因此这里需要 6 位来 标记功能

    reg [2:
         0] OP1_SEL;  // 第一操作数来源
    reg [2:
         0] OP2_SEL;  // 第二操作数来源

    always @(*) begin
        if (rst) begin
            op = ALU_X;
            OP1_SEL = OP1_X;
            OP2_SEL = OP2_X;
            memWr = WMEN_X;
            memRr = RMEN_X;
            regcWr = REN_S;
            w_mask = WMASK_X;
            r_mask = RMASK_X;
            regcAddr = 5'd0;
        end
        else begin
            case (1'b1)
                is_add: begin
                    op = ALU_ADD;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                    regcAddr = rd_addr;

                end
                is_addu: begin
                    op = ALU_ADD;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                    regcAddr = rd_addr;

                end
                is_sub: begin
                    op = ALU_SUB;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_subu: begin
                    op = ALU_SUB;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_and: begin
                    op = ALU_AND;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_or: begin
                    op = ALU_OR;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_xor: begin
                    op = ALU_XOR;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_sll: begin
                    op = ALU_SLL;
                    OP1_SEL = OP1_IM_SA;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_srl: begin
                    op = ALU_SRL;
                    OP1_SEL = OP1_IM_SA;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_sra: begin
                    op = ALU_SRA;
                    OP1_SEL = OP1_IM_SA;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end

                is_addi: begin
                    op = ALU_ADD;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMS; // 符号扩展
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_addiu: begin
                    op = ALU_ADD;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMS;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_andi: begin
                    op = ALU_AND;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMZ; // 零扩展
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_ori: begin
                    op = ALU_OR;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMZ;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_xori: begin
                    op = ALU_XOR;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMZ;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_lw: begin
                    op = ALU_LW;
                    OP1_SEL = OP1_RS; // 同 base
                    OP2_SEL = OP2_IM_OFFSET_S; // 立即数 offset 符号扩展
                    memWr = WMEN_X;
                    memRr = RMEN_S; // 读内存
                    regcWr = REN_S; // 读完了要回写
                    w_mask = WMASK_X;
                    r_mask = RMASK_C; // 读取 4 字节
                end
                is_sw: begin
                    op = ALU_SW;
                    OP1_SEL = OP1_RS; // 同 base
                    OP2_SEL = OP2_IM_OFFSET_S;  // 立即数 offset 符号扩展
                    memWr = WMEN_S; // 写内存
                    memRr = RMEN_X;
                    regcWr = REN_X;  // 写内存不需要回写
                    w_mask = WMASK_C; // 存入 4 字节
                    r_mask = RMASK_X;
                end
                // 这里比较复杂
                is_beq: begin
                    op = ALU_BEQ;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;


                end
                is_bne: begin
                    op = ALU_BNE;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_bgezal: begin
                    op = ALU_BGEZAL;
                    OP1_SEL = OP1_PC;
                    OP2_SEL = OP2_IM_4;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_blez: begin
                    op = ALU_BLEZ;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_bgtz: begin
                    op = ALU_BGTZ;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_bltz: begin
                    op = ALU_BLTZ;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_lui: begin
                    op = ALU_LUI;
                    OP1_SEL = OP1_LUI;
                    OP2_SEL = OP2_X; // imm 送入高 16 位
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;

                end
                is_j: begin
                    op = ALU_J;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_jal: begin
                    op = ALU_JAL;
                    OP1_SEL = OP1_PC;
                    OP2_SEL = OP2_IM_4; // 手册错误，应该是延迟槽，而不是延迟槽后的 PC
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;     // jal 需要回写寄存器

                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_jalr: begin
                    op = ALU_JALR;
                    OP1_SEL = OP1_PC;
                    OP2_SEL = OP2_IM_4; // 手册错误，应该是延迟槽，而不是延迟槽后的 PC
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S; // jalr 需要回写寄存器

                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_jr: begin
                    op = ALU_JR;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
                is_syscall: begin
                    op = ALU_SYSCALL;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_break: begin
                    op = ALU_BREAK;
                    OP1_SEL = OP1_RS; // 技巧，将 RS 作为 break 的信号
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_sltiu: begin
                    op = ALU_SLTIU;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_IMS; // 有符号扩展
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_slt: begin
                    op = ALU_SLT;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_mult: begin
                    op = ALU_MULT;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_multu: begin
                    op = ALU_MULTU;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
                is_div: begin
                    op = ALU_DIV;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_divu: begin
                    op = ALU_DIVU;
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_RT;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_mfhi: begin
                    op = ALU_MFHI;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S; // 写入 rd
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
                is_mflo: begin
                    op = ALU_MFLO;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_S; // 写入 rd
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
                is_mthi: begin
                    op = ALU_MTHI;
                    OP1_SEL = OP1_RS; // RS 中的数据写到 Lo
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X; // 这种写不算写
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                is_mtlo: begin
                    op = ALU_MTLO; // RS 中的数据写到 Lo
                    OP1_SEL = OP1_RS;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X; // 这种写不算写
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
                is_unknown: begin
                    op = ALU_UNKNOWN;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end

                default: begin
                    op = ALU_X;
                    OP1_SEL = OP1_X;
                    OP2_SEL = OP2_X;
                    memWr = WMEN_X;
                    memRr = RMEN_X;
                    regcWr = REN_X;
                    w_mask = WMASK_X;
                    r_mask = RMASK_X;
                end
            endcase
        end
    end

    // 根据解析到的信号，生成第一操作数，第二操作数

    always @(*) begin
        case (OP1_SEL)
            OP1_RS:
                regaData = regaData_i;
            OP1_IM_SA:
                regaData = u_sa; // sll, srl, sra
            OP1_IMS:
                regaData = s_imm; // BEQ,BNE, 相当于符号扩展的 offset
            OP1_LUI:
                regaData = u_imm << 16; // 高 16 位放入 rt
            OP1_PC:
                regaData = pc;
            default:
                regaData = 0;
        endcase
    end

    always @(*) begin
        case (OP2_SEL)
            OP2_RT:
                regbData = regbData_i;
            OP2_IMS:
                regbData = s_imm; // 符号扩展
            OP2_IMZ:
                regbData = u_imm; // 0 扩展
            OP2_ADDRESS:
                regbData = u_address; // 0 扩展
            OP2_IM_4:
                regbData = 32'd4; // JAL, BGEZAL
            OP2_IM_OFFSET_S:
                regbData = s_offset; // LW,SW
            OP2_PC:
                regbData = pc;

            default:
                regbData = 0;
        endcase
    end

    // 跳转信号
    always @(*) begin
        case (op)
            ALU_BEQ:
                jCe = (regaData_i == regbData_i);
            ALU_BNE:
                jCe = (regaData_i != regbData_i);
            ALU_BGEZAL:
                jCe = (regaData_i[31] == 1'b0); // 符号位如果为 0，就是非负，那么一定大于等于 0
            ALU_BLEZ:
                jCe = (regaData_i[31] == 1'b1 || regaData_i == 32'd0); // 小于等于 0 跳转
            ALU_BGTZ:
                jCe = (regaData_i[31] == 1'b0 || regaData_i != 32'd0); // 大于 0 跳转
            ALU_BLTZ:
                jCe = (regaData_i[31] == 1'b1); // 小于 0 跳转
            ALU_J:
                jCe = 1'b1;
            ALU_JAL:
                jCe = 1'b1;
            ALU_JALR:
                jCe = 1'b1;
            ALU_JR:
                jCe = 1'b1;
            default:
                jCe = 1'b0;
        endcase
    end

    // 考虑到性能以及设计需求，现在需要将跳转地址的生成放在 IDU 中
    always @(*) begin
        if (rst) begin
            jAddr = 32'b0;
        end
        else begin
            case ( op)
                ALU_J:
                    jAddr = {pc_plus_4[31:28],address[25:0],2'b00};
                ALU_JR:
                    jAddr = regaData_i; // rs 中的数据
                ALU_JAL:
                    jAddr = {pc_plus_4[31:28],address[25:0],2'b00};
                ALU_JALR:
                    jAddr = regaData_i; // rs 中的数据
                ALU_BEQ:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                ALU_BNE:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                ALU_BGEZAL:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                ALU_BLEZ:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                ALU_BGTZ:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                ALU_BLTZ:
                    jAddr = pc_plus_4 + `signExtend({offset,2'b00} ,18); // 左移两位，再符号扩展 + 延迟槽
                default:
                    jAddr = 32'b0;
            endcase
        end
    end



    // 将解析到的信号发射到 EXU 中处理，EXU 中如果需要，再添加到额外的信号到 IO 接口



endmodule
