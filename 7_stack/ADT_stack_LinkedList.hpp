#include <iostream>

class Node { // linkedlist node structure
public:
  int data;
  Node *next;
};

class Stack {
private:
  Node *top;

public:
  Stack() { top = NULL; }
  void push(int val);
  int pop();
  void display();
};
