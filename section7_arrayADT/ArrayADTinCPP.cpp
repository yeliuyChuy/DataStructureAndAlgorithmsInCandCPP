#include <iostream>
using namespace std;

class Array {
private:
  int *A;
  int size;
  int length;
  void swap(int *x, int *y);

public:
  // constructor
  Array() {
    size = 10;
    length = 0; // no elements
    A = new int[size];
  }
  // constructor for given size
  Array(int _size) {
    size = _size;
    length = 0; // no elements
    A = new int[size];
  }
  // destructor
  ~Array() { delete[] A; }
  void Display();
  void Append(int x);
  void Insert(int index, int x);
  int Delete(int index);

  int LinearSearch(int key);
  int LoopBinarySearch(int key);
  int RecursiveBinarySearch(int inputArray[], int high, int low, int key);
  int Get(int index);
  int Set(int index, int newValue);
  int Max();
  int Min();
  int Sum();
  float Avg();
  void Reverse();
  void InsertSort(int newValue);
  bool IsSorted();
  Array *Merge(Array arr2);
  Array *Union(Array arr2);
  Array *Intersection(Array arr2);
  Array *Difference(Array arr2);
};

void Array::Display() {
  printf("=========Result=========\nElements are:\n");
  for (int i = 0; i < length; i++) {
    printf(" %d ", A[i]);
  }
  printf("\n");
}

void Array::Append(int x) {
  if (length < size) {
    A[length++] = x;
  }
}

void Array::Insert(int index, int x) {
  if (index >= 0 && index <= length) {
    // shift elements
    for (int i = length; i > index; i--) {
      A[i] = A[i - 1];
    }
    // assign the given value at indexed position
    A[index] = x;
    // update length
    length++;
  }
}

int Array::Delete(int index) {
  int temp = 0;
  if (index >= 0 && index <= length) {
    temp = A[index];
    for (int i = index; i < length - 1; i++) {
      A[i] = A[i + 1];
    }
    length--;
    return temp;
  }
  return 0;
}

void Array::swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int Array::LinearSearch(int key) {
  for (int i = 0; i < length; i++) {
    if (key == A[i])
      return i;
  }
  return -1;
}

int Array::LoopBinarySearch(int key) {
  int low, mid, high;
  low = 0;
  high = length - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (key == A[mid]) {
      return mid;
    } else if (key < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int Array::RecursiveBinarySearch(int inputArray[], int high, int low, int key) {
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

int Array::Get(int index) {
  if (index >= 0 && index < length) {
    return A[index];
  }
  return -1;
}

int Array::Set(int index, int newValue) {
  if (index >= 0 && index < length) {
    A[index] = newValue;
  }
  return -1;
}

int Array::Max() {
  int max = A[0];
  for (int i = 0; i < length; i++) {
    if (A[i] > max)
      max = A[i];
  }
  return max;
}

int Array::Min() {
  int min = A[0];
  for (int i = 0; i < length; i++) {
    if (A[i] < min)
      min = A[i];
  }
  return min;
}

int Array::Sum() {
  int result = 0;
  for (int i = 0; i < length; i++) {
    result += A[i];
  }
  return result;
}

float Array::Avg() { return (float)Sum() / length; }

void Array::Reverse() {
  for (int i = 0, j = length - 1; i < j; i++, j--) {
    swap(&A[i], &A[j]);
  }
}

void Array::InsertSort(int newValue) {
  if (length == size)
    return; // no free space to accept new element
  int i = length - 1;
  while (i >= 0 && A[i] > newValue) {
    A[i + 1] = A[i];
    i--;
  }
  A[i + 1] = newValue;
  length++;
}

bool Array::IsSorted() {
  for (int i = 0; i < length - 1; i++) {
    if (A[i] > A[i + 1])
      return false;
  }
  return true;
}

Array *Array::Merge(Array arr2) {
  int i = 0, j = 0, k = 0;
  // Using new instead of malloc
  // struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));
  Array *newArray = new Array(length + arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      newArray->A[k++] = A[i++];
    } else {
      newArray->A[k++] = arr2.A[j++];
    }
  }

  for (; i < length; i++) {
    newArray->A[k++] = A[i];
  }
  for (; i < arr2.length; j++) {
    newArray->A[k++] = arr2.A[j];
  }

  newArray->length = length + arr2.length;

  return newArray;
}

Array *Array::Union(Array arr2) {
  int i = 0, j = 0, k = 0;
  Array *newArray = new Array(length + arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      newArray->A[k++] = A[i++];
    } else if (A[i] > arr2.A[j]) {
      newArray->A[k++] = arr2.A[j++];
    } else {
      newArray->A[k++] = A[i++];
      j++;
    }
  }

  for (; i < length; i++) {
    newArray->A[k++] = A[i];
  }
  for (; i < arr2.length; j++) {
    newArray->A[k++] = arr2.A[j];
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}

Array *Array::Intersection(Array arr2) {
  int i = 0, j = 0, k = 0;
  Array *newArray = new Array(length + arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      i++;
    } else if (A[i] > arr2.A[j]) {
      j++;
    } else {
      newArray->A[k++] = A[i++];
      j++;
    }
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}

Array *Array::Difference(Array arr2) {
  int i = 0, j = 0, k = 0;
  Array *newArray = new Array(length + arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      newArray->A[k++] = A[i++];
    } else if (A[i] > arr2.A[j]) {
      j++;
    } else {
      i++;
      j++;
    }
  }

  for (; i < length; i++) {
    newArray->A[k++] = A[i];
  }

  newArray->length = k;
  newArray->size = k;

  return newArray;
}

int main() {
  Array *arr; // Initielization
  int choice, input, index, size;
  printf("Enter size of an array:");
  scanf("%d", &size);

  // allocate memory in heap and make pointer A ponit to
  arr = new Array(size);

  do {
    cout << "Menu\n";
    cout << "0. Set\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Sum\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";

    cout << "Enter Your Choice:\n";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "Enter an index:";
      cin >> index;
      cout << "Enter its element:";
      cin >> input;
      arr->Set(index, input);
      cout << " Element at index " << index << " is " << input;
      break;
    case 1:
      cout << "Enter an index:";
      cin >> index;
      cout << "Enter its element:";
      cin >> input;
      arr->Insert(index, input);
      break;
    case 2:
      cout << "Enter an index:";
      cin >> index;
      input = arr->Delete(index);
      cout << "Deleted Element is " << input;
      break;
    case 3:
      cout << "Enter an element to search";
      cin >> input;
      index = arr->LinearSearch(input);
      cout << " Element  Index is " << index;
      break;
    case 4:
      cout << "Sum is " << arr->Sum();
      break;
    case 5:
      arr->Display();
      break;
    }
  } while (choice < 6);

  return 0;
}
