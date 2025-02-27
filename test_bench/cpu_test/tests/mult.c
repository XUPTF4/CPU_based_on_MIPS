#include <trap.h>
int main() {
    // 测试 MIPS 中的 mult 指令、multu 指令、div 指令、divu 指令 、mfhi 指令、mflo 指令、mtlo 指令 和 mthi 指令
    int a = 0x11111111;
    int b = 0x22222222;
    int c = 0x2;

    check(a * b == 0x24691358);
    check(a * c == 0x22222222);
    check(a / c == 0x08888888);
    check(a % c == 0x1);
    check(a / b == 0x0);
    check(a % b == 0x11111111);

    return 0;
}