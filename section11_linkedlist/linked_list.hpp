

class Node {
public:
  int Data;
  Node *Next;
};

class LinkedList {
private:
  Node *First;

public:
  LinkedList();
  LinkedList(int array[], int size);
  ~LinkedList();

  void Display();
  void Insert(int index, int value);
  void Delete(int index);
  int Length();
};
