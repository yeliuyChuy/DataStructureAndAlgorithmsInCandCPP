#include <stdio.h>

int factorial(int n) {
  if (n == 0)
    return 1;
  return factorial(n - 1) * n;
}

int nCr(int n, int r) {

  int num, denorm;
  num = factorial(n);
  denorm = factorial(r) * factorial(n - r);
  return num / denorm;
}

int NCR(int n, int r) {
  if (n == r || r == 0) {
    return 1;
  }
  return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main() {
  printf("%d\n", NCR(5, 3));
  return 0;
}
