#include <trap.h>
// 测试 I 型指令
int main() {
    int a = 50;
    int b = 49;
    int c = 0;
    int d = 10;
    if (a > b) {
        c = 1;
    }
    check(c == 1);

    if (d < a) {
        c = 0;
    }
    check(c == 0);

    return 0;
}