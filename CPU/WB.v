// 这是回写模块，增加一个并行的部件意味着可以增加一级流水
// 访存单元
module WB (
        input wire [0:0] REG_EN_i,      // 寄存器写使能 (输入信号)
        input wire [1:0] WB_SEL_i,      // WB 数据来源 (输入信号)
        input wire [0:0] WB_TYPE_i,      // 寄存器回写数据类型 (输入信号)

    );

endmodule

