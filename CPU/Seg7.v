// 该模块接受一个字 data，然后将字输出到数码管中

module Seg7(
        input clk,
        input [31:0] data,
        output [7:0] num_scan_select,
        output [7:0] num_seg7
    );
    integer clk_cnt;
    reg clk_400Hz;
    always @(posedge clk)begin
        if(clk_cnt==32'd150000)begin
            clk_cnt <= 32'd0;
            clk_400Hz <= ~clk_400Hz;
        end
        else
            clk_cnt <= clk_cnt + 1'b1;
    end

    reg[7:0] temp_num_scan_select;
    reg[2:0] count;
    reg [3:0] bcd_num;
    always@(posedge clk_400Hz)begin
        case(count)
            3'b000:begin
                temp_num_scan_select = 8'b0111_1111;
                bcd_num = data[31:28];
                count = count +1;
            end
            3'b001:begin
                temp_num_scan_select = 8'b1011_1111;
                bcd_num = data[27:24];
                count = count +1;
            end
            3'b010:begin
                temp_num_scan_select = 8'b1101_1111;
                bcd_num = data[23:20];
                count = count +1;
            end
            3'b011:begin
                temp_num_scan_select = 8'b1110_1111;
                bcd_num = data[19:16];
                count = count +1;
            end
            3'b100:begin
                temp_num_scan_select = 8'b1111_0111;
                bcd_num = data[15:12];
                count = count +1;
            end
            3'b101:begin
                temp_num_scan_select = 8'b1111_1011;
                bcd_num = data[11:8];
                count = count +1;
            end
            3'b110:begin
                temp_num_scan_select = 8'b1111_1101;
                bcd_num = data[7:4];
                count = count +1;
            end
            3'b111:begin
                temp_num_scan_select = 8'b1111_1110;
                bcd_num = data[3:0];
                count = count +1;
            end
            default:begin
                count = 3'b0;
                bcd_num = 4'b1111;
                temp_num_scan_select = 8'b1111_1111;
            end
        endcase
    end
    assign num_scan_select = temp_num_scan_select;
    assign num_seg7 =
           {bcd_num == 4'b0000}?8'b01111110 ://0
           {bcd_num == 4'b0001}?8'b00110000 ://1
           {bcd_num == 4'b0010}?8'b01101101 ://2
           {bcd_num == 4'b0011}?8'b01111001 ://3
           {bcd_num == 4'b0100}?8'b00110011 ://4
           {bcd_num == 4'b0101}?8'b01011011 ://5
           {bcd_num == 4'b0110}?8'b01011111 ://6
           {bcd_num == 4'b0111}?8'b01110000 ://7
           {bcd_num == 4'b1000}?8'b0111_1111 ://8
           {bcd_num == 4'b1001}?8'b01111011 ://9
           {bcd_num == 4'b1010}?8'b01110111 ://10-A
           {bcd_num == 4'b1011}?8'b00011111 ://11-b
           {bcd_num == 4'b1100}?8'b01001110 ://12-C
           {bcd_num == 4'b1101}?8'b00111101 ://13-d
           {bcd_num == 4'b1110}?8'b01001111 ://14-E
           {bcd_num == 4'b1111}?8'b01000111 ://15-F
           8'b1111_1111;

endmodule
