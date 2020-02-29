#include "SparseMatrix.h"

int main() {

  struct Sparse s1, s2, *s3;

  Create(&s1);
  Create(&s2);
  printf("Adding...\n");
  s3 = Add(&s1, &s2);
  printf("First Matrix:\n");
  Display(s1);
  printf("Second Matrix:\n");
  Display(s2);
  printf("Summed Matrix:\n");
  Display(*s3);
  return 0;
}
