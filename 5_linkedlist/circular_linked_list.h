#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int Data;
  struct Node *Next;
};

struct Node *CreateCircular(int array[], int numElement);
void DisplayCircular(struct Node *h);
int CountCircular(struct Node *p);
void InsertCircular(struct Node *p, int index, int value);
void DeleteCircular(struct Node *p, int index);
