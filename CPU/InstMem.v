module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB

    initial begin
        mem[0]  = 32'h0000f025;
        mem[1]  = 32'h241d1000;
        mem[2]  = 32'h8f990028;
        mem[3]  = 32'h04110078;
        mem[4]  = 32'h00000000;
        mem[5]  = 32'h00000000;
        mem[6]  = 32'h00000000;
        mem[7]  = 32'h00000000;
        mem[8]  = 32'h10800003;
        mem[9]  = 32'h3c1c0000;
        mem[10]  = 32'h03e00008;
        mem[11]  = 32'h00000000;
        mem[12]  = 32'h279c0000;
        mem[13]  = 32'h8f99002c;
        mem[14]  = 32'h10000069;
        mem[15]  = 32'h24040001;
        mem[16]  = 32'h0000000c;
        mem[17]  = 32'h03e00008;
        mem[18]  = 32'h00000000;
        mem[19]  = 32'h3c020000;
        mem[20]  = 32'h8c420000;
        mem[21]  = 32'h8c420000;
        mem[22]  = 32'hac400000;
        mem[23]  = 32'hac410004;
        mem[24]  = 32'hac420008;
        mem[25]  = 32'hac43000c;
        mem[26]  = 32'h03e00008;
        mem[27]  = 32'hac440010;
        mem[28]  = 32'h3c020000;
        mem[29]  = 32'h8c430000;
        mem[30]  = 32'h8c630000;
        mem[31]  = 32'h8c600000;
        mem[32]  = 32'h8c610004;
        mem[33]  = 32'h8c620008;
        mem[34]  = 32'h8c63000c;
        mem[35]  = 32'h8c640010;
        mem[36]  = 32'h8c420000;
        mem[37]  = 32'h8c420000;
        mem[38]  = 32'h8c480080;
        mem[39]  = 32'h03e00008;
        mem[40]  = 32'h40887000;
        mem[41]  = 32'h3c030000;
        mem[42]  = 32'h3c020000;
        mem[43]  = 32'h8c640000;
        mem[44]  = 32'h244200c4;
        mem[45]  = 32'h10820003;
        mem[46]  = 32'h00000000;
        mem[47]  = 32'h03e00008;
        mem[48]  = 32'hac620000;
        mem[49]  = 32'h3c020000;
        mem[50]  = 32'h24420148;
        mem[51]  = 32'h03e00008;
        mem[52]  = 32'hac620000;
        mem[53]  = 32'h27bdffe0;
        mem[54]  = 32'hafbf001c;
        mem[55]  = 32'h0c000013;
        mem[56]  = 32'h00000000;
        mem[57]  = 32'h0c000029;
        mem[58]  = 32'h00000000;
        mem[59]  = 32'h0c00001c;
        mem[60]  = 32'h00000000;
        mem[61]  = 32'h42000018;
        mem[62]  = 32'h8fbf001c;
        mem[63]  = 32'h03e00008;
        mem[64]  = 32'h27bd0020;
        mem[65]  = 32'h24a2ff7c;
        mem[66]  = 32'hafa40000;
        mem[67]  = 32'hafa50004;
        mem[68]  = 32'haca6fffc;
        mem[69]  = 32'h03e00008;
        mem[70]  = 32'haca7ff8c;
        mem[71]  = 32'hac040ffc;
        mem[72]  = 32'h03e00008;
        mem[73]  = 32'h00000000;
        mem[74]  = 32'h27bdffe0;
        mem[75]  = 32'h3c07bbbb;
        mem[76]  = 32'h3c03aaaa;
        mem[77]  = 32'h24060001;
        mem[78]  = 32'hafbf001c;
        mem[79]  = 32'h00802825;
        mem[80]  = 32'h34e7bbbb;
        mem[81]  = 32'h3463aaaa;
        mem[82]  = 32'h8ca20000;
        mem[83]  = 32'h10460002;
        mem[84]  = 32'h00602025;
        mem[85]  = 32'h00e02025;
        mem[86]  = 32'h0c000047;
        mem[87]  = 32'h00000000;
        mem[88]  = 32'h0c000010;
        mem[89]  = 32'h00000000;
        mem[90]  = 32'h1000fff8;
        mem[91]  = 32'h8ca20000;
        mem[92]  = 32'h3c090000;
        mem[93]  = 32'h3c030000;
        mem[94]  = 32'h3c060000;
        mem[95]  = 32'h27bdffd0;
        mem[96]  = 32'h24630148;
        mem[97]  = 32'h252800c4;
        mem[98]  = 32'h24c60128;
        mem[99]  = 32'hafbf002c;
        mem[100]  = 32'h24070001;
        mem[101]  = 32'h01002025;
        mem[102]  = 32'h0c000041;
        mem[103]  = 32'h00602825;
        mem[104]  = 32'h3c050000;
        mem[105]  = 32'h24070002;
        mem[106]  = 32'had2200c4;
        mem[107]  = 32'h24a501cc;
        mem[108]  = 32'h0c000041;
        mem[109]  = 32'h00602025;
        mem[110]  = 32'h00002025;
        mem[111]  = 32'h0c000010;
        mem[112]  = 32'had020084;
        mem[113]  = 32'h0c000008;
        mem[114]  = 32'h00000000;
        mem[115]  = 32'h00001025;
        mem[116]  = 32'h8fbf002c;
        mem[117]  = 32'h03e00008;
        mem[118]  = 32'h27bd0030;
        mem[119]  = 32'h00000000;
        mem[120]  = 32'h00802025;
        mem[121]  = 32'h0000000d;
        mem[122]  = 32'h1000ffff;
        mem[123]  = 32'h00000000;
        mem[124]  = 32'h3c1c0000;
        mem[125]  = 32'h27bdffe0;
        mem[126]  = 32'h279c0000;
        mem[127]  = 32'hafbf001c;
        mem[128]  = 32'hafbc0010;
        mem[129]  = 32'h8f990030;
        mem[130]  = 32'h0411ffd9;
        mem[131]  = 32'h00000000;
        mem[132]  = 32'h0c000078;
        mem[133]  = 32'h00402025;
        mem[134]  = 32'h00000000;
        mem[135]  = 32'h00000000;
        mem[136]  = 32'h10800003;
        mem[137]  = 32'h3c1c0000;
        mem[138]  = 32'h03e00008;
        mem[139]  = 32'h00000000;
        mem[140]  = 32'h279c0000;
        mem[141]  = 32'h8f99002c;
        mem[142]  = 32'h1000ffe9;
        mem[143]  = 32'h24040001;
        mem[144]  = 32'h0000000c;
        mem[145]  = 32'h03e00008;
        mem[146]  = 32'h00000000;
        mem[147]  = 32'h3c020000;
        mem[148]  = 32'h8c420000;
        mem[149]  = 32'h8c420000;
        mem[150]  = 32'hac400000;
        mem[151]  = 32'hac410004;
        mem[152]  = 32'hac420008;
        mem[153]  = 32'hac43000c;
        mem[154]  = 32'h03e00008;
        mem[155]  = 32'hac440010;
        mem[156]  = 32'h3c020000;
        mem[157]  = 32'h8c430000;
        mem[158]  = 32'h8c630000;
        mem[159]  = 32'h8c600000;
        mem[160]  = 32'h8c610004;
        mem[161]  = 32'h8c620008;
        mem[162]  = 32'h8c63000c;
        mem[163]  = 32'h8c640010;
        mem[164]  = 32'h8c420000;
        mem[165]  = 32'h8c420000;
        mem[166]  = 32'h8c480080;
        mem[167]  = 32'h03e00008;
        mem[168]  = 32'h40887000;
        mem[169]  = 32'h3c030000;
        mem[170]  = 32'h3c020000;
        mem[171]  = 32'h8c640000;
        mem[172]  = 32'h244200c4;
        mem[173]  = 32'h10820003;
        mem[174]  = 32'h00000000;
        mem[175]  = 32'h03e00008;
        mem[176]  = 32'hac620000;
        mem[177]  = 32'h3c020000;
        mem[178]  = 32'h24420148;
        mem[179]  = 32'h03e00008;
        mem[180]  = 32'hac620000;
        mem[181]  = 32'h27bdffe0;
        mem[182]  = 32'hafbf001c;
        mem[183]  = 32'h0c000013;
        mem[184]  = 32'h00000000;
        mem[185]  = 32'h0c000029;
        mem[186]  = 32'h00000000;
        mem[187]  = 32'h0c00001c;
        mem[188]  = 32'h00000000;
        mem[189]  = 32'h42000018;
        mem[190]  = 32'h8fbf001c;
        mem[191]  = 32'h03e00008;
        mem[192]  = 32'h27bd0020;
        mem[193]  = 32'h24a2ff7c;
        mem[194]  = 32'hafa40000;
        mem[195]  = 32'hafa50004;
        mem[196]  = 32'haca6fffc;
        mem[197]  = 32'h03e00008;
        mem[198]  = 32'haca7ff8c;
        mem[199]  = 32'hac040ffc;
        mem[200]  = 32'h03e00008;
        mem[201]  = 32'h00000000;
        mem[202]  = 32'h27bdffe0;
        mem[203]  = 32'h3c07bbbb;
        mem[204]  = 32'h3c03aaaa;
        mem[205]  = 32'h24060001;
        mem[206]  = 32'hafbf001c;
        mem[207]  = 32'h00802825;
        mem[208]  = 32'h34e7bbbb;
        mem[209]  = 32'h3463aaaa;
        mem[210]  = 32'h8ca20000;
        mem[211]  = 32'h10460002;
        mem[212]  = 32'h00602025;
        mem[213]  = 32'h00e02025;
        mem[214]  = 32'h0c000047;
        mem[215]  = 32'h00000000;
        mem[216]  = 32'h0c000010;
        mem[217]  = 32'h00000000;
        mem[218]  = 32'h1000fff8;
        mem[219]  = 32'h8ca20000;
        mem[220]  = 32'h3c090000;
        mem[221]  = 32'h3c030000;
        mem[222]  = 32'h3c060000;
        mem[223]  = 32'h27bdffd0;
        mem[224]  = 32'h24630148;
        mem[225]  = 32'h252800c4;
        mem[226]  = 32'h24c60128;
        mem[227]  = 32'hafbf002c;
        mem[228]  = 32'h24070001;
        mem[229]  = 32'h01002025;
        mem[230]  = 32'h0c000041;
        mem[231]  = 32'h00602825;
        mem[232]  = 32'h3c050000;
        mem[233]  = 32'h24070002;
        mem[234]  = 32'had2200c4;
        mem[235]  = 32'h24a501cc;
        mem[236]  = 32'h0c000041;
        mem[237]  = 32'h00602025;
        mem[238]  = 32'h00002025;
        mem[239]  = 32'h0c000010;
        mem[240]  = 32'had020084;
        mem[241]  = 32'h0c000008;
        mem[242]  = 32'h00000000;
        mem[243]  = 32'h00001025;
        mem[244]  = 32'h8fbf002c;
        mem[245]  = 32'h03e00008;
        mem[246]  = 32'h27bd0030;
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
