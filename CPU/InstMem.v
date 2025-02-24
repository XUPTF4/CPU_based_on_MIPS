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
        mem[0] = 32'h012a4020;  // add $t0, $t1, $t2
        mem[1] = 32'h02328020;  // add $s0, $s1, $s2
        mem[2] = 32'h012a4022;  // sub $t0, $t1, $t2
        mem[3] = 32'h02328022;  // sub $s0, $s1, $s2
        mem[4] = 32'h012a4024;  // and $t0, $t1, $t2
        mem[5] = 32'h02328024;  // and $s0, $s1, $s2
        mem[6] = 32'h012a4025;  // or $t0, $t1, $t2
        mem[7] = 32'h02328025;  // or $s0, $s1, $s2
        mem[8] = 32'h012a4026;  // xor $t0, $t1, $t2
        mem[9] = 32'h02328026;  // xor $s0, $s1, $s2
        mem[10] = 32'h00004800; // sll $t1, $zero, 0
        mem[11] = 32'h00008800; // sll $s1, $zero, 0
        mem[12] = 32'h00004802; // srl $t1, $zero, 0
        mem[13] = 32'h00008802; // srl $s1, $zero, 0
        mem[14] = 32'h00004803; // sra $t1, $zero, 0
        mem[15] = 32'h00008803; // sra $s1, $zero, 0
        mem[16] = 32'h00200008; // jr $t1
        mem[17] = 32'h00400008; // jr $v0
        mem[18] = 32'h20840001; // addi $a0, $a0, 1
        mem[19] = 32'h20a50002; // addi $a1, $a1, 2
        mem[20] = 32'h30840001; // andi $a0, $a0, 1
        mem[21] = 32'h30a50002; // andi $a1, $a1, 2
        mem[22] = 32'h34840001; // ori $a0, $a0, 1
        mem[23] = 32'h34a50002; // ori $a1, $a1, 2
        mem[24] = 32'h38840001; // xori $a0, $a0, 1
        mem[25] = 32'h38a50002; // xori $a1, $a1, 2
        mem[26] = 32'h8c840010; // lw $a0, 16($a0)
        mem[27] = 32'h8ca50020; // lw $a1, 32($a1)
        mem[28] = 32'hac840010; // sw $a0, 16($a0)
        mem[29] = 32'haca50020; // sw $a1, 32($a1)
        mem[30] = 32'h10840001; // beq $a0, $a0, 1
        mem[31] = 32'h10a50002; // beq $a1, $a1, 2
        mem[32] = 32'h14840001; // bne $a0, $a0, 1
        mem[33] = 32'h14a50002; // bne $a1, $a1, 2
        mem[34] = 32'h3c080001; // lui $t0, 1
        mem[35] = 32'h3c090002; // lui $t1, 2
        mem[36] = 32'h08000004; // j 4
        mem[37] = 32'h08000008; // j 8
        mem[38] = 32'h0c000004; // jal 4
        mem[39] = 32'h0c000008; // jal 8
    end
    assign data = ce ? mem[addr >> 2] : 32'b0;

endmodule
