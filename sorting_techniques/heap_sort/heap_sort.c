#include "heap_sort.h"

void Heap_Insert(int H[], int val) {
  int i = val;
  int temp = H[i];

  while (i > 1 && temp > H[i / 2]) { // comparing with its parent
    H[i] = H[i / 2];
    i = i / 2;
  }
  // we got right place
  H[i] = temp;
}

int Delete(int H[], int key) {
  int i = 1;
  int j = i * 2;
  int x, temp;
  int val = H[1];
  x = H[key];    // take last elememt
  H[1] = H[key]; // copy last element to first place
  H[key] = val;

  while (j < key - 1) {
    if (H[j + 1] > H[j])
      j = j + 1;
    if (H[i] < H[j]) {
      temp = H[i];
      H[i] = H[j];
      H[j] = temp;
      i = j;
      j = 2 * j;
    } else {
      break;
    }
  }
  return val;
}

int main() {
  int H[] = {0, 2, 5, 8, 9, 4, 10, 7};

  Heap_Insert(H, 2);
  Heap_Insert(H, 3);
  Heap_Insert(H, 4);
  Heap_Insert(H, 6);
  return 0;
}
