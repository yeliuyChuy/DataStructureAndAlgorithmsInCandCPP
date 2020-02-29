#include "ADT_queueUsingArray.h"

void create(struct Queue *q, int size) {
  q->size = size;
  q->front = q->rear = -1; // null
  q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int val) {
  // check if queue is full
  if (q->rear == q->size - 1) {
    printf("Queue is Full\n");
  } else {
    q->rear++;
    q->Q[q->rear] = val;
  }
}

int dequeue(struct Queue *q) {
  int val = -1;
  // check if queue is empty
  if (q->front == q->rear) {
    printf("Queue is empty\n");
  } else {
    q->front++;
    val = q->Q[q->front];
  }
  return val;
}

void display(struct Queue q) {
  for (int i = q.front + 1; i <= q.rear; i++) {
    printf("%d\n", q.Q[i]);
  }
}
