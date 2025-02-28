// 访存
module MEM (
        input wire clk,
        input wire rst,                 // 复位信号
        // WBU
        input wire [31:0] regcData_i,
        input wire [4:0] regcAddr_i,
        input wire [0:0] regcWr_i,            // 寄存器写使能信号

        output reg [31:0] regData,     //<---|
        output wire [4:0] regAddr,      //    |
        output wire regWr,              //    |
        // MEM                          //    |
        input wire [31:0] memAddr_i,    //    |
        input wire [31:0] memData_i,    //    |
        input wire [31:0] rdData_i,     //--->|      load data to WBU
        input wire [0:0] memWr_i,       // 内存写使能 (输入信号)
        input wire [0:0] memRr_i,       // 内存读使能 (输入信号)
        input wire [3:0] w_mask_i,      // w_mask (输入信号)
        input wire [3:0] r_mask_i,      // r_mask (输入信号)

        output wire [31:0] memAddr,
        output wire [31:0] wtData,

        output wire memCe,
        output wire [0:0] memWr,         // 内存写使能 (输出信号)
        output wire [0:0] memRr,         // 内存读使能 (输出信号)
        output wire [3:0] w_mask,        // w_mask (输出信号)
        output wire [3:0] r_mask         // r_mask (输出信号)
    );
    // 寄存器组
    reg [31:0] reg_regcData_i_exu;
    reg [4:0] reg_regcAddr_i_exu;
    reg [0:0] reg_regcWr_i_exu;

    reg [31:0] reg_memAddr_i_exu;
    reg [31:0] reg_memData_i_exu;
    reg [31:0] reg_rdData_i_exu;
    reg [0:0] reg_memWr_i_exu;
    reg [0:0] reg_memRr_i_exu;
    reg [3:0] reg_w_mask_exu;
    reg [3:0] reg_r_mask_i_idu;

    always @(posedge clk) begin
        reg_regcData_i_exu <= regcData_i;
        reg_regcAddr_i_exu <= regcAddr_i;
        reg_regcWr_i_exu <= regcWr_i;
        reg_memAddr_i_exu <= memAddr_i;
        reg_memData_i_exu <= memData_i;
        reg_rdData_i_exu <= rdData_i;
        reg_memWr_i_exu <= memWr_i;
        reg_memRr_i_exu <= memRr_i;
        reg_w_mask_exu <= w_mask_i;
        reg_r_mask_i_idu <= r_mask_i;
    end

    wire [31:0] mem_regcData;
    wire [4:0] mem_regcAddr;
    wire [0:0] mem_regcWr;

    wire [31:0] mem_memAddr;
    wire [31:0] mem_memData;
    wire [31:0] mem_rdData;
    wire [0:0] mem_memWr;
    wire [0:0] mem_memRr;
    wire [3:0] mem_w_mask;
    wire [3:0] mem_r_mask;

    assign mem_regcData = reg_regcData_i_exu;
    assign mem_regcAddr = reg_regcAddr_i_exu;
    assign mem_regcWr = reg_regcWr_i_exu;

    assign mem_memAddr = reg_memAddr_i_exu;
    assign mem_memData = reg_memData_i_exu;
    assign mem_rdData = reg_rdData_i_exu;
    assign mem_memWr = reg_memWr_i_exu;
    assign mem_memRr = reg_memRr_i_exu;
    assign mem_w_mask = reg_w_mask_exu;
    assign mem_r_mask = reg_r_mask_i_idu;



    // WBU
    always @(*) begin
        regData = mem_regcData;  // 默认值
        if (mem_memRr) begin
            regData = mem_rdData;
        end
    end
    // 这个语句会导致 regData 延迟一个周期，所以在 WBU 中需要一个默认值
    // assign regData = memRr_i ? rdData_i : regcData_i;
    assign regAddr = mem_regcAddr;

    assign regWr = mem_regcWr;


    // MEM
    assign memAddr = mem_memAddr;
    assign wtData = mem_memData;
    assign memWr = mem_memWr;
    assign memRr = mem_memRr;
    assign w_mask = mem_w_mask;
    assign r_mask = mem_r_mask;
    assign memCe = rst? 1'b0 : mem_memRr | mem_memWr;
endmodule

