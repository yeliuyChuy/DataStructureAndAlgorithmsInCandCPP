#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
  int *Array;
  int Size;
};

void Display(struct Matrix m);
void SetTriangular(struct Matrix *m, int i, int j, int value);
int GetTriangular(struct Matrix m, int i, int j);
