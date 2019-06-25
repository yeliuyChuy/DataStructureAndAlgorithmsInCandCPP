// Three ways for creating 2-D array

#include <stdio.h>
#include <stdlib.h>

int main() {

  // method 1. everything in stack
  int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // method.2 Partially in heap
  int *B[3];
  for (int i = 0; i < 3; i++) {
    B[i] = (int *)malloc(4 * sizeof(int));
  }

  // method.3 everything in heap
  int **C;
  C = (int **)malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    C[i] = (int *)malloc(4 * sizeof(int));
  }

  // print to test
  for (int m = 0; m < 3; m++) {
    for (int n = 0; n < 4; n++) {
      printf("%d\n", C[m][n]);
    }
  }
  return 0;
}
