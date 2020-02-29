#include "DiagonalMatrices.hpp"

Diagonal::Diagonal() {
  Size = 5;
  Array = new int[Size];
}

Diagonal::Diagonal(int size) {
  this->Size = size;
  Array = new int[Size];
}

void Diagonal::SetDiagonal(int row, int col, int value) {
  if (row == col) {
    Array[row - 1] = value;
  }
}
int Diagonal::GetDiagonal(int row, int col) {
  if (row == col) {
    return Array[row - 1];
  } else {
    return 0;
  }
}
void Diagonal::Display() {
  for (int i = 0; i < Size; i++) {
    for (int j = 0; j < Size; j++) {
      if (i == j) {
        cout << Array[i] << " ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

Diagonal::~Diagonal() { delete[] Array; }
