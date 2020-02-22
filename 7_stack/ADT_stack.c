#include "ADT_stack.h"

void create(struct Stack *p_stack) {

  printf("Enter the size of stack:");
  scanf("%d", &p_stack->size);

  p_stack->top = -1; // using idx -1 represent null
  p_stack->S = (int *)malloc(p_stack->size * sizeof(int));
}

void display(struct Stack p_stack) {
  for (int i = p_stack.top; i >= 0; i--) {
    printf("%d\n", p_stack.S[i]);
  }
  printf("\n");
}

void push(struct Stack *p_stack, int val) {
  // check if stack has space or not
  if (p_stack->top == p_stack->size - 1) {
    printf("Stack overflow\n");
  } else {
    // insert new element
    p_stack->top++;                 // increment the top pointer
    p_stack->S[p_stack->top] = val; // save the val in
  }
}

int pop(struct Stack *p_stack) {
  int val = -1;
  // check if elements in the stack first
  if (p_stack->top == -1) {
    printf("Stack Underflow\n");
  } else {
    // get the val and decrement the pointer
    val = p_stack->S[p_stack->top--];
  }
  return val;
}

bool isEmpty(struct Stack p_stack) {
  if (p_stack.top == -1) {
    return true;
  }
  return false;
}

bool isFull(struct Stack p_stack) {
  if (p_stack.top == p_stack.size - 1) {
    return true;
  }
  return false;
}
