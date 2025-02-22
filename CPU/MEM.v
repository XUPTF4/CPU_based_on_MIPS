// 访存单元
// 这里将参考资料中的 MEM 拆开，多了一个 WBU 单元
module MEM (
        input wire op,
        input wire [31:0] addr,       // 取指地址
        output wire [31:0] data,       // 输出指令数据

        // 来自上游的信号
        input wire [5:0] ALU_FUNC_i,    // ALU 功能 (输入信号)
        input wire [0:0] W_MEM_EN_i,      // 内存写使能 (输入信号)
        input wire [1:0] R_MEM_ENP_i,      // 内存读使能 (输入信号)
        input wire [1:0] W_MASK_i,      // w_mask (输入信号)
        input wire [1:0] R_MASK_i,      // r_mask (输入信号)
        input wire [0:0] W_TYPE_i,      // 写入数据类型 (输入信号)
        input wire [0:0] REG_EN_i,      // 寄存器写使能 (输入信号)
        input wire [1:0] WB_SEL_i,      // WB 数据来源 (输入信号)
        input wire [0:0] WB_TYPE_i,      // 寄存器回写数据类型 (输入信号)

        // 输出到 DataMem

        output reg [0:0] W_MEM_EN,      // 内存写使能 (输出信号)
        output reg [0:0] R_MEM_EN,      // 内存读使能 (输出信号)
        output reg [1:0] W_MASK,      // w_mask (输出信号)
        output reg [1:0] R_MASK,      // r_mask (输出信号)
        output reg [0:0] W_TYPE,      // 写入数据类型 (输出信号)
    );








endmodule

