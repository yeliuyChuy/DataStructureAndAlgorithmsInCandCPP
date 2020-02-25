#include "avl_tree.h"

struct Node *RecursiveInsert(struct Node *p, int key) {
  struct Node *tmp = NULL;

  if (p == NULL) {
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = key;
    tmp->height = 1;
    tmp->lChild = tmp->rChild = NULL;
    return tmp;
  }

  if (key < p->data) {
    p->lChild = RecursiveInsert(p->lChild, key);
  } else if (key > p->data) {
    p->rChild = RecursiveInsert(p->rChild, key);
  }

  p->height = nodeHeight(p);
  if (balanceFactor(p) == 2 && balanceFactor(p->lChild) == 1) {
    return LLRotation(p);
  } else if (balanceFactor(p) == 2 && balanceFactor(p->lChild) == -1) {
    return LRRotation(p);
  } else if (balanceFactor(p) == 2 && balanceFactor(p->rChild) == 1) {
    return RRRotation(p);
  } else if (balanceFactor(p) == 2 && balanceFactor(p->rChild) == -1) {
    return RLRotation(p);
  }
  return p;
}

int nodeHeight(struct Node *p) {
  int height_left, height_right;

  height_left = p && p->lChild ? p->lChild->height : 0;
  height_right = p && p->rChild ? p->rChild->height : 0;

  return height_left > height_right ? height_left + 1 : height_right + 1;
}

int balanceFactor(struct Node *p) {
  int height_left, height_right;

  height_left = p && p->lChild ? p->lChild->height : 0;
  height_right = p && p->rChild ? p->rChild->height : 0;

  return height_left - height_right;
}

struct Node *LLRotation(struct Node *p) {
  struct Node *pl = p->lChild; // 1.use left child replace the node
  struct Node *plr = pl->rChild;

  pl->rChild = p;  // 2. make the node as its left child's right child
  p->lChild = plr; // 3. the right child of left child of the node becomes the
                   // left child of the node

  // modify the height
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if (root == p) {
    root = pl;
  }
  return pl;
}

struct Node *LRRotation(struct Node *p) {
  struct Node *pl = p->lChild;
  struct Node *plr = pl->rChild;

  pl->rChild = plr->lChild;
  p->lChild = plr->rChild;
  plr->lChild = pl;
  plr->rChild = p;

  // modify the height
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);
  plr->height = nodeHeight(plr);

  if (root == p) {
    root = plr;
  }
  return plr;
}
struct Node *RRRotation(struct Node *p) {
  struct Node *pr = p->rChild; // 1.use left child replace the node
  struct Node *prl = pr->lChild;

  pr->lChild = p;  // 2. make the node as its left child's right child
  p->rChild = prl; // 3. the right child of left child of the node becomes the
                   // left child of the node

  // modify the height
  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if (root == p) {
    root = pr;
  }
  return pr;
}
struct Node *RLRotation(struct Node *p) {
  struct Node *pr = p->rChild;
  struct Node *prl = pr->lChild;

  pr->lChild = prl->rChild;
  p->rChild = prl->lChild;
  prl->lChild = p;
  prl->rChild = pr;

  // modify the height
  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);
  prl->height = nodeHeight(prl);

  if (root == p) {
    root = prl;
  }
  return prl;
}
