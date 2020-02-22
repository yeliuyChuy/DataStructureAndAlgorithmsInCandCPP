#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// implementation of stack using array
struct Stack {
  // a pointer in the form of index to point to top most element in the stack
  int top;
  int size; // size of stack
  int *S;   // array for storing element
};

void create(struct Stack *p_stack); // creating a stack
void display(struct Stack p_stack);
void push(struct Stack *p_stack, int val);
int pop(struct Stack *p_stack);
bool isEmpty(struct Stack p_stack);
bool isFull(struct Stack p_stack);
