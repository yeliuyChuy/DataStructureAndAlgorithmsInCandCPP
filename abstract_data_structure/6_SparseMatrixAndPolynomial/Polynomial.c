#include <stdio.h>
#include <stdlib.h>

struct Term {
  int coef;
  int exp;
};

struct Poly {
  int Size;
  struct Term *terms;
};

void Create(struct Poly *p) {
  printf("Enter the number of terms in polynomial");
  scanf("%d", &p->Size);
  // allocate memory
  p->terms = (struct Term *)malloc(p->Size * sizeof(struct Term));

  printf("Enter the exponent and coefficient for each term\n");
  for (int i = 0; i < p->Size; i++) {
    scanf("%d%d", &p->terms[i].exp, &p->terms[i].coef);
  }
}

void Display(struct Poly p) {
  for (int i = 0; i < p.Size; i++) {
    printf("%d * X^%d + ", p.terms[i].coef, p.terms[i].exp);
  }
  printf("\n");
}

struct Poly *Add(struct Poly *p1, struct Poly *p2) {
  int i, j, k;
  i = j = k = 0;
  struct Poly *sum;

  sum = (struct Poly *)malloc(sizeof(struct Poly));
  sum->terms =
      (struct Term *)malloc((p1->Size + p2->Size) * sizeof(struct Term));

  while (i < p1->Size && j < p2->Size) {
    if (p1->terms[i].exp < p2->terms[j].exp) {
      sum->terms[k++] = p2->terms[j++];
    } else if (p1->terms[i].exp > p2->terms[j].exp) {
      sum->terms[k++] = p1->terms[i++];
    } else {
      sum->terms[k].exp = p1->terms[i].exp;
      sum->terms[k++].coef = p1->terms[i++].coef + p2->terms[j++].coef;
    }
  }
  for (; i < p1->Size; i++) {
    sum->terms[k++] = p1->terms[i++];
  }
  for (; j < p2->Size; j++) {
    sum->terms[k++] = p2->terms[j++];
  }

  sum->Size = k;
  return sum;
}

int main() {
  struct Poly p1, p2, *p3;
  Create(&p1);
  Create(&p2);

  p3 = Add(&p1, &p2);
  printf("\n");
  Display(p1);
  printf("\n");
  Display(p2);
  printf("\n");
  Display(*p3);

  return 0;
}
