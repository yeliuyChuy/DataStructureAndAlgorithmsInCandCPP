#include "LowerTriangularMatrices.h"

int main() {
  struct Matrix testMatrix;
  // testMatrix.Size = 4;

  // SetDiagonal(&testMatrix, 1, 1, 3);
  // SetDiagonal(&testMatrix, 2, 2, 5);
  // SetDiagonal(&testMatrix, 3, 3, 7);
  // SetDiagonal(&testMatrix, 4, 4, 9);

  // Display(testMatrix);
  // printf("%d\n", GetDiagonal(testMatrix, 4, 4));

  //======================================
  int x;

  printf("Enter Dimsension: ");
  scanf("%d", &testMatrix.Size);

  testMatrix.Array =
      (int *)malloc(testMatrix.Size * (testMatrix.Size - 1) / 2 * sizeof(int));
  printf("Enter All Elements");
  for (int i = 1; i <= testMatrix.Size; i++) {
    for (int j = 1; j <= testMatrix.Size; j++) {
      scanf("%d", &x);
      SetTriangular(&testMatrix, i, j, x);
    }
  }
  printf("\n\n");
  Display(testMatrix);
  return 0;
}
