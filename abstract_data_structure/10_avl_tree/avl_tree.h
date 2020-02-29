#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *lChild;
  int data;
  int height;
  struct Node *rChild;
} *root = NULL;

struct Node *RecursiveInsert(struct Node *p, int key);
int nodeHeight(struct Node *p);
int balanceFactor(struct Node *p);

struct Node *LLRotation(struct Node *p);
struct Node *LRRotation(struct Node *p);
struct Node *RRRotation(struct Node *p);
struct Node *RLRotation(struct Node *p);
