module IsBreak(
        input wire clk,
        input wire isBreak
    );
    reg [0:0] reg_isBreak;
    always @(posedge clk) begin
        reg_isBreak <= isBreak;
    end

endmodule
