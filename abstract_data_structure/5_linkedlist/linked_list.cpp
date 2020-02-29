#include "linked_list.hpp"
#include <iostream>

using namespace std;

LinkedList::LinkedList() { First = NULL; }
LinkedList::LinkedList(int array[], int size) {
  Node *last, *temp;

  First = new Node;
  First->Data = array[0];
  First->Next = NULL;
  last = First;

  for (int i = 1; i < size; i++) {
    temp = new Node;
    temp->Data = array[i];
    temp->Next = NULL;
    last->Next = temp;
    last = temp;
  }
}

LinkedList::~LinkedList() {
  Node *p = First;
  while (First) {
    First = First->Next;
    delete p;
    p = First;
  }
}

void LinkedList::Display() {
  Node *p = First;
  while (p) {
    cout << p->Data << " ";
    p = p->Next;
  }
  cout << endl;
}

void LinkedList::Insert(int index, int value) {
  if (index < 0 || index > Length()) {
    return;
  }
  Node *temp, *p = First;
  temp = new Node;
  temp->Data = value;
  temp->Next = NULL;

  if (index == 0) {
    temp->Next = First;
    First = temp;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->Next;
    }
    temp->Next = p->Next;
    p->Next = temp;
  }
}

void LinkedList::Delete(int index) {
  if (index < 0 || index > Length()) {
    return;
  }

  Node *p, *q = NULL;
  if (index == 0) {
    p = First;
    First = First->Next;
    delete p;
  } else {
    p = First;
    for (int i = 0; i < index - 1; i++) {
      q = p;
      p = p->Next;
    }
    q->Next = p->Next;
    delete p;
  }
}
int LinkedList::Length() {
  Node *p = First;
  int len = 0;
  while (p) {
    len++;
    p = p->Next;
  }
  return len;
}
