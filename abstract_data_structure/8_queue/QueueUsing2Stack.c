#include "QueueUsing2Stack.h"

struct Stack S1, S2;

void enqueueSTK(int val) { push(&S1, val); }
int dequeueSTK() {
  int val = -1;
  if (isEmpty(S2)) {
    if (isEmpty(S1)) {
      printf("Queue is Empty\n");
      return val;
    } else {
      // transfer s1 to s2
      while (!isEmpty(S1)) {
        push(&S2, pop(&S1));
      }
    }
  }
  return pop(&S2);
}
