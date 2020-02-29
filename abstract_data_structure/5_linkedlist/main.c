#include "circular_linked_list.h"
#include "doubly_linked_list.h"
//#include "singly_linked_list.h"

int main() {

  int testArray1[] = {1, 3, 5, 7, 9};
  int testArray2[] = {2, 4, 6, 8, 10};
  // int testArray3[] = {1, 3, 5, 7, 9};
  // struct Node *first = Create(testArray1, 5);
  // struct Node *second = Create(testArray2, 5);
  struct Node *firstCircular = CreateCircular(testArray1, 5);
  // struct DoublyNode *firstDoubly = CreateDoubly(testArray2, 5);
  // Insert(first, 3, 333);

  // delete element
  // first = Delete(first, 2);

  // Reverse
  // ReverseByArray(first);
  // ReverseBySlidePointer(first)
  // ReverseByRecursion(NULL, first);

  // display linked list
  // Display(Merge(first, second));
  // InsertCircular(firstCircular, 0, 0);
  // DeleteCircular(firstCircular, 1);
  DisplayCircular(firstCircular);
  // DisplayDoubly(firstDoubly);

  // check if Sorted
  // if (IsSorted(first)) {
  //  printf("Sorted!\n");
  //} else {
  //  printf("Not Sorted\n");
  //}
  return 0;
}
