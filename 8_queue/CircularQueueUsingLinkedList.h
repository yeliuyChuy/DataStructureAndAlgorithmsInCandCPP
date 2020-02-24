#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void enqueueLL(int val);
int dequeueLL();
void displayLL();
