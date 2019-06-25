#include <stdio.h>

#define ArraySize 50

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 2) + fib(n - 1);
}

// or use array for storing computed fib[n], which reduces the complexity of the
// program
int storageArray[ArraySize];
int mfib(int n) {
  if (n <= 1) {
    storageArray[n] = n;
    return n;
  } else {
    if (storageArray[n - 2] == -1) {
      storageArray[n - 2] = mfib(n - 2);
    }
    if (storageArray[n - 1] == -1) {
      storageArray[n - 1] = mfib(n - 1);
    }
    return storageArray[n - 2] + storageArray[n - 1];
  }
}

int main() {

  // initialize Array
  for (int i = 0; i < ArraySize; i++) {
    storageArray[i] = -1;
  }

  // write the recursive fib function with array storing values
  printf("%d\n", mfib(10));
  return 0;
}
