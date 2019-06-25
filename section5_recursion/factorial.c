#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return factorial(n - 1) * n;
}

int main() {

  int num = 5;
  int result = factorial(num);
  printf("%d\n", result);
  return 0;
}
