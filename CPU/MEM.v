// 访存单元
// 这里将参考资料中的 MEM 拆开，多了一个 WBU 单元
// 这里进行访存
module MEM (
        input wire rst,               // 复位信号
        // WBU
        input wire [31:0] regcData_i,
        input wire [4:0] regcAddr_i,
        input wire regcWr_i, // 寄存器写使能信号

        output wire [31:0] regData,         //<---|
        output wire [4:0] regAddr,          //    |
        output wire regWr,                  //    |
        // MEM                              //    |
        input wire [31:0] memAddr_i,        //    |
        input wire [31:0] memData_i,        //    |
        input wire [31:0] rdData_i,         //--->|      load data to WBU
        input wire [0:0] memWr_i,        // 内存写使能 (输入信号)
        input wire [0:0] memRr_i,        // 内存读使能 (输入信号)
        input wire [3:0] w_mask_i,          // w_mask (输入信号)
        input wire [3:0] r_mask_i,          // r_mask (输入信号)

        output wire [31:0] memAddr,
        output wire [31:0] wtData,
   
        output wire memCe,
        output reg [0:0] memWr,      // 内存写使能 (输出信号)
        output reg [0:0] memRr,      // 内存读使能 (输出信号)
        output reg [3:0] w_mask,        // w_mask (输出信号)
        output reg [3:0] r_mask        // r_mask (输出信号)
    );

    // WBU
    assign regData = memRr_i ? rdData_i : regcData_i; // 如果读内存，那么 WBU 输出 rdData_i;
    assign regAddr = regcAddr_i;

    assign regWr = regcWr_i;


    // MEM
    assign memAddr = memAddr_i;
    assign wtData = memData_i;
    assign memWr = memWr_i;
    assign memRr = memRr_i;
    assign w_mask = w_mask_i;
    assign r_mask = r_mask_i;
    assign memCe = rst? 1'b0 : memRr_i | memWr_i;


endmodule

