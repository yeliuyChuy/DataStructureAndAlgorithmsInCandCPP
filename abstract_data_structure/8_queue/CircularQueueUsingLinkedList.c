#include "CircularQueueUsingLinkedList.h"

void enqueueLL(int val) {
  struct Node *tmp;
  tmp = (struct Node *)malloc(sizeof(struct Node));

  if (tmp == NULL) {
    printf("Queue is Full\n");
  } else {
    tmp->data = val;
    tmp->next = NULL;
    // if it is the first inserted element:
    if (front == NULL) {
      front = rear = tmp;
    } else {
      rear->next = tmp;
      rear = tmp;
    }
  }
}

int dequeueLL() {
  int val = -1;
  struct Node *tmp;

  if (front == NULL) {
    printf("Queue is Empty\n");
  } else {
    val = front->data;
    tmp = front;
    front = front->next;
    free(tmp);
  }
  return val;
}

void displayLL() {
  struct Node *p = front;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
}
