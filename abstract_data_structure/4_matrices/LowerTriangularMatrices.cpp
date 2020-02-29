#include <iostream>

using namespace std;

class LowerTriangular {
private:
  int *Array;
  int Size;

public:
  LowerTriangular();
  LowerTriangular(int size);
  void SetTriangular(int row, int col, int value);
  int GetTriangular(int row, int col);
  void Display();
  ~LowerTriangular();
};

LowerTriangular::LowerTriangular() {
  Size = 3;
  Array = new int[Size * (Size + 1) / 2];
}

LowerTriangular::LowerTriangular(int size) {
  this->Size = size;
  Array = new int[Size * (Size + 1) / 2];
}

void LowerTriangular::SetTriangular(int row, int col, int value) {
  if (row >= col) {
    Array[row * (row - 1) / 2 + col - 1] = value;
  }
}

int LowerTriangular::GetTriangular(int row, int col) {
  if (row >= col) {
    return Array[row * (row - 1) / 2 + col - 1];
  } else {
    return 0;
  }
}

void LowerTriangular::Display() {
  for (int row = 1; row <= Size; row++) {
    for (int col = 1; col <= Size; col++) {
      if (row >= col) {
        cout << Array[row * (row - 1) / 2 + col - 1] << " ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

LowerTriangular::~LowerTriangular() { delete[] Array; }

int main() {
  int dimension;
  cout << "Enter Dimensions";
  cin >> dimension;

  LowerTriangular lowerTriangular(dimension);

  int x;
  cout << "Enter all elements";
  for (int i = 1; i <= dimension; i++) {
    for (int j = 1; j <= dimension; j++) {
      cin >> x;
      lowerTriangular.SetTriangular(i, j, x);
    }
  }

  lowerTriangular.Display();
  return 0;
}
