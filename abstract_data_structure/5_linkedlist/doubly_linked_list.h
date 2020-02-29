#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
  struct DoublyNode *Prev;
  int Data;
  struct DoublyNode *Next;
};

struct DoublyNode *CreateDoubly(int array[], int numElement);
void DisplayDoubly(struct DoublyNode *p);
int CountDoubly(struct DoublyNode *p);
void InsertDoubly(struct DoublyNode *p, int index, int value);
struct DoublyNode *DeleteDoubly(struct DoublyNode *p, int index);
struct DoublyNode *ReverseDoubly(struct DoublyNode *p);
