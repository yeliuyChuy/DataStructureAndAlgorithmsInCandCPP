#include "LowerTriangularMatrices.h"

void Display(struct Matrix m) {
  for (int i = 1; i <= m.Size; i++) {
    for (int j = 1; j <= m.Size; j++) {
      if (i >= j) {
        printf("%d ", m.Array[i * (i - 1) / 2 + j - 1]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void SetTriangular(struct Matrix *m, int i, int j, int value) {
  if (i >= j) {
    m->Array[i * (i - 1) / 2 + j - 1] = value;
  }
}

int GetTriangular(struct Matrix m, int i, int j) {
  if (i >= j) {
    return m.Array[i * (i - 1) / 2 + j - 1];
  } else {
    return 0;
  }
}
