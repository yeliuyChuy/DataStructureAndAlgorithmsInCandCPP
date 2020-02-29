#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(int Row, int Col, int NumNonZero) {
  this->Row = Row;
  this->Col = Col;
  this->NumNonZero = NumNonZero;
  ele = new NonZeroElement[this->NumNonZero];
}

// destructor
SparseMatrix::~SparseMatrix() { delete[] ele; }

SparseMatrix SparseMatrix::operator+(SparseMatrix &s) {
  int i, j, k;
  i = j = k = 0;

  // check Dimension
  if (Row != s.Row || Col != s.Col) {
    return SparseMatrix(0, 0, 0);
  }
  SparseMatrix *sum = new SparseMatrix(Row, Col, NumNonZero + s.NumNonZero);
  while (i < NumNonZero && j < s.NumNonZero) {
    // compare row index first
    if (ele[i].RowLoc < s.ele[j].RowLoc) {
      // smaller first
      sum->ele[k++] = ele[i++];
    } else if (ele[i].RowLoc > s.ele[j].RowLoc) {
      sum->ele[k++] = s.ele[j++];
    } else {
      // else row index is same, compare column index
      if (ele[i].ColLoc < s.ele[j].ColLoc) {
        sum->ele[k++] = ele[i++];
      } else if (ele[i].ColLoc > s.ele[j].ColLoc) {
        sum->ele[k++] = s.ele[j++];
      } else {
        // applying addition
        sum->ele[k] = ele[i];
        sum->ele[k++].Value = ele[i++].Value + s.ele[j++].Value;
      }
    }
  }
  // run out of both elements in s1 and s2:
  for (; i < NumNonZero; i++) {
    sum->ele[k++] = ele[i++];
  }
  for (; j < s.NumNonZero; j++) {
    sum->ele[k++] = s.ele[j++];
  }

  sum->NumNonZero = k;
  return *sum;
}

istream &operator>>(istream &is, SparseMatrix &s) {
  cout << "Enter Non-zero elements:(row,col,value)";
  for (int i = 0; i < s.NumNonZero; i++) {
    cin >> s.ele[i].RowLoc >> s.ele[i].ColLoc >> s.ele[i].Value;
  }
  return is;
}

ostream &operator<<(ostream &os, SparseMatrix &s) {
  int k = 0;
  for (int i = 0; i < s.Row; i++) {
    for (int j = 0; j < s.Col; j++) {
      if (s.ele[k].RowLoc == i && s.ele[k].ColLoc == j) {
        cout << s.ele[k++].Value << " ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }
  return os;
}
