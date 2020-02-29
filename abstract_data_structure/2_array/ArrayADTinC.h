#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Array {
  int *A;
  int size;
  int length;
};

void Display(struct Array arr);

void Append(struct Array *arr, int x);

void Insert(struct Array *arr, int index, int x);

int Delete(struct Array *arr, int index);

void swap(int *x, int *y);

int LinearSearch(struct Array arr, int key);

int LoopBinarySearch(struct Array arr, int key);

int RecursiveBinarySearch(int inputArray[], int high, int low, int key);

int Get(struct Array arr, int index);

int Set(struct Array *arr, int index, int newValue);

int Max(struct Array arr);

int Min(struct Array arr);

int Sum(struct Array arr);

float Avg(struct Array arr);

void Reverse(struct Array *arr);

void InsertSort(struct Array *arr, int newValue);

bool IsSorted(struct Array arr);

struct Array *Merge(struct Array *arr1, struct Array *arr2);

struct Array *Union(struct Array *arr1, struct Array *arr2);

struct Array *Intersection(struct Array *arr1, struct Array *arr2);
