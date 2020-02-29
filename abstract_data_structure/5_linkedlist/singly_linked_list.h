#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int Data;
  struct Node *Next;
};

struct Node *Create(int Array[], int NumElement);
void Display(struct Node *p);
void RecursiveDisplay(struct Node *p);
int Count(struct Node *p);
int RecursiveCount(struct Node *p);
int Sum(struct Node *p);
int FindMax(struct Node *p);
int RecursiveFindMax(struct Node *p);
struct Node *LinearSearch(struct Node *p, int key);
struct Node *RecursiveLinearSearch(struct Node *p, int key);
void Insert(struct Node *p, int index, int value);
struct Node *Delete(struct Node *p, int index);
bool IsSorted(struct Node *p);
void ReverseByArray(struct Node *p);
struct Node *ReverseBySlidePointer(struct Node *p);
void ReverseByRecursion(struct Node *pNew, struct Node *pOrigin);
struct Node *Concate(struct Node *list1, struct Node *list2);
struct Node *Merge(struct Node *list1, struct Node *list2);
bool isLooped(struct Node *list);
