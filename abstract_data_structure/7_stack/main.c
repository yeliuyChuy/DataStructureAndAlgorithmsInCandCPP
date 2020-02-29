#include "ADT_stack.c"

int main() {
  struct Stack st;

  create(&st);
  printf("=================\n");
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  push(&st, 50);

  display(st);
  printf("Pop value: %d\n", pop(&st));
  printf("=================\n");
  display(st);

  return 0;
}
