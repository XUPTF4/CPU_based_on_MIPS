#include <trap.h>
int main() {
    int a = 0;
    int b = 5;
    int c = 2;
    int d = 3;

    if (b == c + d) {
        a = a + 1;
    }
    check(a == 1);
    if (a != 10) {
        a = a + 5;
    }
    check(a == 6);
    return 0;
}