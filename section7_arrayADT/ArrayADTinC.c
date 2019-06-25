#include "ArrayADTinC.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Display(struct Array arr) {

  printf("=========Result=========\nElements are:\n");
  for (int i = 0; i < arr.length; i++) {
    printf(" %d ", arr.A[i]);
  }
  printf("\n");
}

void Append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length++] = x;
  }
}

void Insert(struct Array *arr, int index, int x) {
  if (index >= 0 && index <= arr->length) {
    // shift elements
    for (int i = arr->length; i > index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    // assign the given value at indexed position
    arr->A[index] = x;
    // update length
    arr->length++;
  }
}

int Delete(struct Array *arr, int index) {
  int temp = 0;
  if (index >= 0 && index <= arr->length) {
    temp = arr->A[index];
    for (int i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return temp;
  }
  return 0;
}

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array arr, int key) {
  for (int i = 0; i < arr.length; i++) {
    if (key == arr.A[i])
      return i;
  }
  return -1;
}

int LoopBinarySearch(struct Array arr, int key) {
  int low, mid, high;
  low = 0;
  high = arr.length - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (key == arr.A[mid]) {
      return mid;
    } else if (key < arr.A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int RecursiveBinarySearch(int inputArray[], int high, int low, int key) {
  int mid;

  if (low <= high) {
    mid = (low + high) / 2;
    if (key == inputArray[mid])
      return mid;
    else if (key < inputArray[mid])
      return RecursiveBinarySearch(inputArray, mid - 1, low, key);
    else
      return RecursiveBinarySearch(inputArray, high, mid + 1, key);
  }
  return -1;
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }
  return -1;
}

int Set(struct Array *arr, int index, int newValue) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = newValue;
  }
  return -1;
}

int Max(struct Array arr) {
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] > max)
      max = arr.A[i];
  }
  return max;
}

int Min(struct Array arr) {
  int min = arr.A[0];
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] < min)
      min = arr.A[i];
  }
  return min;
}

int Sum(struct Array arr) {
  int result = 0;
  for (int i = 0; i < arr.length; i++) {
    result += arr.A[i];
  }
  return result;
}

float Avg(struct Array arr) { return (float)Sum(arr) / arr.length; }

void Reverse(struct Array *arr) {
  for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
    swap(&arr->A[i], &arr->A[j]);
  }
}

void InsertSort(struct Array *arr, int newValue) {
  if (arr->length == arr->size)
    return; // no free space to accept new element
  int i = arr->length;
  while (i >= 0 && arr->A[i] > newValue) {
    arr->A[i + 1] = arr->A[i];
    i--;
  }
  arr->A[i + 1] = newValue;
  arr->length++;
}

bool IsSorted(struct Array arr) {
  for (int i = 0; i < arr.length - 1; i++) {
    if (arr.A[i] > arr.A[i + 1])
      return false;
  }
  return true;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {
  int i = 0, j = 0, k = 0;
  struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->A[i] < arr2->A[j]) {
      newArray->A[k++] = arr1->A[i++];
    } else {
      newArray->A[k++] = arr2->A[j++];
    }
  }

  for (; i < arr1->length; i++) {
    newArray->A[k++] = arr1->A[i];
  }
  for (; i < arr2->length; j++) {
    newArray->A[k++] = arr2->A[j];
  }

  newArray->length = arr1->length + arr2->length;
  newArray->size = arr1->size + arr2->size;

  return newArray;
}

struct Array *Union(struct Array *arr1, struct Array *arr2) {
  int i = 0, j = 0, k = 0;
  struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->A[i] < arr2->A[j]) {
      newArray->A[k++] = arr1->A[i++];
    } else if (arr1->A[i] > arr2->A[j]) {
      newArray->A[k++] = arr2->A[j++];
    } else {
      newArray->A[k++] = arr1->A[i++];
      j++;
    }
  }

  for (; i < arr1->length; i++) {
    newArray->A[k++] = arr1->A[i];
  }
  for (; i < arr2->length; j++) {
    newArray->A[k++] = arr2->A[j];
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) {
  int i = 0, j = 0, k = 0;
  struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->A[i] < arr2->A[j]) {
      i++;
    } else if (arr1->A[i] > arr2->A[j]) {
      j++;
    } else {
      newArray->A[k++] = arr1->A[i++];
      j++;
    }
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2) {
  int i = 0, j = 0, k = 0;
  struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length) {
    if (arr1->A[i] < arr2->A[j]) {
      newArray->A[k++] = arr1->A[i++];
    } else if (arr1->A[i] > arr2->A[j]) {
      j++;
    } else {
      i++;
      j++;
    }
  }

  for (; i < arr1->length; i++) {
    newArray->A[k++] = arr1->A[i];
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}
