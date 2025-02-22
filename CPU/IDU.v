

`include "Helpers.v"  // 包含 constants.v 文件

module IDU (

        input wire rst,               // 复位信号
        input wire [31:0] pc,
        input wire [31:0] inst,             // 输入指令
        input wire [31:0] regaData_i,       // 寄存器 A 数据
        input wire [31:0] regbData_i,       // 寄存器 B 数据, 这个输出还要负责处理立即数的传递

        output reg [31:0] regaData,        // 操作数 a
        output reg [31:0] regbData,        // 操作数 b, 为了利用 case 语法特性，这里使用 reg
        
        // 跳转使能由 IDU 生成，跳转地址由 EXU 生成
        output reg jCe,                             // 跳转使能

        // 连接 RegFile
        output wire  regaRd,                // 读使能
        output wire [4:0] regaAddr,         // 读地址 a
        output wire  regbRd,                // 读使能
        output wire [4:0] regbAddr,          // 读地址 b

        // 信号传递给 EXU
        output reg [5:0] EXE_FUNC,   // ALU 功能
        output reg [0:0] W_MEM_EN,     // 内存写使能
        output reg [0:0] R_MEM_EN,     // 内存读使能
        output reg [1:0] W_MASK,     // w_mask
        output reg [1:0] R_MASK,     // r_mask
        output reg [0:0] W_TYPE,     // 写入数据类型
        output reg [0:0] REG_EN,     // 寄存器写使能
        output reg [1:0] WB_SEL,     // WB 数据来源
        output reg [4:0] Reg_Target     // WB 数据地址
        // output reg  regcWr_i,              // 写使能信号
        // output reg [4:0] regcAddr_i,       // 目标寄存器地址

    );
    // 提取指令字段
    assign jCe = 1'b0; // 默认不跳转


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
    assign regaAddr = rs_addr;
    assign regbAddr = rt_addr;


    // 解析信号
    reg is_add, is_sub, is_and, is_or, is_xor,
        is_sll, is_srl, is_sra, is_jr,
        is_addi, is_andi, is_ori, is_xori,
        is_lw, is_sw, is_beq, is_bne,
        is_lui, is_j, is_jal;


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

        casez (inst[31:0])
            // R-type instructions (funct = 000000)
            32'b000000_?????_?????_?????_00000_??????: begin
                Reg_Target = rd_addr;
                if (inst[5:0] == FUNCT_ADD) begin
                    is_add = 1'b1;
                end
                else if (inst[5:0] == FUNCT_SUB) begin
                    is_sub = 1'b1;
                end
                else if (inst[5:0] == FUNCT_AND) begin
                    is_and = 1'b1;
                end
                else if (inst[5:0] == FUNCT_OR) begin
                    is_or = 1'b1;
                end
                else if (inst[5:0] == FUNCT_XOR) begin
                    is_xor = 1'b1;
                end
            end
            32'b000000_00000_?????_?????_?????_??????: begin
                Reg_Target = rd_addr;
                if (inst[5:0] == FUNCT_SLL) begin
                    is_sll = 1'b1;
                end
                if (inst[5:0] == FUNCT_SRL) begin
                    is_srl = 1'b1;
                end
                if (inst[5:0] == FUNCT_SRA) begin
                    is_sra = 1'b1;
                end
            end

            // I-type instructions
            32'b??????_?????_?????_?????_?????_??????: begin
                Reg_Target = rt_addr;

                if(inst[31:26] == FUNCT_ADDI) begin
                    is_addi = 1'b1; // addi
                end
                if(inst[31:26] == FUNCT_ANDI) begin
                    is_andi = 1'b1; // andi
                end
                if(inst[31:26] == FUNCT_ORI) begin
                    is_ori  = 1'b1; // ori
                end
                if(inst[31:26] == FUNCT_XORI) begin
                    is_xori = 1'b1; // xori
                end
                if(inst[31:26] == FUNCT_LW) begin
                    is_lw   = 1'b1; // lw
                end

            end



            32'b101011_?????_?????_?????_?????_??????:
                is_sw   = 1'b1; // sw
            32'b000100_?????_?????_?????_?????_??????:
                is_beq  = 1'b1; // beq
            32'b000101_?????_?????_?????_?????_??????:
                is_bne  = 1'b1; // bne
            32'b001111_00000_?????_?????_?????_??????: begin
                Reg_Target = rt_addr;
                is_lui  = 1'b1; // lui
            end


            // J-type instructions
            32'b000010_?????_?????_?????_?????_??????:
                is_j   = 1'b1; // j
            32'b000011_?????_?????_?????_?????_??????: begin
                Reg_Target = 5'd31; // jal 需要回写到 31 号寄存器
                is_jal = 1'b1; // jal
            end

            32'b000000_?????_00000_00000_00001_001000: begin // jr
                if (inst[5:0] == FUNCT_JR) begin
                    is_jr = 1'b1;
                end
            end

            default: begin
            end
        endcase
    end

    // 根据指令的类型进行解析
    // 需要产生的信号
    // 一共 38 条指令，因此这里需要 6 位来 标记功能

    reg [2:0] OP1_SEL;  // 第一操作数来源
    reg [2:0] OP2_SEL;  // 第二操作数来源

    always @(*) begin
        case (1'b1)
            is_add: begin
                EXE_FUNC = ALU_ADD;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
                Reg_Target = rd_addr;

            end
            is_sub: begin
                EXE_FUNC = ALU_SUB;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_and: begin
                EXE_FUNC = ALU_AND;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_or: begin
                EXE_FUNC = ALU_OR;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_xor: begin
                EXE_FUNC = ALU_XOR;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_sll: begin
                EXE_FUNC = ALU_SLL;
                OP1_SEL = OP1_IM_SA;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_srl: begin
                EXE_FUNC = ALU_SRL;
                OP1_SEL = OP1_IM_SA;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_sra: begin
                EXE_FUNC = ALU_SRA;
                OP1_SEL = OP1_IM_SA;
                OP2_SEL = OP2_RT;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end

            is_addi: begin
                EXE_FUNC = ALU_ADD;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_IMS; // 符号扩展
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
            is_andi: begin
                EXE_FUNC = ALU_AND;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_IMZ; // 零扩展
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
            is_ori: begin
                EXE_FUNC = ALU_OR;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_IMZ;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
            is_xori: begin
                EXE_FUNC = ALU_XOR;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_IMZ;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
            is_lw: begin
                EXE_FUNC = ALU_LW;
                OP1_SEL = OP1_RS; // 同 base
                OP2_SEL = OP2_IM_OFFSET_S; // 立即数 offset 符号扩展
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_S; // 读内存
                REG_EN = REN_X;
                WB_SEL = WB_MEM; // 读取内存，写入 rd
                W_MASK = WMASK_X;
                R_MASK = RMASK_C; // 读取 4 字节
                W_TYPE = WTYPE_U; // 数据符号，默认为无符号型
            end
            is_sw: begin
                EXE_FUNC = ALU_SW;
                OP1_SEL = OP1_RS; // 同 base
                OP2_SEL = OP2_IM_OFFSET_S;  // 立即数 offset 符号扩展
                W_MEM_EN = WMEN_S; // 写内存
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X;
                WB_SEL = WB_X;
                W_MASK = WMASK_C; // 存入 4 字节
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X; // 数据符号，默认为无符号型
            end
            // 这里比较复杂
            is_beq: begin
                EXE_FUNC = ALU_BEQ;
                OP1_SEL = OP1_IMS;
                OP2_SEL = OP2_PC;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X; // PC 不是普通寄存器，可以直接在 EXU 中改写
                WB_SEL = WB_X;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_bne: begin
                EXE_FUNC = ALU_BNE;
                OP1_SEL = OP1_IMS; // 等价于符号扩展的 offset
                OP2_SEL = OP2_PC;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X;
                WB_SEL = WB_X;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end
            is_lui: begin
                EXE_FUNC = ALU_LUI;
                OP1_SEL = OP1_LUI;
                OP2_SEL = OP2_X; // imm 送入高 16 位
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
            is_j: begin
                EXE_FUNC = ALU_J;
                OP1_SEL = OP1_PC;
                OP2_SEL = OP2_ADDRESS;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X;
                WB_SEL = WB_X;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end

            // 并保存 PC
            is_jal: begin
                EXE_FUNC = ALU_JAL; // 这里可以将其当成加法
                OP1_SEL = OP1_PC;
                OP2_SEL = OP2_IM_4;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_S; // jal 需要回写寄存器，可以将其放在 alu_out,
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end

            is_jr: begin
                EXE_FUNC = ALU_JR;
                OP1_SEL = OP1_RS;
                OP2_SEL = OP2_X;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X;
                WB_SEL = WB_ALU;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;

            end

            default: begin
                EXE_FUNC = ALU_X;
                OP1_SEL = OP1_X;
                OP2_SEL = OP2_X;
                W_MEM_EN = WMEN_X;
                R_MEM_EN = RMEN_X;
                REG_EN = REN_X;
                WB_SEL = WB_X;
                W_MASK = WMASK_X;
                R_MASK = RMASK_X;
                W_TYPE = WTYPE_X;
            end
        endcase
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
                regbData = 32'd4; // JAL
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
        case (EXE_FUNC)
            ALU_BEQ:
                jCe = (regaData == regbData);
            ALU_BNE:
                jCe = (regaData != regbData);
            ALU_J:
                jCe = 1'b1;
            ALU_JAL:
                jCe = 1'b1;
            ALU_JR:
                jCe = 1'b1;
            default:
                jCe = 1'b0;
        endcase
    end



    // 将解析到的信号发射到 EXU 中处理，EXU 中如果需要，再添加到额外的信号到 IO 接口



endmodule
