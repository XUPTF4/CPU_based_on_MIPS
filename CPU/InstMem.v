module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB

    initial begin
        mem[0]  = 32'h0000f025;
        mem[1]  = 32'h241d1000;
        mem[2]  = 32'h8f990008;
        mem[3]  = 32'h0411001c;
        mem[4]  = 32'h00000000;
        mem[5]  = 32'h00000000;
        mem[6]  = 32'h00000000;
        mem[7]  = 32'h00000000;
        mem[8]  = 32'h10800003;
        mem[9]  = 32'h00000000;
        mem[10]  = 32'h03e00008;
        mem[11]  = 32'h00000000;
        mem[12]  = 32'h3c1c0000;
        mem[13]  = 32'h279c0000;
        mem[14]  = 32'h8f99000c;
        mem[15]  = 32'h24040001;
        mem[16]  = 32'h1000000b;
        mem[17]  = 32'h00000000;
        mem[18]  = 32'h00000000;
        mem[19]  = 32'h00000000;
        mem[20]  = 32'h2402ffff;
        mem[21]  = 32'hac020ffc;
        mem[22]  = 32'hac020ffc;
        mem[23]  = 32'h1000fffd;
        mem[24]  = 32'h00000000;
        mem[25]  = 32'h00000000;
        mem[26]  = 32'h00000000;
        mem[27]  = 32'h00000000;
        mem[28]  = 32'h00802025;
        mem[29]  = 32'h0000000d;
        mem[30]  = 32'h1000ffff;
        mem[31]  = 32'h00000000;
        mem[32]  = 32'h3c1c0000;
        mem[33]  = 32'h279c0000;
        mem[34]  = 32'h27bdffe0;
        mem[35]  = 32'h8f990010;
        mem[36]  = 32'hafbf001c;
        mem[37]  = 32'hafbc0010;
        mem[38]  = 32'h0411ffed;
        mem[39]  = 32'h00000000;
        mem[40]  = 32'h00402025;
        mem[41]  = 32'h0000000d;
        mem[42]  = 32'h1000ffff;
        mem[43]  = 32'h00000000;
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
