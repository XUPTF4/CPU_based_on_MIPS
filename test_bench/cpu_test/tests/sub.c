#include <trap.h>
int main() {
    int a = 10;
    int b = 5;
    int c = a - b;

    check(c == 5);
    return 0;
}