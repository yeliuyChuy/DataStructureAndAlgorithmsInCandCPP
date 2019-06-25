#include <stdio.h>

// void toh(#disk, tower A, tower B, tower C)
void toh(int n, int a, int b, int c) {
  if (n > 0) {
    toh(n - 1, a, c, b);
    printf("(%d, %d)\n", a, c);
    toh(n - 1, b, a, c);
  }
}
int main() {
  toh(3, 1, 2, 3);
  return 0;
}
