#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main() {
  int array1[] = {1, 3, 5, 7, 9};
  LinkedList myList1(array1, 5);

  // delete and insert;
  myList1.Delete(4);
  myList1.Delete(3);
  myList1.Insert(3, 7);
  myList1.Display();
  cout << "Length: " << myList1.Length() << endl;

  return 0;
}
