#include "ArrayADTinC.h"

int main() {
  struct Array arr; // Initielization
  int choice, input, index;
  printf("Enter size of an array:");
  scanf("%d", &arr.size);

  // allocate memory in heap and make pointer A ponit to
  arr.A = (int *)malloc(arr.size * sizeof(int));
  arr.length = arr.size;

  do {
    printf("Menu\n");
    printf("0. Set\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter Your Choice:\n");
    scanf("%d", &choice);

    switch (choice) {
    case 0:
      printf("Enter an index:");
      scanf("%d", &index);
      printf("Enter its element:");
      scanf("%d", &input);
      Set(&arr, index, input);
      printf(" Element at index %d is %d now\n", index, input);
      break;
    case 1:
      printf("Enter an index:");
      scanf("%d", &index);
      printf("Enter its element:");
      scanf("%d", &input);
      Insert(&arr, index, input);
      break;
    case 2:
      printf("Enter an index");
      scanf("%d", &index);
      input = Delete(&arr, index);
      printf("Deleted Element is %d\n", input);
      break;
    case 3:
      printf("Enter an element to search");
      scanf("%d", &input);
      index = LinearSearch(arr, input);
      printf(" Element  Index is %d\n", index);
      break;
    case 4:
      printf("Sum is %d\n", Sum(arr));
      break;
    case 5:
      Display(arr);
      break;
    }
  } while (choice < 6);

  return 0;
}
