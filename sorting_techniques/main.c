#include "SortingLib.h"

int main() {
  int A[] = {3, 7, 10, 6, 5, 12, 4, 11, 2, 50, 20};
  size_t size = sizeof(A) / sizeof(A[0]);

  // BubbleSort(A, size);
  // InsertionSort(A, size);
  // SelectionSort(A, size);
  // QuickSort(A, 0, size - 1);
  // IterativeMergeSort(A, size);
  // RecursiveMergeSort(A, 0, size - 1);
  // CountSort(A, size);
  print(A, size);

  return 0;
}
