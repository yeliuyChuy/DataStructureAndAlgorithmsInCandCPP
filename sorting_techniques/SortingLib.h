#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// General Functions:
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void print(int A[], int size) {
  for (int i = 0; i <= size - 1; i++) {
    printf("%d\n", A[i]);
  }
}

int partition(int A[], int low, int high) {
  int pivot = A[low];
  int i = low, j = high;
  do {
    do {
      i++;
    } while (A[i] <= pivot);
    do {
      j--;
    } while (A[j] > pivot);
    if (i < j)
      swap(&A[i], &A[j]);
  } while (i < j);
  swap(&A[low], &A[j]);
  return j;
}

void Merge(int A[], int low, int mid, int high) {
  int i = low;
  int k = low;
  int j = mid + 1;
  int res[100];

  while (i <= mid && j <= high) {
    if (A[i] < A[j]) {
      res[k++] = A[i++];
    } else {
      res[k++] = A[j++];
    }
  }
  for (; i <= mid; i++) {
    res[k++] = A[i];
  }
  for (; j <= high; j++) {
    res[k++] = A[j];
  }
  for (int i = low; i <= high; i++) {
    A[i] = res[i];
  }
}
int FindMax(int A[], int size) {
  int max = INT32_MIN;
  for (int i = 0; i < size; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  return max;
}
//====================================
/*
Bubble Sort:

for n elements:
  n - 1 pass there:
  n(n-1)/2 -> O(n^2) comparisons happened
  n(n-1)/2 -> O(n^2) swap happened

*/
void BubbleSort(int A[], int num_element) {
  for (int i = 0; i < num_element; i++) {
    for (int j = 0; j < num_element - i - 1; j++) {
      if (A[j] < A[j + 1]) {
        swap(&A[j], &A[j + 1]);
      }
    }
  }
}

/*
Insertion Sort using linked list

* sorted array
* O(1) - O(n): Travesal all elements

n - 1 pass
n(n-1)/2 -> O(n^2) comparisons happened
n(n-1)/2 -> O(n^2) swap happened

*/
void InsertionSort(int A[], int size) {
  int pre, cur;
  for (int i = 1; i < size; i++) {
    pre = i - 1;
    cur = A[i];
    while (pre > -1 && A[pre] > cur) {
      A[pre + 1] = A[pre];
      pre--;
    }
    A[pre + 1] = cur;
  }
}

/*
Selection Sort
n(n-1)/2 -> O(n^2) comparisons happened
O(n) swap happened
*/

void SelectionSort(int A[], int size) {
  int j, k;
  for (int i = 0; i < size; i++) {
    for (j = k = i; j < size; j++) {
      if (A[j] < A[k])
        k = j;
    }
    swap(&A[i], &A[k]);
  }
}

/*
Quick Sort
(best case)If sorted in ascending/descending: n(n+1)/2 -> O(n^2) comparisons
happened (Worst case) If sorted in descending:  O(nLogn) if partitioning
happened in the middle.
*/
void QuickSort(int A[], int low, int high) {
  int j;
  if (low < high) {
    j = partition(A, low, high);
    QuickSort(A, low, j);
    QuickSort(A, j + 1, high);
  }
}

/* Merge Sort
O(nLogn), extra space required n + logn: Recursive Merging Sort
O(nLogn): iterative merge sort
*/
void IterativeMergeSort(int A[], int size) {
  int i, low, high, mid;

  for (i = 2; i <= size; i = i * 2) {
    for (int j = 0; j + i - 1 < size; j = j + i) {
      low = j;
      high = j + i - 1;
      mid = (low + high) / 2;
      Merge(A, low, mid, high);
    }
  }
  if (i / 2 < size) {
    Merge(A, 0, i / 2 - 1, size);
  }
}

void RecursiveMergeSort(int A[], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    RecursiveMergeSort(A, low, mid);
    RecursiveMergeSort(A, mid + 1, high);
    Merge(A, low, mid, high);
  }
}

/* Count Sort
O(m+n) -> O(n)
*/
void CountSort(int A[], int size) {
  int *C;
  int p, q;
  int max = FindMax(A, size);

  C = (int *)malloc(sizeof(int) * max + 1);
  // initialize C as 0
  for (int i = 0; i < max + 1; i++) {
    C[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    C[A[i]]++;
  }
  p = q = 0;
  while (q < max + 1) {
    if (C[q] > 0) {
      A[p++] = q;
      C[q]--;
    } else {
      q++;
    }
  }
}

/* Shell Sort
for very large list
O(nLogn)
*/
void ShellSort(int A[], int size) {
  int gap, temp, i, j;

  for (gap = size / 2; gap > 1; gap /= 2) {
    for (i = gap; i < size; i++) {
      temp = A[i];
      j = i - gap;
      while (j > 0 && A[j] > temp) {
        A[j + gap] = A[j];
        j = j - gap;
      }
      A[j + gap] = temp;
    }
  }
}
/* Hash
Avg successful Search: O(1 + lamda/2)
Space Requirement for hash table:
  Linked List: any
  linear probing: 2*elements size
*/
struct Node {
  int data;
  struct Node *next;
};
void SortedInsert(struct Node **H, int x) {
  struct Node *t, *q = NULL, *p = *H;

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  if (*H == NULL)
    *H = t;
  else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }
    if (p == *H) {
      t->next = *H;
      *H = t;
    } else {
      t->next = q->next;
      q->next = t;
    }
  }
}
struct Node *Search(struct Node *p, int key) {
  while (p != NULL) {
    if (key == p->data) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}
int hash(int key) { return key % 10; }
void Insert(struct Node *H[], int key) {
  int index = hash(key);
  SortedInsert(&H[index], key);
}
