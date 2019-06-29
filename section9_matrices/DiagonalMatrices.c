#include "DiagonalMatrices.h"

void Display(struct Matrix m) {
  for (int i = 0; i < m.Size; i++) {
    for (int j = 0; j < m.Size; j++) {
      if (i == j) {
        printf("%d ", m.Array[i]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void SetDiagonal(struct Matrix *m, int i, int j, int value) {
  if (i == j) {
    m->Array[i - 1] = value;
  }
}

int GetDiagonal(struct Matrix m, int i, int j) {
  if (i == j) {
    return m.Array[i - 1];
  } else {
    return 0;
  };
}
