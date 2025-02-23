// 访存单元
// 这里将参考资料中的 MEM 拆开，多了一个 WBU 单元
// 这里进行访存
module MEM (

        // WBU
        input wire [31:0] regcData_i,
        input wire [4:0] regcAddr_i,
        input wire regcWr_i, // 寄存器写使能信号
        output wire [31:0] regData,
        output wire [4:0] regAddr,
        output wire regWr,

        // MEM
        input wire [31:0] memAddr_i,
        input wire [31:0] memData_i,
        input wire [31:0] rdData_i,
        input wire [0:0] W_MEM_EN_i,      // 内存写使能 (输入信号)
        input wire [0:0] R_MEM_EN_i,      // 内存读使能 (输入信号)
        input wire [3:0] W_MASK_i,      // w_mask (输入信号)
        input wire [3:0] R_MASK_i,      // r_mask (输入信号)

        output wire [31:0] memAddr,
        output wire [31:0] wtData,
        output wire memWr, //  内存使能信号输出，表示是否启用内存操作。
        output wire memCe, //  内存使能信号输出，表示是否启用内存操作。// 直接生成
        output reg [0:0] W_MEM_EN,      // 内存写使能 (输出信号)
        output reg [0:0] R_MEM_EN,      // 内存读使能 (输出信号)
        output reg [3:0] W_MASK,      // w_mask (输出信号)
        output reg [3:0] R_MASK,      // r_mask (输出信号)

        // 来自上游的信号


        // input wire [0:0] W_TYPE_i,      // 写入数据类型 (输入信号)
        // input wire [0:0] REG_EN_i,      // 寄存器写使能 (输入信号)
        input wire [1:0] WB_SEL_i,      // WB 数据来源 (输入信号)
        // input wire [0:0] WB_TYPE_i,      // 寄存器回写数据类型 (输入信号)

        // 输出到 DataMem

        output wire [1:0] WB_SEL,      // WB 数据来源 (输入信号)
    );

    // WBU
    assign regData = regcData_i;
    assign regAddr = regcAddr_i;

    assign regWr = regcWr_i;
    assign WB_SEL = WB_SEL_i;

    assign W_MEM_EN = W_MEM_EN_i;
    assign R_MEM_EN = R_MEM_EN_i;
    assign W_MASK = W_MASK_i;
    assign R_MASK = R_MASK_i;
    assign W_TYPE = W_TYPE_i;



    // 内存信号
    assign memAddr = alu_out; // 如果是 load：OK；如果是 store：
    assign memData = rt_data_o; // 那也 OK
    assign readWr = R_MEM_EN_i;
    assign writeWr = W_MEM_EN_i;
    assign rmask = R_MASK_i;
    assign wmask = W_MASK_i;

endmodule

