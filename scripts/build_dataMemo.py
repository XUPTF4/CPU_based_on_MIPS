import argparse

def hex_to_data_mem_verilog(hex_filepath, verilog_filepath):
    """
    Converts a hex file (.hex) to a Verilog data memory module initialization file (.v).
    Removes spaces from hex literals to ensure correct Verilog syntax.

    Args:
        hex_filepath (str): Path to the input hex file.
        verilog_filepath (str): Path to the output Verilog file.
    """

    mem_init_lines = []
    address = 0

    try:
        with open(hex_filepath, 'r') as hex_file:
            for line in hex_file:
                line = line.strip()
                if line and not line.startswith('//'):  # Ignore empty lines and comments
                    # Remove spaces from the hex line before creating Verilog literal
                    hex_value_no_spaces = line.replace(" ", "")
                    verilog_hex_literal = f"        memory[{address}]  = 32'h{hex_value_no_spaces};" # Modified for DataMem memory name
                    mem_init_lines.append(verilog_hex_literal)
                    address += 1

    except FileNotFoundError:
        print(f"Error: Input hex file '{hex_filepath}' not found.")
        return

    with open(verilog_filepath, 'w') as verilog_file:
        verilog_file.write("module DataMem(\n")
        verilog_file.write("    input clk,\n")
        verilog_file.write("    input ce,\n")
        verilog_file.write("    input we,\n")
        verilog_file.write("    input [31:0] wtData,\n")
        verilog_file.write("    input [31:0] addr,\n")
        verilog_file.write("    input memRr,                // 内存读使能\n")
        verilog_file.write("    input [3:0] w_mask,         // 写掩码\n")
        verilog_file.write("    input [3:0] r_mask,         // 读掩码\n")
        verilog_file.write("    output reg [31:0] rdData,    // 组合逻辑直接输出\n")
        verilog_file.write("    output [31:0] seg7      // 数码管显示输出\n")
        verilog_file.write(");\n")
        verilog_file.write("    reg [31:0] memory [0:1023]; // 4KB 内存\n")
        verilog_file.write("// 初始化 memory\n\n")
        verilog_file.write("    initial begin\n")
        for init_line in mem_init_lines:
            verilog_file.write(f"{init_line}\n")
        verilog_file.write("    end\n\n")
        verilog_file.write("    // 组合逻辑读操作：地址变化立即生效\n")
        verilog_file.write("    assign seg7 = memory[1023]; // 直接输出\n")
        verilog_file.write("    always @(*) begin\n")
        verilog_file.write("        if (ce && memRr) begin\n")
        verilog_file.write("            case (r_mask)\n")
        verilog_file.write("                4'b0001: rdData = {24'd0, memory[addr[11:2]][7:0]};   // 读低 8 位\n")
        verilog_file.write("                4'b0011: rdData = {16'd0, memory[addr[11:2]][15:0]};  // 读低 16 位\n")
        verilog_file.write("                default: rdData = memory[addr[11:2]];                 // 读全 32 位\n")
        verilog_file.write("            endcase\n")
        verilog_file.write("        end else begin\n")
        verilog_file.write("            rdData = 32'd0;  // 非读使能时输出 0\n")
        verilog_file.write("        end\n")
        verilog_file.write("    end\n\n")
        verilog_file.write("    // 同步写操作（需时钟）\n")
        verilog_file.write("    always @(posedge clk) begin\n")
        verilog_file.write("        if (ce && we) begin\n")
        verilog_file.write("            case(w_mask)\n")
        verilog_file.write("                4'b0001: memory[addr[11:2]][7:0]   <= wtData[7:0];    // 写低 8 位\n")
        verilog_file.write("                4'b0011: memory[addr[11:2]][15:0]  <= wtData[15:0];   // 写低 16 位\n")
        verilog_file.write("                default: memory[addr[11:2]]        <= wtData;         // 写全 32 位\n")
        verilog_file.write("            endcase\n")
        verilog_file.write("        end\n")
        verilog_file.write("    end\n")
        verilog_file.write("endmodule\n")

    print(f"Successfully converted '{hex_filepath}' to '{verilog_filepath}'")

def main():
    # 使用 argparse 来解析命令行参数
    parser = argparse.ArgumentParser(description="Convert HEX file to Verilog data memory module")
    parser.add_argument("input_hex_file", help="Path to the input HEX file")
    parser.add_argument("output_verilog_file", help="Path to the output Verilog file")

    # 解析命令行参数
    args = parser.parse_args()

    # 调用函数
    hex_to_data_mem_verilog(args.input_hex_file, args.output_verilog_file)

if __name__ == "__main__":
    main()