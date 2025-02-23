// 这是存放程序的单元，PC 从这里取指，这相当于 ROM，将程序段放到这里
module InstMem(
        input         ce,
        input  [31:0] addr,
        output  [31:0] data
    );

    reg [31:0] mem [0:1023]; // 4KB
    initial begin
        $readmemh("C:/path_to_dummy.hex", mem);
    end

    assign data = ce ? mem[addr] : 32'b0;

endmodule
