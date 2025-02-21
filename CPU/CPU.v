// 顶层模块
module CPU (
        input wire clk,
        input wire rst
    );
    // 信号连线
    // IFU
    wire [31:0] ifu_pc;
    wire ifu_romCe;

    // IDU
    wire idu_jCe;
    wire [31:0] idu_jAddr;
    wire [4:0] idu_op;
    wire [31:0] idu_regaData;
    wire [31:0] idu_regbData;
    wire  idu_regcWr_i;
    wire [4:0] idu_regcAddr_i;

    wire  idu_regaRd;
    wire [4:0] idu_regaAddr;

    wire  idu_regbRd;
    wire [4:0] idu_regbAddr;

    // EXU
    wire  [31:0] exu_regcData;
    wire [4:0] exu_regcAddr;
    wire exu_regcWr;

    // InstMem
    wire [31:0] instMem_data;

    // RegFile
    wire [31:0] regs_regaData;
    wire [31:0] regs_regbData;

    IFU ifu(
            .clk(clk),
            .rst(rst),
            .jAddr(idu_jAddr),
            .jCe(idu_jCe),
            .pc(ifu_pc),
            .romCe(ifu_romCe)
        );

    InstMem instMem(
                .ce(ifu_romCe),
                .addr(ifu_pc),
                .data(instMem_data)
            );
    RegFile regs(
                .clk(clk),
                .rst(rst),
                .regaData(regs_regaData),
                .regbData(regs_regbData),
                .regaAddr(idu_regaAddr),
                .regaRd(idu_regaRd),
                .regbAddr(idu_regbAddr),
                .regbRd(idu_regbRd),
                .we(exu_regcWr),
                .wAddr(exu_regcAddr),
                .wData(exu_regcData)
            );

    IDU idu(
            .rst(rst),
            .pc(ifu_pc),
            .inst(instMem_data),
            .regaData_i(regs_regaData),
            .regbData_i(regs_regbData),

            .jCe(idu_jCe),
            .jAddr(idu_jAddr),
            .op(idu_op),
            .regaData(idu_regaData),
            .regbData(idu_regbData),
            .regcWr_i(idu_regcWr_i),
            .regcAddr_i(idu_regcAddr_i),
            .regaRd(idu_regaRd),
            .regaAddr(idu_regaAddr),
            .regbRd(idu_regbRd),
            .regbAddr(idu_regbAddr)
        );

    EXU exu(
            .op(idu_op),
            .regaData(idu_regaData),
            .regbData(idu_regbData),
            .regcWr_i(idu_regcWr_i),
            .regcAddr_i(idu_regcAddr_i),
            .regcData(exu_regcData),
            .regcAddr(exu_regcAddr),
            .regcWr(exu_regcWr)
        );

endmodule
