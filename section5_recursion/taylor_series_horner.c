#include <stdio.h>

double taylor_series_horner(int x, int n) {
  static double s = 1;

  if (n == 0) {
    return s;
  }
  s = 1 + s * x / n;
  return taylor_series_horner(x, n - 1);
}

int main() {
  printf("%lf\n", taylor_series_horner(1, 10));
  return 0;
}
