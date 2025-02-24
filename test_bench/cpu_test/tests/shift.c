#include <trap.h>
int s[10] = {0};
int main() {
    int a = 4;
    int b = a << 1;
    int c = a >> 2;

    check(b == 8);
    check(c == 1);
    return 0;
}