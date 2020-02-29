#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *lChild;
  int data;
  struct Node *rChild;
} *root = NULL;

struct Queue {
  int size;
  int front; // pointer
  int rear;  // pointer
  struct Node **Q;
};

int isEmpty(struct Queue q);

void create(struct Queue *q, int size);
void enqueue(struct Queue *q, struct Node *n);
struct Node *dequeue(struct Queue *q);
void display(struct Queue q);

void createTree();
void levelOrder(struct Node *root);
int count(struct Node *root);
int height(struct Node *root);

void preOrder(struct Node *p);
void inOrder(struct Node *p);
void postOrder(struct Node *p);

// Binary Search Tree:
void insert(int key);
struct Node *Search(int key);
struct Node *RecursiveInsert(struct Node *p, int key);
struct Node *delete (struct Node *p, int key);
struct Node *inPre(struct Node *p);
struct Node *inSucc(struct Node *p);
