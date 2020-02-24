#include "ADT_BinaryTree.c"

int main() {
  /*
  createTree();
  printf("\n===========preOrder=================\n");
  preOrder(root);
  printf("\n===========inOrder=================\n");
  inOrder(root);
  printf("\n===========postOrder=================\n");
  postOrder(root);
  */
  struct Node *tmp;
  root = RecursiveInsert(root, 10);
  RecursiveInsert(root, 5);
  RecursiveInsert(root, 20);
  RecursiveInsert(root, 10);
  RecursiveInsert(root, 8);
  RecursiveInsert(root, 30);

  /*
  insert(10);
  insert(5);
  insert(20);
  insert(10);
  insert(8);
  insert(30);
  */

  printf("\n");
  tmp = Search(20);
  delete (root, 30);
  if (tmp != NULL) {
    printf("element %d is found\n", tmp->data);
  } else {
    printf("element not found\n");
  }
  inOrder(root);

  return 0;
}
