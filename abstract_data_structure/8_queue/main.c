#include "ADT_queueUsingArray.c"
#include "CircularQueueUsingLinkedList.c"
int main() {

  struct Queue q;
  create(&q, 5);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  dequeue(&q);
  display(q);

  enqueueLL(10);
  enqueueLL(20);
  enqueueLL(30);
  enqueueLL(40);
  dequeueLL();
  displayLL();
  return 0;
}
