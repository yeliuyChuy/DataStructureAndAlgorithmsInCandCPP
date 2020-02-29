#include "ADT_bTree.h"

#define MAX_KEYS 1024

struct btNode {
  bool isLeaf;
  int numKeys; // num of keys this node contain
  int keys[MAX_KEYS];
  struct btNode *child[MAX_KEYS + 1];
};

bTree btCreate() {
  bTree myTree = malloc(sizeof(*myTree));
  assert(myTree);

  myTree->isLeaf = true;
  myTree->numKeys = 0;

  return myTree;
}

void btDestroy(bTree myTree) {
  if (!myTree->isLeaf) {
    for (int i = 0; i < myTree->numKeys + 1; i++) {
      btDestroy(myTree->child[i]);
    }
  }
  free(myTree);
}

// binary search for smallest index i in sorted array such that key <= a[i]
// or n if there is no such index
static int searchKey(int n, int *a, int key) {
  int low, mid, high;

  low = -1;
  high = n;

  while (low + 1 < high) {
    mid = (low + high) / 2;
    if (a[mid] == key) {
      return mid;
    } else if (a[mid] < key) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high;
}

int btSearch(bTree myTree, int key) {
  int index;
  // check if it is an empty tree:
  if (myTree->numKeys == 0) {
    return 0;
  }
  // look for the smallest position that key fits below
  index = searchKey(myTree->numKeys, myTree->keys, key);
  if (index < myTree->numKeys && myTree->keys[index] == key) {
    return 1;
  } else {
    return (!myTree->isLeaf && btSearch(myTree->child[index], key));
  }
}

// insert a new ky into a tree,
// return new right sibling if the node splits
// and puts the median in *median
// else return 0;
static bTree btInsertInternal(bTree myTree, int key, int *median) {
  int mid;
  bTree myTree_2;
  int index = searchKey(myTree->numKeys, myTree->keys, key);
  if (index < myTree->numKeys && myTree->keys[index] == key) {
    return 0;
  }
  if (myTree->isLeaf) {
    memmove(&myTree->keys[index + 1], &myTree->keys[index],
            sizeof(*(myTree->keys)) * (myTree->numKeys - index));
    myTree->keys[index] = key;
    myTree->numKeys++;
  } else {
    myTree_2 = btInsertInternal(myTree->child[index], key, &mid);
    if (myTree_2) {
      memmove(&myTree->keys[index + 1], &myTree->keys[index],
              sizeof(*(myTree->keys)) * (myTree->numKeys - index));
      memmove(&myTree->child[index + 2], &myTree->child[index + 1],
              sizeof(*(myTree->keys)) * (myTree->numKeys - index));
      myTree->keys[index] = mid;
      myTree->child[index + 1] = myTree_2;
      myTree->numKeys++;
    }
  }

  if (myTree->numKeys >= MAX_KEYS) {
    mid = myTree->numKeys / 2;
    *median = myTree->keys[mid];

    myTree_2 = malloc(sizeof(*myTree_2));
    myTree_2->numKeys = myTree->numKeys - mid - 1;
    myTree_2->isLeaf = myTree->isLeaf;
    memmove(&myTree_2->keys[index + 1], &myTree->keys[index],
            sizeof(*(myTree->keys)) * (myTree_2->numKeys - index));
    if (!myTree->isLeaf) {
      memmove(&myTree_2->child[index + 1], &myTree->child[index],
              sizeof(*(myTree->child)) * (myTree_2->numKeys + 1));
    }
    myTree->numKeys = mid;
    return myTree_2;
  } else {
    return 0;
  }
}

void btInsert(bTree b, int key) {
  bTree b1; // new left child
  bTree b2; // new right child
  int median;

  b2 = btInsertInternal(b, key, &median);
  if (b2) {
    b1 = malloc(sizeof(*b1));
    assert(b1);

    memmove(b1, b, sizeof(*b));

    b->numKeys = 1;
    b->isLeaf = false;
    b->keys[0] = median;
    b->child[0] = b1;
    b->child[1] = b2;
  }
}
