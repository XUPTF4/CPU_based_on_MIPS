// 这是存放程序的单元，PC 从这里取指，这相当于 ROM，将程序段放到这里
module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB
    // initial begin
    //     $readmemh("C:/path_to_dummy.hex", mem);
    // end

    // 手动初始化

    initial begin
        mem[0]   = 32'h0000f025;
        mem[1]   = 32'h8f9d0014;
        mem[2]   = 32'h8f990008;
        mem[3]   = 32'h04110018;
        mem[4]   = 32'h00000000;
        mem[5]   = 32'h00000000;
        mem[6]   = 32'h00000000;
        mem[7]   = 32'h00000000;
        mem[8]   = 32'h10800003;
        mem[9]   = 32'h3c1c0000;
        mem[10]  = 32'h03e00008;
        mem[11]  = 32'h00000000;
        mem[12]  = 32'h279c0000;
        mem[13]  = 32'h8f99000c;
        mem[14]  = 32'h10000009;
        mem[15]  = 32'h24040001;
        mem[16]  = 32'h27bdffe0;
        mem[17]  = 32'hafbf001c;
        mem[18]  = 32'h0c000008;
        mem[19]  = 32'h24040001;
        mem[20]  = 32'h00001025;
        mem[21]  = 32'h8fbf001c;
        mem[22]  = 32'h03e00008;
        mem[23]  = 32'h27bd0020;
        mem[24]  = 32'h00802025;
        mem[25]  = 32'h0000000d;
        mem[26]  = 32'h1000ffff;
        mem[27]  = 32'h00000000;
        mem[28]  = 32'h3c1c0000;
        mem[29]  = 32'h27bdffe0;
        mem[30]  = 32'h279c0000;
        mem[31]  = 32'hafbf001c;
        mem[32]  = 32'hafbc0010;
        mem[33]  = 32'h8f990010;
        mem[34]  = 32'h0411ffed;
        mem[35]  = 32'h00000000;
        mem[36]  = 32'h00402025;
        mem[37]  = 32'h0000000d;
        mem[38]  = 32'h1000ffff;
        mem[39]  = 32'h00000000;
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
