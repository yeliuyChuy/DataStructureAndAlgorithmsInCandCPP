#include <stdio.h>

double talyor_series(int x, int n) {
  static double p = 1, f = 1;
  double result;
  if (n == 0) {
    return 1;
  }
  result = talyor_series(x, n - 1);
  p = p * x;
  f = f * n;
  return result + p / f;
}

int main() {
  printf("%lf \n", talyor_series(3, 10));
  return 0;
}
