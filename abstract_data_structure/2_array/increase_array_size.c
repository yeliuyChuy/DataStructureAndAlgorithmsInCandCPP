#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p, *q;
  int i;

  p = (int *)malloc(5 * sizeof(int));
  p[0] = 1;
  p[1] = 3;
  p[2] = 5;
  p[3] = 7;
  p[4] = 9;

  // assign q with larger memory
  q = (int *)malloc(10 * sizeof(int));

  // cope the elements from p to q
  for (i = 0; i < 5; i++) {
    q[i] = p[i];
  }

  // free the memory that p points to
  free(p);

  // let the p point to new memory
  p = q;

  // make q as null
  q = NULL;

  for (i = 0; i < 5; i++) {
    printf("%d\n", p[i]);
  }
  return 0;
}
