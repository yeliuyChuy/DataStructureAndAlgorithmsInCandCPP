#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ArraySize 50

struct Matrix {
  int Array[ArraySize];
  int Size;
};

void Display(struct Matrix m);
void SetDiagonal(struct Matrix *m, int i, int j, int value);
int GetDiagonal(struct Matrix m, int i, int j);
