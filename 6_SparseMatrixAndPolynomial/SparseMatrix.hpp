#include <iostream>

using namespace std;

class NonZeroElement {
public:
  int RowLoc;
  int ColLoc;
  int Value;
};

class SparseMatrix {
private:
  int Row;
  int Col;
  int NumNonZero;
  NonZeroElement *ele;

public:
  SparseMatrix(int Row, int Col, int NumNonZero);
  // destructor
  ~SparseMatrix();
  void Read();
  void Display();
  SparseMatrix operator+(SparseMatrix &s);

  friend istream &operator>>(istream &is, SparseMatrix &s);

  friend ostream &operator<<(ostream &os, SparseMatrix &s);
};
