#include "circular_linked_list.h"

struct Node *CreateCircular(int array[], int numElement) {
  struct Node *head, *last, *temp;

  // initilize head
  head = (struct Node *)malloc(sizeof(struct Node));
  head->Data = array[0];
  head->Next = head;
  last = head;

  for (int i = 1; i < numElement; i++) {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = array[i];
    temp->Next = last->Next;
    last->Next = temp;
    last = temp;
  }
  return head;
}

void DisplayCircular(struct Node *h) {
  struct Node *head = h;
  do {
    printf("%d ", h->Data);
    h = h->Next;
  } while (h != head);
  printf("\n");
}

int CountCircular(struct Node *p) {
  struct Node *head = p;
  int len = 0;
  do {
    len++;
    p = p->Next;
  } while (p != head);
  return len;
}

void InsertCircular(struct Node *p, int index, int value) {
  // check if the given index is valid first
  if (index < 0 || index > CountCircular(p)) {
    printf("Invalid given index\n");
    return;
  }
  struct Node *temp, *head = p;
  if (index == 0) {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = value;
    if (p == NULL) {
      p = head = temp;
      temp->Next = temp;
    } else {
      while (p->Next != head) {
        p = p->Next;
      }
      p->Next = temp;
      temp->Next = head;
      head = temp;
    }
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->Next;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = value;
    temp->Next = p->Next;
    p->Next = temp;
  }
}

void DeleteCircular(struct Node *p, int index) {
  // check if the given index is valid first
  if (index < 0 || index > CountCircular(p)) {
    printf("Invalid given index\n");
    return;
  }
  struct Node *head = p, *pDetele;
  if (index == 1) {
    while (p->Next != head) {
      p = p->Next;
    }
    if (head == p) {
      free(head);
      head = NULL;
    } else {
      p->Next = head->Next;
      free(head);
      head = p->Next;
    }
  } else {
    for (int i = 0; i < index - 2; i++) {
      p = p->Next;
    } // p now is the node before the one that we want to delete
    pDetele = p->Next;
    p->Next = pDetele->Next;
    free(pDetele);
  }
  return;
}
