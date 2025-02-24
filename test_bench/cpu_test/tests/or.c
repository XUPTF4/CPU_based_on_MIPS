#include <trap.h>
int main() {
    int a = 5;
    int b = 0;
    int c = a | b;
    int d = a ^ b;
    int e = a & b;

    check(c == 5);
    check(d = 5);
    check(e == 0);
    return 0;
}