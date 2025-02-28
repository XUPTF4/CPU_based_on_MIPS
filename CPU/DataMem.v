module DataMem(
    input clk,
    input ce,
    input we,
    input [31:0] wtData,
    input [31:0] addr,
    input memRr,                // 内存读使能
    input [3:0] w_mask,         // 写掩码
    input [3:0] r_mask,         // 读掩码
    output reg [31:0] rdData    // 组合逻辑直接输出
);
    reg [31:0] memory [0:1023]; // 4KB 内存
// 初始化 memory

    initial begin
        memory[0]  = 32'hfffffadb;
        memory[1]  = 32'h0000288b;
        memory[2]  = 32'hffffe943;
        memory[3]  = 32'hffffc80e;
        memory[4]  = 32'hffffef16;
        memory[5]  = 32'hfffff3d6;
        memory[6]  = 32'hffffd92c;
        memory[7]  = 32'h00001b79;
        memory[8]  = 32'hfffff8a5;
        memory[9]  = 32'hffffe875;
        memory[10]  = 32'hffffa136;
        memory[11]  = 32'hfffffca3;
        memory[12]  = 32'h00000fcc;
        memory[13]  = 32'hffffb290;
        memory[14]  = 32'hffffff21;
        memory[15]  = 32'h00000376;
        memory[16]  = 32'hffffd12c;
        memory[17]  = 32'hffffe6d6;
        memory[18]  = 32'hffffc9ea;
        memory[19]  = 32'hfffffbe2;
        memory[20]  = 32'h00002637;
        memory[21]  = 32'hffffe45f;
        memory[22]  = 32'hfffffc6a;
        memory[23]  = 32'hffffe8e9;
        memory[24]  = 32'hfffffc39;
        memory[25]  = 32'hffffe444;
        memory[26]  = 32'h0000390d;
        memory[27]  = 32'hffffe27c;
        memory[28]  = 32'hfffff291;
        memory[29]  = 32'h00002587;
        memory[30]  = 32'h00003e6c;
        memory[31]  = 32'hfffffdf8;
        memory[32]  = 32'hffffcc0f;
        memory[33]  = 32'h00003ac3;
        memory[34]  = 32'h00001829;
        memory[35]  = 32'hfffff1ba;
        memory[36]  = 32'h0000052d;
        memory[37]  = 32'h00001061;
        memory[38]  = 32'h0000421d;
        memory[39]  = 32'hffffba9f;
        memory[40]  = 32'h00000a06;
        memory[41]  = 32'h00000c73;
        memory[42]  = 32'h00002808;
        memory[43]  = 32'h00001ef5;
        memory[44]  = 32'h000018ae;
        memory[45]  = 32'h0000058d;
        memory[46]  = 32'h00003938;
        memory[47]  = 32'h000002bc;
        memory[48]  = 32'hffffd05f;
        memory[49]  = 32'h0000043b;
        memory[50]  = 32'hffffcec5;
        memory[51]  = 32'h00004a3e;
        memory[52]  = 32'h000051d8;
        memory[53]  = 32'h000048a7;
        memory[54]  = 32'hfffff9fd;
        memory[55]  = 32'h00001440;
        memory[56]  = 32'h00004400;
        memory[57]  = 32'h00001a54;
        memory[58]  = 32'h00001878;
        memory[59]  = 32'h00003b0a;
        memory[60]  = 32'hffffce55;
        memory[61]  = 32'h00003b11;
        memory[62]  = 32'h000026eb;
        memory[63]  = 32'hffffca6b;
        memory[64]  = 32'h0000096b;
        memory[65]  = 32'hfffff76c;
        memory[66]  = 32'h00001803;
        memory[67]  = 32'hfffff95e;
        memory[68]  = 32'hfffff2c3;
        memory[69]  = 32'h00002008;
        memory[70]  = 32'hffffb5c1;
        memory[71]  = 32'h00003081;
        memory[72]  = 32'h0000165b;
        memory[73]  = 32'hffffd3d3;
        memory[74]  = 32'hffffb4d6;
        memory[75]  = 32'h00003d7c;
        memory[76]  = 32'hfffff131;
        memory[77]  = 32'hfffff093;
        memory[78]  = 32'hffffccb6;
        memory[79]  = 32'hffffffeb;
        memory[80]  = 32'hffffcef3;
        memory[81]  = 32'hffffe8ae;
        memory[82]  = 32'hffffd2ce;
        memory[83]  = 32'hffffdd37;
        memory[84]  = 32'h00002fc3;
        memory[85]  = 32'h00001e86;
        memory[86]  = 32'hffffec1a;
        memory[87]  = 32'h000011b4;
        memory[88]  = 32'h0000042f;
        memory[89]  = 32'hfffffae3;
        memory[90]  = 32'hfffff475;
        memory[91]  = 32'h000024a5;
        memory[92]  = 32'h000018e4;
        memory[93]  = 32'hffffe50e;
        memory[94]  = 32'h0000239d;
        memory[95]  = 32'h00001679;
        memory[96]  = 32'h0000512a;
        memory[97]  = 32'hffffec4b;
        memory[98]  = 32'h00000417;
        memory[99]  = 32'h00002f52;
        memory[100]  = 32'hffffffd0;
        memory[101]  = 32'hffffffba;
        memory[102]  = 32'hffffffd8;
        memory[103]  = 32'hffffffae;
        memory[104]  = 32'hffffffb6;
        memory[105]  = 32'hffffffc1;
        memory[106]  = 32'hffffffc5;
        memory[107]  = 32'hffffffb8;
        memory[108]  = 32'hffffff9c;
        memory[109]  = 32'hffffffb8;
        memory[110]  = 32'h00000005;
        memory[111]  = 32'hffffffac;
        memory[112]  = 32'h0000001c;
        memory[113]  = 32'h00000038;
        memory[114]  = 32'h0000003c;
        memory[115]  = 32'hffffffdf;
        memory[116]  = 32'hffffffd6;
        memory[117]  = 32'hffffffce;
        memory[118]  = 32'hffffffad;
        memory[119]  = 32'hffffffad;
        memory[120]  = 32'hfffffffb;
        memory[121]  = 32'h00000005;
        memory[122]  = 32'h00000030;
        memory[123]  = 32'h0000004b;
        memory[124]  = 32'hffffffb2;
        memory[125]  = 32'hfffffff7;
        memory[126]  = 32'h00000009;
        memory[127]  = 32'h00000002;
        memory[128]  = 32'h00000058;
        memory[129]  = 32'h00000046;
        memory[130]  = 32'h00000045;
        memory[131]  = 32'h00000017;
        memory[132]  = 32'h00000042;
        memory[133]  = 32'h00000042;
        memory[134]  = 32'hfffffff5;
        memory[135]  = 32'h00000032;
        memory[136]  = 32'h00000043;
        memory[137]  = 32'h00000012;
        memory[138]  = 32'hffffffc6;
        memory[139]  = 32'h0000004c;
        memory[140]  = 32'h0000001e;
        memory[141]  = 32'h0000002d;
        memory[142]  = 32'h00000020;
        memory[143]  = 32'h00000019;
        memory[144]  = 32'hffffffb7;
        memory[145]  = 32'h00000039;
        memory[146]  = 32'hffffffbd;
        memory[147]  = 32'hfffffff2;
        memory[148]  = 32'h00000035;
        memory[149]  = 32'hffffffdf;
        memory[150]  = 32'h00000062;
        memory[151]  = 32'hffffffaa;
        memory[152]  = 32'hffffffc1;
        memory[153]  = 32'h00000050;
        memory[154]  = 32'hffffffd3;
        memory[155]  = 32'hffffffa8;
        memory[156]  = 32'h00000050;
        memory[157]  = 32'hffffffc0;
        memory[158]  = 32'h0000003a;
        memory[159]  = 32'hffffffac;
        memory[160]  = 32'hffffffc9;
        memory[161]  = 32'hffffffd9;
        memory[162]  = 32'hfffffff3;
        memory[163]  = 32'hffffffe5;
        memory[164]  = 32'hffffffdb;
        memory[165]  = 32'h00000008;
        memory[166]  = 32'hffffffa0;
        memory[167]  = 32'h00000054;
        memory[168]  = 32'hffffffa7;
        memory[169]  = 32'h0000001f;
        memory[170]  = 32'hffffffae;
        memory[171]  = 32'h0000003a;
        memory[172]  = 32'h00000051;
        memory[173]  = 32'hffffffd7;
        memory[174]  = 32'hffffffc6;
        memory[175]  = 32'h00000024;
        memory[176]  = 32'h0000004c;
        memory[177]  = 32'hffffffb1;
        memory[178]  = 32'hffffffe3;
        memory[179]  = 32'h00000017;
        memory[180]  = 32'h00000056;
        memory[181]  = 32'hffffffd2;
        memory[182]  = 32'h00000010;
        memory[183]  = 32'hffffffee;
        memory[184]  = 32'h00000051;
        memory[185]  = 32'h0000005a;
        memory[186]  = 32'h00000023;
        memory[187]  = 32'hffffffa6;
        memory[188]  = 32'h0000002b;
        memory[189]  = 32'h00000037;
        memory[190]  = 32'hffffffda;
        memory[191]  = 32'hffffffed;
        memory[192]  = 32'hffffffd8;
        memory[193]  = 32'h00000052;
        memory[194]  = 32'hffffffb4;
        memory[195]  = 32'h00000039;
        memory[196]  = 32'hffffffe3;
        memory[197]  = 32'hfffffffe;
        memory[198]  = 32'h0000004f;
        memory[199]  = 32'hffffffd0;
        memory[200]  = 32'h0000001f;
        memory[201]  = 32'hffffffb7;
        memory[202]  = 32'hffffffbd;
        memory[203]  = 32'hffffffe4;
        memory[204]  = 32'h00000057;
        memory[205]  = 32'hffffffef;
        memory[206]  = 32'hfffffff1;
        memory[207]  = 32'hffffffdd;
        memory[208]  = 32'hffffffcb;
        memory[209]  = 32'hffffffca;
        memory[210]  = 32'h00000034;
        memory[211]  = 32'h00000024;
        memory[212]  = 32'h00000009;
        memory[213]  = 32'hffffffa5;
        memory[214]  = 32'hffffffe5;
        memory[215]  = 32'hffffffb2;
        memory[216]  = 32'h0000002a;
        memory[217]  = 32'h00000052;
        memory[218]  = 32'h00000013;
        memory[219]  = 32'hfffffffa;
        memory[220]  = 32'h00000029;
        memory[221]  = 32'hffffffc8;
        memory[222]  = 32'h0000001f;
        memory[223]  = 32'h00000020;
        memory[224]  = 32'hffffffcc;
        memory[225]  = 32'h0000004a;
        memory[226]  = 32'h0000001c;
        memory[227]  = 32'h00000014;
        memory[228]  = 32'h00000037;
        memory[229]  = 32'hffffffb8;
        memory[230]  = 32'hffffffc5;
        memory[231]  = 32'h00000002;
        memory[232]  = 32'hffffffb1;
        memory[233]  = 32'hfffffff8;
        memory[234]  = 32'h0000002c;
        memory[235]  = 32'h00000037;
        memory[236]  = 32'hffffffad;
        memory[237]  = 32'hffffffa1;
        memory[238]  = 32'hffffffd3;
        memory[239]  = 32'h00000032;
        memory[240]  = 32'hffffffa1;
        memory[241]  = 32'h0000003d;
        memory[242]  = 32'hffffffc1;
        memory[243]  = 32'h0000003e;
        memory[244]  = 32'hfffffff0;
        memory[245]  = 32'h00000034;
        memory[246]  = 32'h00000028;
        memory[247]  = 32'h0000005c;
        memory[248]  = 32'hffffffe0;
        memory[249]  = 32'hffffffe6;
        memory[250]  = 32'hffffff9d;
        memory[251]  = 32'h00000034;
        memory[252]  = 32'h00000060;
        memory[253]  = 32'h0000003f;
        memory[254]  = 32'hffffffb5;
        memory[255]  = 32'hffffffb6;
        memory[256]  = 32'hffffffae;
        memory[257]  = 32'h00000052;
        memory[258]  = 32'hffffffa1;
        memory[259]  = 32'h0000002a;
        memory[260]  = 32'h0000000b;
        memory[261]  = 32'hffffffea;
        memory[262]  = 32'h0000001b;
        memory[263]  = 32'hffffffe5;
        memory[264]  = 32'hffffffe5;
        memory[265]  = 32'hffffffb4;
        memory[266]  = 32'hffffffb9;
        memory[267]  = 32'h0000003a;
        memory[268]  = 32'hffffffd8;
        memory[269]  = 32'hffffffbf;
        memory[270]  = 32'h0000005b;
        memory[271]  = 32'hffffffcb;
        memory[272]  = 32'hffffffbd;
        memory[273]  = 32'h00000048;
        memory[274]  = 32'h00000024;
        memory[275]  = 32'hffffffb3;
        memory[276]  = 32'hfffffffd;
        memory[277]  = 32'h0000005d;
        memory[278]  = 32'hffffffe8;
        memory[279]  = 32'h00000061;
        memory[280]  = 32'hffffffcc;
        memory[281]  = 32'hfffffff5;
        memory[282]  = 32'hffffffb3;
        memory[283]  = 32'hffffffa3;
        memory[284]  = 32'hffffffa4;
        memory[285]  = 32'hffffffe8;
        memory[286]  = 32'h00000046;
        memory[287]  = 32'h00000012;
        memory[288]  = 32'h00000038;
        memory[289]  = 32'h00000058;
        memory[290]  = 32'hffffffd5;
        memory[291]  = 32'hffffffd7;
        memory[292]  = 32'hffffffe6;
        memory[293]  = 32'h0000000b;
        memory[294]  = 32'hffffffac;
        memory[295]  = 32'hfffffff2;
        memory[296]  = 32'hffffffd7;
        memory[297]  = 32'h00000053;
        memory[298]  = 32'h0000001b;
        memory[299]  = 32'hfffffff5;
    end

    // 组合逻辑读操作：地址变化立即生效
    always @(*) begin
        if (ce && memRr) begin
            case (r_mask)
                4'b0001: rdData = {24'd0, memory[addr[11:2]][7:0]};   // 读低 8 位
                4'b0011: rdData = {16'd0, memory[addr[11:2]][15:0]};  // 读低 16 位
                default: rdData = memory[addr[11:2]];                 // 读全 32 位
            endcase
        end else begin
            rdData = 32'd0;  // 非读使能时输出 0
        end
    end

    // 同步写操作（需时钟）
    always @(posedge clk) begin
        if (ce && we) begin
            case(w_mask)
                4'b0001: memory[addr[11:2]][7:0]   <= wtData[7:0];    // 写低 8 位
                4'b0011: memory[addr[11:2]][15:0]  <= wtData[15:0];   // 写低 16 位
                default: memory[addr[11:2]]        <= wtData;         // 写全 32 位
            endcase
        end
    end
endmodule
