module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB

    initial begin
        mem[0]  = 32'h0000f025;
        mem[1]  = 32'h241d1000;
        mem[2]  = 32'h8f9904b8;
        mem[3]  = 32'h04110060;
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
        mem[14]  = 32'h8f9904bc;
        mem[15]  = 32'h24040001;
        mem[16]  = 32'h1000004f;
        mem[17]  = 32'h00000000;
        mem[18]  = 32'h00000000;
        mem[19]  = 32'h00000000;
        mem[20]  = 32'h27bdffc0;
        mem[21]  = 32'hafb1001c;
        mem[22]  = 32'h3c110000;
        mem[23]  = 32'hafb5002c;
        mem[24]  = 32'hafb40028;
        mem[25]  = 32'hafb30024;
        mem[26]  = 32'hafb20020;
        mem[27]  = 32'h26310320;
        mem[28]  = 32'h3c140000;
        mem[29]  = 32'h3c130000;
        mem[30]  = 32'h3c150000;
        mem[31]  = 32'h3c120000;
        mem[32]  = 32'hafb60030;
        mem[33]  = 32'hafbf003c;
        mem[34]  = 32'hafbe0038;
        mem[35]  = 32'hafb70034;
        mem[36]  = 32'hafb00018;
        mem[37]  = 32'h269404d0;
        mem[38]  = 32'h26730000;
        mem[39]  = 32'h26360190;
        mem[40]  = 32'h26b50320;
        mem[41]  = 32'h26520348;
        mem[42]  = 32'h02a03025;
        mem[43]  = 32'h0260f025;
        mem[44]  = 32'h0280b825;
        mem[45]  = 32'h24d0fe70;
        mem[46]  = 32'h02201025;
        mem[47]  = 32'h00002025;
        mem[48]  = 32'h8e030000;
        mem[49]  = 32'h8c450000;
        mem[50]  = 32'h26100028;
        mem[51]  = 32'h00a30018;
        mem[52]  = 32'h24420004;
        mem[53]  = 32'h00001812;
        mem[54]  = 32'h00832021;
        mem[55]  = 32'h1606fff8;
        mem[56]  = 32'h00000000;
        mem[57]  = 32'h8fc20000;
        mem[58]  = 32'haee40000;
        mem[59]  = 32'h00442026;
        mem[60]  = 32'h2c840001;
        mem[61]  = 32'h0c000008;
        mem[62]  = 32'h00000000;
        mem[63]  = 32'h24040001;
        mem[64]  = 32'h0c000008;
        mem[65]  = 32'h00000000;
        mem[66]  = 32'h26060004;
        mem[67]  = 32'h26f70004;
        mem[68]  = 32'h27de0004;
        mem[69]  = 32'h1646ffe7;
        mem[70]  = 32'h00000000;
        mem[71]  = 32'h24040001;
        mem[72]  = 32'h26310028;
        mem[73]  = 32'h0c000008;
        mem[74]  = 32'h00000000;
        mem[75]  = 32'h26940028;
        mem[76]  = 32'h26730028;
        mem[77]  = 32'h1636ffdc;
        mem[78]  = 32'h00000000;
        mem[79]  = 32'h24040001;
        mem[80]  = 32'h0c000008;
        mem[81]  = 32'h00000000;
        mem[82]  = 32'h8fbf003c;
        mem[83]  = 32'h8fbe0038;
        mem[84]  = 32'h8fb70034;
        mem[85]  = 32'h8fb60030;
        mem[86]  = 32'h8fb5002c;
        mem[87]  = 32'h8fb40028;
        mem[88]  = 32'h8fb30024;
        mem[89]  = 32'h8fb20020;
        mem[90]  = 32'h8fb1001c;
        mem[91]  = 32'h8fb00018;
        mem[92]  = 32'h00001025;
        mem[93]  = 32'h27bd0040;
        mem[94]  = 32'h03e00008;
        mem[95]  = 32'h00000000;
        mem[96]  = 32'h00802025;
        mem[97]  = 32'h0000000d;
        mem[98]  = 32'h1000ffff;
        mem[99]  = 32'h00000000;
        mem[100]  = 32'h3c1c0000;
        mem[101]  = 32'h279c0000;
        mem[102]  = 32'h27bdffe0;
        mem[103]  = 32'h8f9904c0;
        mem[104]  = 32'hafbf001c;
        mem[105]  = 32'hafbc0010;
        mem[106]  = 32'h0411ffa9;
        mem[107]  = 32'h00000000;
        mem[108]  = 32'h00402025;
        mem[109]  = 32'h0000000d;
        mem[110]  = 32'h1000ffff;
        mem[111]  = 32'h00000000;
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
