#include "ADT_stack_LinkedList.hpp"

void Stack::push(int val) {
  Node *p_stack = new Node;
  if (p_stack == NULL) {
    std::cout << "Stack is Full" << '\n';
  } else {
    p_stack->data = val;
    p_stack->next = top;
    top = p_stack;
  }
}

int Stack::pop() {
  int val = -1;
  if (top == NULL) {
    std::cout << "Stack is Empty" << '\n';
  } else {
    val = top->data;
    Node *tmp = top;
    top = top->next;
    delete tmp;
  }
  return val;
}

void Stack::display() {
  Node *p_stack = top;
  while (p_stack != NULL) {
    std::cout << p_stack->data << " ";
    p_stack = p_stack->next;
  }
  std::cout << std::endl;
}
