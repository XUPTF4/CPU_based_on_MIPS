module Led(
    input [31:0] led_data,
    output [15:0] led
);

// 根据 led_data 的最低 16 位来控制亮灭
assign led = led_data[15:0];
endmodule