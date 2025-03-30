// 顶层模块
module CPU (
        input wire clk,
        input wire rst
    );
    // 信号连线

    // CP0
    wire [31:0] CP0_EPC;
    wire [31:0] CP0_handler_PC;
    // IFU
    wire [31:0] ifu_pc;
    wire ifu_romCe;

    // IDU
    wire [31:0] idu_regaData;       // 操作数 a
    wire [31:0] idu_regbData;       // 操作数 b
    wire idu_jCe;                   // 跳转使能
    wire [31:0] idu_jAddr;          // 跳转地址
    wire idu_regaRd;                // 读使能 a
    wire [4:0] idu_regaAddr;        // 读地址 a
    wire idu_regbRd;                // 读使能 b
    wire [4:0] idu_regbAddr;        // 读地址 b
    wire [5:0] idu_op;              // ALU 功能
    wire idu_memWr;                 // 内存写使能
    wire idu_memRr;                 // 内存读使能
    wire [3:0] idu_w_mask;          // w_mask
    wire [3:0] idu_r_mask;          // r_mask
    wire idu_regcWr;                // 寄存器写使能
    wire [4:0] idu_regcAddr;        // WB 数据地址
    wire [31:0] idu_rt_data_o;      // load 指令写入的地址，for WB

    wire [31:0] idu_inst_debug;
    wire [31:0] idu_pc_debug;

    wire IDU_EXLSet;
    wire IDU_EXLClear;
    wire [31:0] IDU_CP0_PC;

    // EXU
    wire [31:0] exu_regcData;       // 寄存器写数据
    wire [4:0] exu_regcAddr;        // 寄存器写地址
    wire exu_regcWr;                // 寄存器写使能


    wire [31:0] exu_memAddr;        // 内存访问地址
    wire [31:0] exu_memData;        // 内存写数据
    wire exu_readWr;                // 内存读使能
    wire exu_writeWr;               // 内存写使能
    wire [3:0] exu_rmask;           // 读掩码
    wire [3:0] exu_wmask;           // 写掩码

    wire [31:0] exu_wLoData;
    wire exu_wlo;
    wire [31:0] exu_wHiData;
    wire exu_whi;

    wire [31:0] exu_inst_debug;
    wire [31:0] exu_pc_debug;

    // 数据相关
    wire exu_exu_regWr;
    wire [31:0] exu_exu_data;
    wire [4:0] exu_exu_regAddr;

    // MEM
    wire [31:0] mem_regData;        // 寄存器数据 (输出信号)
    wire [4:0] mem_regAddr;         // 寄存器地址 (输出信号)
    wire mem_regWr;                 // 寄存器写使能 (输出信号)

    wire [31:0] mem_memAddr;        // 内存访问地址 (输出信号)
    wire [31:0] mem_wtData;         // 写入内存的数据 (输出信号)
    wire mem_memCe;                 // 内存使能 (输出信号)
    wire mem_memWr;                 // 内存写使能 (输出信号)
    wire mem_memRr;                 // 内存读使能 (输出信号)
    wire [3:0] mem_w_mask;          // 写掩码 (输出信号)
    wire [3:0] mem_r_mask;          // 读掩码 (输出信号)

    wire [31:0] mem_inst_debug;
    wire [31:0] mem_pc_debug;

    // 数据相关
    wire mem_mem_regWr;
    wire [31:0] mem_mem_data;
    wire [4:0] mem_mem_regAddr;

    // WBU
    wire wbu_we;
    wire [4:0] wbu_wAddr;
    wire [31:0] wbu_wData;

    wire wbu_is_break;

    // 数据相关
    wire wbu_wbu_regWr;
    wire [31:0] wbu_wbu_data;
    wire [4:0] wbu_wbu_regAddr;

    // RegFile
    wire [31:0] regs_regaData;      // 读端口 A 数据
    wire [31:0] regs_regbData;      // 读端口 B 数据
    wire [1023:0] regs_registers_show; // 仅限于 debug，输出为很宽，达到了 1024

    // InstMem
    wire [31:0] instMem_data;

    // DataMem
    wire [31:0] dataMem_rdData;     // 输出给 MEM
    wire [31:0] dataMem_seg7;       // 数码管输出
    wire [31:0] dateMem_led_data;   // led 输出

    // HiLo
    wire [31:0] hilo_rLoData;  // 低位数据输出
    wire [31:0] hilo_rHiData;  // 高位数据输出


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

                // WBU
                .we(wbu_we),
                .wAddr(wbu_wAddr),
                .wData(wbu_wData),
                .registers_show(regs_registers_show)
            );

    IDU idu(
            .clk(clk),
            .rst(rst),
            .pc(ifu_pc),
            .inst(instMem_data),
            .regaData_i(regs_regaData),
            .regbData_i(regs_regbData),
            .regaData(idu_regaData),
            .regbData(idu_regbData),

            .jCe(idu_jCe),
            .jAddr(idu_jAddr),

            .regaRd(idu_regaRd),
            .regaAddr(idu_regaAddr),
            .regbRd(idu_regbRd),
            .regbAddr(idu_regbAddr),

            .op(idu_op),
            .memWr(idu_memWr),
            .memRr(idu_memRr),
            .w_mask(idu_w_mask),
            .r_mask(idu_r_mask),
            .regcWr(idu_regcWr),
            .regcAddr(idu_regcAddr),
            .rt_data_o(idu_rt_data_o),
            .inst_debug(idu_inst_debug),
            .pc_debug(idu_pc_debug),

            .exu_regWr(exu_exu_regWr),
            .exu_data(exu_exu_data),
            .exu_regAddr(exu_exu_regAddr),
            .mem_regWr(mem_mem_regWr),
            .mem_data(mem_mem_data),
            .mem_regAddr(mem_mem_regAddr),
            .wbu_regWr(wbu_wbu_regWr),
            .wbu_data(wbu_wbu_data),
            .wbu_regAddr(wbu_wbu_regAddr),
            .EXLSet(IDU_EXLSet),
            .EXLClear(IDU_EXLClear),
            .CP0_PC(IDU_CP0_PC),
            .CP0_EPC(CP0_EPC),
            .CP0_handler_PC(CP0_handler_PC)
        );

    CP0 cp0u(
            .clk(clk),
            .rst(rst),
            .PC(IDU_CP0_PC),
            .EXLSet(IDU_EXLSet),
            .EXLClear(IDU_EXLClear),
            .EPC(CP0_EPC),
            .handler_PC(CP0_handler_PC)
        );

    EXU exu(
            .clk(clk),
            .rst(rst),
            .regcData(exu_regcData),
            .regcAddr(exu_regcAddr),
            .regcWr(exu_regcWr),
            .memAddr(exu_memAddr),
            .memData(exu_memData),
            .readWr(exu_readWr),
            .writeWr(exu_writeWr),
            .rmask(exu_rmask),
            .wmask(exu_wmask),

            .op_i(idu_op),
            .memWr_i(idu_memWr),
            .memRr_i(idu_memRr),
            .w_mask_i(idu_w_mask),
            .r_mask_i(idu_r_mask),
            .regaData_i(idu_regaData),
            .regbData_i(idu_regbData),

            // for WBU
            .regcWr_i(idu_regcWr),
            .regcAddr_i(idu_regcAddr),
            .rt_data_i(idu_rt_data_o), // 这是 rt 中 的数据，将其传到 mem 中，为了 SW 等 LOAD 指令

            // for HiLo
            .rLoData_i(hilo_rLoData),
            .rHiData_i(hilo_rHiData),

            .wLoData(exu_wLoData),
            .wlo(exu_wlo),
            .wHiData(exu_wHiData),
            .whi(exu_whi),

            // debug
            .inst_debug_i(idu_inst_debug),
            .pc_debug_i(idu_pc_debug),
            .inst_debug(exu_inst_debug),
            .pc_debug(exu_pc_debug),

            .exu_regWr(exu_exu_regWr),
            .exu_data(exu_exu_data),
            .exu_regAddr(exu_exu_regAddr)
        );
    MEM mem(
            .clk(clk),
            .rst(rst),
            .regcData_i(exu_regcData),
            .regcAddr_i(exu_regcAddr),
            .regcWr_i(exu_regcWr),

            .regData(mem_regData),
            .regAddr(mem_regAddr),
            .regWr(mem_regWr),

            .memAddr_i(exu_memAddr),
            .memData_i(exu_memData),
            .rdData_i(dataMem_rdData), // 读取的数据
            .memWr_i(exu_writeWr),
            .memRr_i(exu_readWr),
            .w_mask_i(exu_wmask),
            .r_mask_i(exu_rmask),

            .memAddr(mem_memAddr),
            .wtData(mem_wtData),
            .memCe(mem_memCe),
            .memWr(mem_memWr),
            .memRr(mem_memRr),
            .w_mask(mem_w_mask),
            .r_mask(mem_r_mask),

            // debug
            .inst_debug_i(exu_inst_debug),
            .pc_debug_i(exu_pc_debug),
            .inst_debug(mem_inst_debug),
            .pc_debug(mem_pc_debug),

            .mem_regWr(mem_mem_regWr),
            .mem_data(mem_mem_data),
            .mem_regAddr(mem_mem_regAddr)
        );
    // output declaration of module DataMem

    DataMem data_mem(
                .clk(clk),
                .ce(mem_memCe),
                .we(mem_memWr),
                .wtData(mem_wtData),
                .addr(mem_memAddr),
                .memRr(mem_memRr),
                .w_mask(mem_w_mask),
                .r_mask(mem_r_mask),
                .rdData(dataMem_rdData), // 读出来的数据
                .seg7(dataMem_seg7),    // 数码管输出
                .led_data(dateMem_led_data)
            );
    // output declaration of module WB

    WB wb(
           .clk(clk),
           .rst(rst),
           .regWr(mem_regWr),
           .regAddr(mem_regAddr),
           .regData(mem_regData),
           .we(wbu_we),
           .wAddr(wbu_wAddr),
           .wData(wbu_wData),

           // debug
           .inst_debug_i(mem_inst_debug),
           .pc_debug_i(mem_pc_debug),

           .wbu_regWr(wbu_wbu_regWr),
           .wbu_data(wbu_wbu_data),
           .wbu_regAddr(wbu_wbu_regAddr),
           .is_break(wbu_is_break)
       );

    HiLo hilo(
             .rst(rst),
             .clk(clk),
             .wLoData_i(exu_wLoData),
             .wlo_i(exu_wlo),
             .wHiData_i(exu_wHiData),
             .whi_i(exu_whi),

             .rLoData(hilo_rLoData),
             .rHiData(hilo_rHiData)
         );

    IsBreak isbreak(
                .clk(clk),
                .isBreak(wbu_is_break)
            );
endmodule
