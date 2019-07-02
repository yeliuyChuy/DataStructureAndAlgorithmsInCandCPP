#include "SparseMatrix.hpp"
using namespace std;

int main() {
  SparseMatrix s1(5, 5, 5);
  SparseMatrix s2(5, 5, 5);

  cin >> s1;
  cin >> s2;

  SparseMatrix sum = s1 + s2;
  cout << "First Matrix" << endl << s1;
  cout << "Second Matrix" << endl << s2;
  cout << "Sum Matrix" << endl << sum;
  return 0;
}
