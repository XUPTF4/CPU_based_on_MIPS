import argparse

def hex_to_verilog_mem(hex_filepath, verilog_filepath):
    """
    Converts a hex file (.hex) to a Verilog memory initialization file (.v).
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
                    verilog_hex_literal = f"mem[{address}]  = 32'h{hex_value_no_spaces};"
                    mem_init_lines.append(verilog_hex_literal)
                    address += 1

    except FileNotFoundError:
        print(f"Error: Input hex file '{hex_filepath}' not found.")
        return

    with open(verilog_filepath, 'w') as verilog_file:
        verilog_file.write("module InstMem(\n")
        verilog_file.write("        input         ce,\n")
        verilog_file.write("        input  [31:0] addr,\n")
        verilog_file.write("        output  [31:0] data\n")
        verilog_file.write("    );\n\n")
        verilog_file.write("    reg [31:0] mem [0:1023]; // 4KB\n\n") # You can adjust memory size if needed
        verilog_file.write("    initial begin\n")
        for init_line in mem_init_lines:
            verilog_file.write(f"        {init_line}\n")
        verilog_file.write("    end\n")
        verilog_file.write("    assign data = ce ? mem[addr >> 2] : 32'b0;\n\n")
        verilog_file.write("endmodule\n")

    print(f"Successfully converted '{hex_filepath}' to '{verilog_filepath}'")

def main():
    # 使用 argparse 来解析命令行参数
    parser = argparse.ArgumentParser(description="Convert HEX file to Verilog memory module")
    parser.add_argument("input_hex_file", help="Path to the input HEX file")
    parser.add_argument("output_verilog_file", help="Path to the output Verilog file")

    # 解析命令行参数
    args = parser.parse_args()

    # 调用函数
    hex_to_verilog_mem(args.input_hex_file, args.output_verilog_file)

if __name__ == "__main__":
    main()
