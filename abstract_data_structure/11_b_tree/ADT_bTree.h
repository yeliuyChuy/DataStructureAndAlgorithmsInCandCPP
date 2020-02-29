#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// implementation of a B-tree
typedef struct btNode *bTree;

// create an empty tree;
bTree btCreate();

// free a tree;
void btDestroy(bTree t);

// return nonzero if key is present in tree;
int btSearch(bTree t, int key);

// insert a new element into a tree;
void btInsert(bTree t, int key);

// print all keys of the tree in order;
void btPrintKey(bTree t);
