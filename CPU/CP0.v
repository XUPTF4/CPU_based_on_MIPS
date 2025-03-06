module CP0(
        input clk,
        input rst,
        input [31:0] PC,
        input EXLSet,
        input EXLClear, // eret 信号
        output  [31:0] EPC,
        output  [31:0] handler_PC // 异常入口
    );

    reg exl;
    reg [31:0] exception_handler_addr; // 异常处理程序入口地址
    reg [31:0] reg_EPC; // 异常返回地址



    initial begin
        exl = 0;
        reg_EPC = 32'h0;
        exception_handler_addr = 32'hf0; // 这个值可以观察反汇编代码
    end

    assign handler_PC = exception_handler_addr;
    assign EPC = reg_EPC;

    always @(posedge clk) begin
        if (rst) begin
            exl <= 0;
            reg_EPC <= 32'h0;

        end
        if (EXLSet) begin
            exl <= 1'b1;
            reg_EPC <= PC;

        end
        // eret
        if (EXLClear) begin
            exl <= 1'b0;
            reg_EPC <= 32'd0;
        end
    end


endmodule
