#include "ADT_BinaryTree.h"

void create(struct Queue *q, int size) {
  q->size = size;
  q->front = q->rear = -1; // null
  q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *n) {
  // check if queue is full
  if ((q->rear + 1) % q->size == q->front) {
    printf("Queue is Full\n");
  } else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = n;
  }
}

struct Node *dequeue(struct Queue *q) {
  struct Node *n = NULL;
  // check if queue is empty
  if (q->front == q->rear) {
    printf("Queue is empty\n");
  } else {
    q->front = (q->front + 1) % q->size;
    n = q->Q[q->front];
  }
  return n;
}

int isEmpty(struct Queue q) { return q.front == q.rear; }

void createTree() {
  struct Node *p, *tmp;
  struct Queue q;
  int val;

  create(&q, 100);
  printf("Enter Root Value: ");
  scanf("%d", &val);

  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = val;
  root->lChild = root->rChild = NULL;
  enqueue(&q, root);

  while (!isEmpty(q)) {
    p = dequeue(&q);

    printf("Enter Left Child Value of %d: ", p->data);
    scanf("%d", &val);
    if (val != -1) {
      tmp = (struct Node *)malloc(sizeof(struct Node));
      tmp->data = val;
      tmp->lChild = tmp->rChild = NULL;
      //
      p->lChild = tmp;
      enqueue(&q, tmp);
    }

    printf("Enter Left Child Value of %d: ", p->data);
    scanf("%d", &val);
    if (val != -1) {
      tmp = (struct Node *)malloc(sizeof(struct Node));
      tmp->data = val;
      tmp->lChild = tmp->rChild = NULL;
      //
      p->rChild = tmp;
      enqueue(&q, tmp);
    }
  }
}

void levelOrder(struct Node *root) {
  struct Queue q;
  create(&q, 100);

  printf("%d\n", root->data);
  enqueue(&q, root);

  while (!isEmpty(q)) {
    root = dequeue(&q);
    if (root->lChild) {
      printf("%d\n", root->lChild->data);
      enqueue(&q, root->lChild);
    }
    if (root->rChild) {
      printf("%d\n", root->rChild->data);
      enqueue(&q, root->rChild);
    }
  }
}

int count(struct Node *root) {
  if (root) {
    return count(root->lChild) + count(root->rChild) + 1;
  }
  return 0;
}

int height(struct Node *root) {
  if (root == 0)
    return 0;
  if (height(root->lChild) > height(root->rChild)) {
    return height(root->lChild) + 1;
  } else {
    return height(root->rChild) + 1;
  }
}

void preOrder(struct Node *p) {
  if (p) {
    printf("%d", p->data);
    preOrder(p->lChild);
    preOrder(p->rChild);
  }
}
void inOrder(struct Node *p) {
  if (p) {
    inOrder(p->lChild);
    printf("%d", p->data);
    inOrder(p->rChild);
  }
}
void postOrder(struct Node *p) {
  if (p) {
    postOrder(p->lChild);
    postOrder(p->rChild);
    printf("%d", p->data);
  }
}

// Binary Search Tree:
void insert(int key) {
  struct Node *t = root;
  struct Node *r = NULL, *p;

  if (root == NULL) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lChild = p->rChild = NULL;
    root = p;
    return;
  }

  while (t != NULL) {
    r = t;
    if (key < t->data)
      t = t->lChild;
    else if (key > t->data)
      t = t->rChild;
    else
      return;
  }
  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = key;
  p->lChild = p->rChild = NULL;
  if (key < r->data)
    r->lChild = p;
  else
    r->rChild = p;
}

struct Node *Search(int key) {
  struct Node *r = root;
  while (r != NULL) {
    if (key == r->data) {
      return r;
    } else if (key < r->data) {
      r = r->lChild;
    } else {
      r = r->rChild;
    }
  }
  return NULL;
}

struct Node *RecursiveInsert(struct Node *p, int key) {
  struct Node *tmp = NULL;

  if (p == NULL) {
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = key;
    tmp->lChild = tmp->rChild = NULL;
    return tmp;
  }

  if (key < p->data) {
    p->lChild = RecursiveInsert(p->lChild, key);
  } else if (key > p->data) {
    p->rChild = RecursiveInsert(p->rChild, key);
  }
  return p;
}

struct Node *delete (struct Node *p, int key) {
  struct Node *q;
  if (p == NULL)
    return NULL;

  if (p->lChild == NULL && p->rChild == NULL) {
    // if a leaf Node
    if (p == root) {
      return NULL;
    }
    free(p);
    return NULL;
  }

  if (key < p->data) {
    p->lChild = delete (p->lChild, key);
  } else if (key > p->data) {
    p->rChild = delete (p->rChild, key);
  } else {
    if (height(p->lChild) > height(p->rChild)) {
      q = inPre(p->lChild);
      p->data = q->data;
      p->lChild = delete (p->lChild, q->data);
    } else {
      q = inSucc(p->rChild);
      p->data = q->data;
      p->rChild = delete (p->rChild, q->data);
    }
  }
  return p;
}

struct Node *inPre(struct Node *p) {
  // right most Child
  while (p && p->rChild != NULL) {
    p = p->rChild;
  }
  return p;
}

struct Node *inSucc(struct Node *p) {
  // left most Child
  while (p && p->lChild != NULL) {
    p = p->lChild;
  }
  return p;
}
