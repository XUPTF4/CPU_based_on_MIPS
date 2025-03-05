module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB

    initial begin
        mem[0]  = 32'h3c1e1001;
        mem[1]  = 32'h8f9f0000;
        mem[2]  = 32'h27ff0078;
        mem[3]  = 32'h10000001;
        mem[4]  = 32'h00000000;
        mem[5]  = 32'h27de0004;
        mem[6]  = 32'h27dafffc;
        mem[7]  = 32'h241b0001;
        mem[8]  = 32'haf5b0000;
        mem[9]  = 32'h27de0004;
        mem[10]  = 32'h27dafffc;
        mem[11]  = 32'h241b0002;
        mem[12]  = 32'haf5b0000;
        mem[13]  = 32'h27de0004;
        mem[14]  = 32'h27dafffc;
        mem[15]  = 32'h241b0003;
        mem[16]  = 32'haf5b0000;
        mem[17]  = 32'h27dafff4;
        mem[18]  = 32'h8f480000;
        mem[19]  = 32'h27dafff8;
        mem[20]  = 32'h8f490000;
        mem[21]  = 32'h01094021;
        mem[22]  = 32'h27dafffc;
        mem[23]  = 32'h8f490000;
        mem[24]  = 32'h01094021;
        mem[25]  = 32'h01001025;
        mem[26]  = 32'h27defff4;
        mem[27]  = 32'h03e00008;
        mem[28]  = 32'h00000000;
        mem[29]  = 32'h27defff4;
        mem[30]  = 32'h00000000;
        mem[31]  = 32'h00000000;
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
