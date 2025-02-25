#include <trap.h>
int aa() {
    check(1);
    return 0;
}
int main() {
    int a = 1;
    if (a == 1) {
        aa();
    }
    return 0;
}