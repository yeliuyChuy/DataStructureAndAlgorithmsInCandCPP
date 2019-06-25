#include "ArrayADTinC.h"
//==============================================================================
// Find the duplicate element
void FindDuplicate(struct Array arr) {
  // Initialization
  struct Array newArray;

  newArray.A = (int *)malloc(arr.size * sizeof(int));
  newArray.length = Max(arr);
  // initialize all elements to 0
  for (int i = 0; i < newArray.length - 1; i++) {
    newArray.A[i] = 0;
  }
  // scan original input array and put it into hashtable
  for (int j = 0; j < arr.length - 1; j++) {
    newArray.A[arr.A[j]]++;
  }
  for (int k = 1; k < newArray.length - 1; k++) {
    if (newArray.A[k] == 0) {
      printf("Missing %d in this array\n", k);
    } else if (newArray.A[k] > 1) {
      printf(" %d appeared in this array for %d times\n", k, newArray.A[k]);
    }
  }
  return;
}
