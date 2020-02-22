#include <stdio.h>
#include <stdlib.h>

struct NonZeroElement {
  int RowLoc;
  int ColLoc;
  int Value;
};

struct Sparse {
  int Row;
  int Col;
  int NumNonZero;
  struct NonZeroElement *ele;
};

void Create(struct Sparse *s);
void Display(struct Sparse s);
struct Sparse *Add(struct Sparse *s1, struct Sparse *s2);
