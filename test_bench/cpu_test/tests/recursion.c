#include <trap.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int n = 5;
  int expected_factorial = 120; // 5! = 120
  int actual_factorial = factorial(n);

  check(actual_factorial == expected_factorial); // Check factorial result
  return 0;
}