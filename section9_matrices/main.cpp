#include "DiagonalMatrices.hpp"

int main() {
  Diagonal testMatrix(4);

  testMatrix.SetDiagonal(1, 1, 3);
  testMatrix.SetDiagonal(2, 2, 5);
  testMatrix.SetDiagonal(3, 3, 7);
  testMatrix.SetDiagonal(4, 4, 9);

  testMatrix.Display();
  return 0;
}
