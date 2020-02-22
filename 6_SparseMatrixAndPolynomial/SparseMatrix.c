#include "SparseMatrix.h"

void Create(struct Sparse *s) {
  printf("Enter Dimension:");
  scanf("%d%d", &s->Row, &s->Col);
  printf("Enter Number of non zero elements");
  scanf("%d", &s->NumNonZero);

  s->ele = (struct NonZeroElement *)malloc(s->NumNonZero *
                                           sizeof(struct NonZeroElement));
  printf("Please enter the detail of each non zero element");
  for (int i = 0; i < s->NumNonZero; i++) {
    scanf("%d%d%d", &s->ele[i].RowLoc, &s->ele[i].ColLoc, &s->ele[i].Value);
  }
}
void Display(struct Sparse s) {
  int k = 0;
  for (int i = 0; i < s.Row; i++) {
    for (int j = 0; j < s.Col; j++) {
      if (i == s.ele[k].RowLoc && j == s.ele[k].ColLoc) {
        printf("%d ", s.ele[k++].Value);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2) {
  struct Sparse *sum;

  sum = (struct Sparse *)malloc(sizeof(struct Sparse));
  sum->ele = (struct NonZeroElement *)malloc(sizeof(struct NonZeroElement) *
                                             (s1->NumNonZero + s2->NumNonZero));

  int i, j, k;
  i = j = k = 0;
  if (s1->Col != s2->Col && s1->Row != s2->Row)
    return NULL; // dimension checking
  while (i < s1->NumNonZero && j < s2->NumNonZero) {
    // compare row index first
    if (s1->ele[i].RowLoc < s2->ele[j].RowLoc) {
      // smaller first
      sum->ele[k++] = s1->ele[i++];
    } else if (s1->ele[i].RowLoc > s2->ele[j].RowLoc) {
      sum->ele[k++] = s2->ele[j++];
    } else {
      // else row index is same, compare column index
      if (s1->ele[i].ColLoc < s2->ele[j].ColLoc) {
        sum->ele[k++] = s1->ele[i++];
      } else if (s1->ele[i].ColLoc > s2->ele[j].ColLoc) {
        sum->ele[k++] = s2->ele[j++];
      } else {
        // applying addition
        sum->ele[k] = s1->ele[i];
        sum->ele[k++].Value = s1->ele[i++].Value + s2->ele[j++].Value;
      }
    }
  }
  // run out of both elements in s1 and s2:
  for (; i < s1->NumNonZero; i++) {
    sum->ele[k++] = s1->ele[i++];
  }
  for (; j < s2->NumNonZero; j++) {
    sum->ele[k++] = s2->ele[j++];
  }

  // perfect the sum struct
  sum->Row = s1->Row;
  sum->Col = s1->Col;
  sum->NumNonZero = k;

  return sum;
}
