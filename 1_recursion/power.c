#include <stdio.h>

int factorial(int m, int n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return factorial(m * m, n / 2);
  } else {
    return m * factorial(m * m, (n - 1) / 2);
  }
}

int main() {
  printf("%d\n", factorial(9, 3));
  return 0;
}
