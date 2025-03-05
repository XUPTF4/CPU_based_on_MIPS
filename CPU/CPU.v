// 顶层模块
module CPU (
        input wire clk,
        input wire resetn,
        // input wire rst,
        output [15:0] led,
        //  例如：这会亮最低位数码管
        // num_scan_select = 8'b1111_1110;
        output [7:0] num_scan_select,
        output [7:0] num_seg,// 要显示的数字
        output lcd_rst,
        output lcd_cs,
        output lcd_rs,
        output lcd_wr,
        output lcd_rd,
        inout[15:0] lcd_data_io,
        output lcd_bl_ctr,
        inout ct_int,
        inout ct_sda,
        output ct_scl,
        output ct_rstn
    );

    wire rst;
    assign rst = !resetn;


    reg[25:0] clk_div;
    reg cpu_clk;
    always @(posedge clk) begin
        if (!resetn) begin
            clk_div <= 26'd0;
        end
        else if(clk_div == 26'h2ffffff) begin
            clk_div <= 0;
            cpu_clk <= ~cpu_clk;
        end
        else
            clk_div <= clk_div + 1;
    end
    // 信号连线
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

    Seg7 seg7(
             .clk(clk), // 100M Hz
             .data(dataMem_seg7),
             .num_scan_select(num_scan_select),
             .num_seg7(num_seg)
         );

    Led led_u(
            .led_data(dateMem_led_data),
            .led(led)
        );


    IFU ifu(
            .clk(cpu_clk),
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
                .clk(cpu_clk),
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
            .clk(cpu_clk),
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
            .wbu_regAddr(wbu_wbu_regAddr)
        );

    EXU exu(
            .clk(cpu_clk),
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
            .clk(cpu_clk),
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
                .clk(cpu_clk),
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
           .clk(cpu_clk),
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
             .clk(cpu_clk),
             .wLoData_i(exu_wLoData),
             .wlo_i(exu_wlo),
             .wHiData_i(exu_wHiData),
             .whi_i(exu_whi),

             .rLoData(hilo_rLoData),
             .rHiData(hilo_rHiData)
         );

    IsBreak isbreak(
                .clk(cpu_clk),
                .isBreak(wbu_is_break)
            );


    // lcd 模块
    reg         display_valid;
    reg  [39:0] display_name;
    reg  [31:0] display_value;
    wire [5 :0] display_number;
    wire        input_valid;
    wire [31:0] input_value;

    lcd_module lcd_module(
                   .clk            (clk           ),
                   .resetn         (resetn        ),


                   .display_valid  (display_valid ),
                   .display_name   (display_name  ),
                   .display_value  (display_value ),
                   .display_number (display_number),
                   .input_valid    (input_valid   ),
                   .input_value    (input_value   ),


                   .lcd_rst        (lcd_rst       ),
                   .lcd_cs         (lcd_cs        ),
                   .lcd_rs         (lcd_rs        ),
                   .lcd_wr         (lcd_wr        ),
                   .lcd_rd         (lcd_rd        ),
                   .lcd_data_io    (lcd_data_io   ),
                   .lcd_bl_ctr     (lcd_bl_ctr    ),
                   .ct_int         (ct_int        ),
                   .ct_sda         (ct_sda        ),
                   .ct_scl         (ct_scl        ),
                   .ct_rstn        (ct_rstn       )
               );


    always @(posedge clk) begin

        case(display_number)
            6'd1 : //显示PC值
            begin
                display_valid <= 1'b1;
                display_name  <= "   PC";
                display_value <= exu_pc_debug;
            end
            6'd2 : //显示PC取出的指令
            begin
                display_valid <= 1'b1;
                display_name  <= " INST";
                display_value <= exu_inst_debug;
            end
            6'd3 : //显示要观察的内存地址
            begin
                display_valid <= 1'b1;
                display_name  <= " SEG7";
                display_value <= dataMem_seg7;
            end
            6'd4 : //显示该内存地址对应的数据
            begin
                display_valid <= 1'b1;
                display_name  <= " LEDS";
                display_value <= dateMem_led_data;
            end
            6'd5: // 开始寄存区显示
            begin
                display_valid <= 1'b1;
                display_name  <= " ZERO";
                display_value <= regs_registers_show[0*32 +: 32];
            end
            6'd6:begin
                display_valid <= 1'b1;
                display_name <= "   AT";
                display_value <= regs_registers_show[1*32 +: 32];
            end
            6'd7:begin
                display_valid <= 1'b1;
                display_name <= "   V0";
                display_value <= regs_registers_show[2*32 +: 32];
            end
            6'd8:begin
                display_valid <= 1'b1;
                display_name <= "   V1";
                display_value <= regs_registers_show[3*32 +: 32];
            end
            6'd9:begin
                display_valid <= 1'b1;
                display_name <= "   A0";
                display_value <= regs_registers_show[4*32 +: 32];
            end
            6'd10:begin
                display_valid <= 1'b1;
                display_name <= "   A1";
                display_value <= regs_registers_show[5*32 +: 32];
            end
            6'd11:begin
                display_valid <= 1'b1;
                display_name <= "   A2";
                display_value <= regs_registers_show[6*32 +: 32];
            end
            6'd12:begin
                display_valid <= 1'b1;
                display_name <= "   A3";
                display_value <= regs_registers_show[7*32 +: 32];
            end
            6'd13:begin
                display_valid <= 1'b1;
                display_name <= "   A0";
                display_value <= regs_registers_show[8*32 +: 32];
            end
            6'd14:begin
                display_valid <= 1'b1;
                display_name <= "   T1";
                display_value <= regs_registers_show[9*32 +: 32];
            end
            6'd15:begin
                display_valid <= 1'b1;
                display_name <= "   T2";
                display_value <= regs_registers_show[10*32 +: 32];
            end
            6'd16:begin
                display_valid <= 1'b1;
                display_name <= "   T3";
                display_value <= regs_registers_show[11*32 +: 32];
            end
            6'd17:begin
                display_valid <= 1'b1;
                display_name <= "   T4";
                display_value <= regs_registers_show[12*32 +: 32];
            end
            6'd18:begin
                display_valid <= 1'b1;
                display_name <= "   T5";
                display_value <= regs_registers_show[13*32 +: 32];
            end
            6'd19:begin
                display_valid <= 1'b1;
                display_name <= "   T6";
                display_value <= regs_registers_show[14*32 +: 32];
            end
            6'd20:begin
                display_valid <= 1'b1;
                display_name <= "   T7";
                display_value <= regs_registers_show[15*32 +: 32];
            end
            6'd21:begin
                display_valid <= 1'b1;
                display_name <= "   S0";
                display_value <= regs_registers_show[16*32 +: 32];
            end
            6'd22:begin
                display_valid <= 1'b1;
                display_name <= "   S1";
                display_value <= regs_registers_show[17*32 +: 32];
            end
            6'd23:begin
                display_valid <= 1'b1;
                display_name <= "   S2";
                display_value <= regs_registers_show[18*32 +: 32];
            end
            6'd24:begin
                display_valid <= 1'b1;
                display_name <= "   S3";
                display_value <= regs_registers_show[19*32 +: 32];
            end
            6'd25:begin
                display_valid <= 1'b1;
                display_name <= "   S4";
                display_value <= regs_registers_show[20*32 +: 32];
            end
            6'd26:begin
                display_valid <= 1'b1;
                display_name <= "   S5";
                display_value <= regs_registers_show[21*32 +: 32];
            end
            6'd27:begin
                display_valid <= 1'b1;
                display_name <= "   S6";
                display_value <= regs_registers_show[22*32 +: 32];
            end
            6'd28:begin
                display_valid <= 1'b1;
                display_name <= "   S7";
                display_value <= regs_registers_show[23*32 +: 32];
            end
            6'd29:begin
                display_valid <= 1'b1;
                display_name <= "   T8";
                display_value <= regs_registers_show[24*32 +: 32];
            end
            6'd30:begin
                display_valid <= 1'b1;
                display_name <= "   T9";
                display_value <= regs_registers_show[25*32 +: 32];
            end
            6'd31:begin
                display_valid <= 1'b1;
                display_name <= "   K0";
                display_value <= regs_registers_show[26*32 +: 32];
            end
            6'd32:begin
                display_valid <= 1'b1;
                display_name <= "   K1";
                display_value <= regs_registers_show[27*32 +: 32];
            end
            6'd33:begin
                display_valid <= 1'b1;
                display_name <= "   GP";
                display_value <= regs_registers_show[28*32 +: 32];
            end
            6'd34:begin
                display_valid <= 1'b1;
                display_name <= "   SP";
                display_value <= regs_registers_show[29*32 +: 32];
            end
            6'd35:begin
                display_valid <= 1'b1;
                display_name <= "   FP";
                display_value <= regs_registers_show[30*32 +: 32];
            end
            6'd36:begin
                display_valid <= 1'b1;
                display_name <= "   RA";
                display_value <= regs_registers_show[31*32 +: 32];
            end


            default :begin
                display_valid <= 1'b0;
            end
        endcase
    end



endmodule
