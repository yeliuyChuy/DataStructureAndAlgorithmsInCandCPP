#include "ArrayADTinC.h"
//==============================================================================
// Find the duplicate element
void FindDuplicate(struct Array arr, int sum) {
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

  for (int j = 0; j < arr.length - 1; j++) {
    if (newArray.A[sum - arr.A[j]] != 0) {
      printf("%d + %d = %d\n", arr.A[j], sum - arr.A[j], sum);
    }
    newArray.A[arr.A[j]]++;
  }
  return;
}
