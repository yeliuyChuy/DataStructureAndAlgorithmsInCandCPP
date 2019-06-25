#include <stdio.h>
#include <stdlib.h>

int main() {

  int myArray[5] = {2, 4, 6, 8, 10};
  int *p;
  int i;

  // dynamic array
  p = (int *)malloc(5 * sizeof(int)); // allocate memory in heap
  p[0] = 1;
  p[1] = 3;
  p[2] = 5;
  p[3] = 7;
  p[4] = 9;

  for (i = 0; i < 5; i++) {
    printf("%d\n", myArray[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("%d\n", p[i]);
  }

  return 0;
}
