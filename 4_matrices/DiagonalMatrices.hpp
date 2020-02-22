#include <iostream>

using namespace std;

class Diagonal {
private:
  int Size;
  int *Array;

public:
  Diagonal();
  Diagonal(int size);
  void SetDiagonal(int row, int col, int value);
  int GetDiagonal(int row, int col);
  void Display();
  ~Diagonal();
};
