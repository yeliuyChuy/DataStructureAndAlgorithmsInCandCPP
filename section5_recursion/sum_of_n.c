#include <stdio.h>

// recusrsive
int sum(int n) {

  if (n == 0) {
    return 0;
  }
  return sum(n - 1) + n;
}

// iterative
int iterative_sum(int n) {
  int s = 0;
  for (int i = 0; i <= n; i++) {
    s = s + i;
  }
  return s;
}

int main() {

  int result;
  result = iterative_sum(5);
  printf("%d\n", result);
  return 0;
}
