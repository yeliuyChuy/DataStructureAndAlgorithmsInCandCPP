#include "singly_linked_list.h"

struct Node *Create(int Array[], int NumElement) {
  struct Node *first = NULL;
  struct Node *temp, *last;
  // allocate memory for head pointer
  first = (struct Node *)malloc(sizeof(struct Node));
  first->Data = Array[0];
  first->Next = NULL;
  last = first; // last pointer point to first node.

  for (int i = 1; i < NumElement; i++) {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = Array[i];
    temp->Next = NULL;
    last->Next = temp;
    last = temp;
  }
  return first;
}

// Display the data in each nodes
void Display(struct Node *p) {
  while (p != NULL) {
    printf("%d ", p->Data);
    p = p->Next;
  }
  printf("\n");
}

void RecursiveDisplay(struct Node *p) {
  if (p != NULL) {
    printf("%d ", p->Data);
    RecursiveDisplay(p->Next);
  }
}

// Count the nodes in linked list
int Count(struct Node *p) {
  int len = 0;
  while (p) {
    len++;
    p = p->Next;
  }
  return len;
}

int RecursiveCount(struct Node *p) {
  if (p != NULL) {
    return RecursiveCount(p->Next) + 1;
  } else {
    return 0;
  }
}

int Sum(struct Node *p) {
  int result = 0;
  while (p != NULL) {
    result += p->Data;
    p = p->Next;
  }
  return result;
}

int RecursiveSum(struct Node *p) {
  if (p == NULL) {
    return 0;
  } else {
    return RecursiveSum(p->Next) + p->Data;
  }
}

int FindMax(struct Node *p) {
  int max = INT32_MIN;
  while (p) {
    if (p->Data > max) {
      max = p->Data;
    }
    p = p->Next;
  }
  return max;
}

int RecursiveFindMax(struct Node *p) {
  int max = 0;
  if (p == 0) {
    return INT32_MIN;
  }
  max = RecursiveFindMax(p->Next);
  if (max > p->Data) {
    return max;
  } else {
    return p->Data;
  }
}

struct Node *LinearSearch(struct Node *p, int key) {
  while (p != NULL) {
    if (key == p->Data) {
      return p;
    }
    p = p->Next;
  }
  return NULL;
}

struct Node *RecursiveLinearSearch(struct Node *p, int key) {
  if (p == NULL) {
    return NULL;
  }
  if (key == p->Data) {
    return p;
  }
  return RecursiveLinearSearch(p->Next, key);
}

void Insert(struct Node *p, int index, int value) {
  // check if the given index is valid first
  if (index < 0 || index > Count(p)) {
    printf("Invalid given index\n");
    return;
  }

  // Initilize the new node;
  struct Node *new;
  new = (struct Node *)malloc(sizeof(struct Node));
  new->Data = value;

  // if insert at first
  if (index == 0) {
    new->Next = p;
    p = new;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->Next;
    }
    new->Next = p->Next;
    p->Next = new;
  }
}

// delete the element at given index,return the element
struct Node *Delete(struct Node *p, int index) {
  struct Node *tempPointer = NULL;
  // check if the index is valid
  if (index < 0 || index > Count(p)) {
    printf("Invalid Index,None of element was deleted\n");
    return p;
  }
  // if delete first
  if (index == 0) {
    tempPointer = p;
    p = p->Next;
    free(tempPointer);
    return p;
  } else {
    // delete others except first
    // traverse to  1 node before given position
    struct Node *first = p;
    for (int i = 0; i < index; i++) {
      tempPointer = p;
      p = p->Next;
    }
    tempPointer->Next = p->Next;
    free(p);
    p = tempPointer;
    return first;
  }
}

bool IsSorted(struct Node *p) {
  int tempValue = INT32_MIN;
  while (p != NULL) {
    // if current data smaller than previous one
    if (p->Data < tempValue) {
      return false;
    }
    // store the current data;
    tempValue = p->Data;
    // move pointer
    p = p->Next;
  }
  return true;
}
void ReverseByArray(struct Node *p) {
  // Creating an array to reverse
  int *tempArray, i = 0;
  struct Node *q = p;

  tempArray = (int *)malloc(sizeof(Count(p)));
  while (q != NULL) {
    tempArray[i] = q->Data;
    q = q->Next;
    i++;
  }
  q = p;
  i--;

  while (q != NULL) {
    q->Data = tempArray[i];
    q = q->Next;
    i--;
  }
}

struct Node *ReverseBySlidePointer(struct Node *p) {
  // using three sliding pointer to reverse
  struct Node *q = NULL, *r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->Next;
    q->Next = r;
  }
  return q;
}

void ReverseByRecursion(struct Node *pNew, struct Node *pOrigin) {
  if (pOrigin) {
    ReverseByRecursion(pOrigin, pOrigin->Next);
    pOrigin->Next = pNew;
  } else {
    pOrigin = pNew;
  }
}

struct Node *Concate(struct Node *list1, struct Node *list2) {
  struct Node *new = list1;
  while (list1->Next != NULL) {
    list1 = list1->Next;
  }
  // last node of list1
  list1->Next = list2;
  return new;
}

struct Node *Merge(struct Node *list1, struct Node *list2) {
  struct Node *last, *new;
  if (list1->Data < list2->Data) {
    new = last = list1;
    list1 = list1->Next;
    new->Next = NULL;
  } else {
    new = last = list2;
    list2 = list2->Next;
    new->Next = NULL;
  }
  while (list1 && list2) {
    if (list1->Data < list2->Data) {
      last->Next = list1;
      last = list1;
      list1 = list1->Next;
      last->Next = NULL;
    } else {
      last->Next = list2;
      last = list2;
      list2 = list2->Next;
      last->Next = NULL;
    }
  }
  if (list1)
    last->Next = list1;
  if (list2)
    last->Next = list2;

  return new;
}

bool isLooped(struct Node *list) {
  // check the linked list if is looped
  struct Node *p, *q;
  p = q = list;

  do {
    p = p->Next;
    q = q->Next;
    q = q ? q->Next : q;
  } while (p && q && p != q);

  if (p == q) {
    return true;
  } else {
    return false;
  }
}
