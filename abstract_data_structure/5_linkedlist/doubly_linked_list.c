#include "doubly_linked_list.h"

struct DoublyNode *CreateDoubly(int array[], int numElement) {
  struct DoublyNode *first = NULL, *temp, *last;

  first = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
  first->Data = array[0];
  first->Next = first->Prev = NULL;
  last = first;

  for (int i = 1; i < numElement; i++) {
    temp = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
    temp->Data = array[i];
    temp->Next = last->Next;
    temp->Prev = last;
    last->Next = temp;
    last = temp;
  }
  return first;
}

void DisplayDoubly(struct DoublyNode *p) {
  while (p) {
    printf("%d ", p->Data);
    p = p->Next;
  }
  printf("\n");
}

int CountDoubly(struct DoublyNode *p) {
  int len = 0;
  while (p) {
    len++;
    p = p->Next;
  }
  return len;
}

void InsertDoubly(struct DoublyNode *p, int index, int value) {
  // check if the given index is valid first
  if (index < 0 || index > CountDoubly(p)) {
    printf("Invalid given index\n");
    return;
  }
  struct DoublyNode *temp, *first = p;
  if (index == 0) {
    temp = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
    temp->Data = value;
    temp->Next = first;
    temp->Prev = NULL;
    first->Prev = temp;
    first = temp;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->Next;
    }
    temp = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
    temp->Data = value;
    temp->Prev = p;
    temp->Next = p->Next;
    if (p->Next) {
      p->Next->Prev = temp;
    }
    p->Next = temp;
  }
}

struct DoublyNode *DeleteDoubly(struct DoublyNode *p, int index) {
  if (index < 0 || index > CountDoubly(p)) {
    printf("Invalid given index\n");
    return NULL;
  }
  struct DoublyNode *first = p;
  if (index == 0) {
    first = first->Next;
    if (first) {
      first->Prev = NULL;
    }
    free(p);
    return first;
  } else {
    for (int i = 1; i <= index; i++) {
      p = p->Next;
    }
    p->Prev->Next = p->Next;
    if (p->Next) {
      p->Next->Prev = p->Prev;
    }
    free(p);
    return first;
  }
}

struct DoublyNode *ReverseDoubly(struct DoublyNode *p) {
  struct DoublyNode *temp, *first = p;
  while (p != NULL) {
    temp = p->Next;
    p->Next = p->Prev;
    p->Prev = temp;
    p = p->Prev; // move to the next
    if (p != NULL && p->Next == NULL) {
      // if it is the last node
      first = p;
    }
  }
  return first;
}

int main() {

  int testArray1[] = {1, 3, 5, 7, 9};
  int testArray2[] = {2, 4, 6, 8, 10};
  // int testArray3[] = {1, 3, 5, 7, 9};
  struct DoublyNode *firstDoubly = CreateDoubly(testArray2, 5);
  // Insert(first, 3, 333);

  // delete element
  // first = Delete(first, 2);

  // Reverse
  // ReverseByArray(first);
  // ReverseBySlidePointer(first)
  // ReverseByRecursion(NULL, first);

  // display linked list
  // Display(Merge(first, second));
  // InsertCircular(firstCircular, 0, 0);
  // DeleteCircular(firstCircular, 1);
  InsertDoubly(firstDoubly, 3, 333);
  struct DoublyNode *DeletedList = DeleteDoubly(firstDoubly, 0);
  struct DoublyNode *RevertedList = ReverseDoubly(DeletedList);
  DisplayDoubly(RevertedList);

  // check if Sorted
  // if (IsSorted(first)) {
  //  printf("Sorted!\n");
  //} else {
  //  printf("Not Sorted\n");
  //}
  return 0;
}
