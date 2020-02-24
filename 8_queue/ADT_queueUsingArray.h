#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int front; // pointer
  int rear;  // pointer
  int *Q;
};

struct Stack {
  // a pointer in the form of index to point to top most element in the stack
  int top;
  int size; // size of stack
  int *S;   // array for storing element
};

void create(struct Queue *q, int size);
void enqueue(struct Queue *q, int val);
int dequeue(struct Queue *q);
void display(struct Queue q);
