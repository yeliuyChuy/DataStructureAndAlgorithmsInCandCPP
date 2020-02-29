#include <iostream>

enum RBTColor { RED, BLACK };

template <class T> class RBTNode {
public:
  RBTColor color;
  T key;
  RBTNode lChild;
  RBTNode rChild;
  RBTNode *parent;

  RBTNode(T val, RBTColor col, RBTNode *p, RBTNode *l, RBTNode *r)
      : key(val), color(col), parent(), lChild(l), rChild(r) {}
};

template <class T> class RBTree {
private:
  RBTNode<T> *root; // root node
public:
  RBTree();
  ~RBTree();

  // Treversal functions
  void preOrder();
  void inOrder();
  void postOrder();

  // 2 searching functions
  RBTNode<T> search(T key);
  RBTNode<T> iterativeSearch(T key);

  // find min max key
  T minimum();
  T maximum();

  // find the successor and predecessor of x
  RBTNode<T>
  successor(RBTNode<T> *x); // find the minimum one that greater than x
  RBTNode<T>
  predesessor(RBTNode<T> *x); // find the maximum one that less than x

  // insert key
  void insert(T key);

  // delete key node
  void remove(T key);

  void destroy();
  void print();

private:
  void preOrder(RBTNode<T> *tree) const;
  void inOrder(RBTNode<T> *tree) const;
  void postOrder(RBTNode<T> *tree) const;

  // look for the node in tree X which contains key
  RBTNode<T> *search(RBTNode<T> *x, T key) const;
  RBTNode<T> *iterativeSearch(RBTNode<T> *x, T key) const;

  // find the min and max node based on x as root
  RBTNode<T> *minimum(RBTNode<T> *x) const;
  RBTNode<T> *maximum(RBTNode<T> *x) const;

  void lRotate(RBTNode<T> *&root, RBTNode<T> *x);
  void rRotate(RBTNode<T> *&root, RBTNode<T> *x);
  void insert(RBTNode<T> *&root, RBTNode<T> *node);
  void insertFixUp(RBTNode<T> *&root, RBTNode<T> *node);
  void remove(RBTNode<T> *&root, RBTNode<T> *node);
  void removeFixUp(RBTNode<T> *&root, RBTNode<T> *node, RBTNode<T> *parent);
  void destroy(RBTNode<T> *&tree);
  void print(RBTNode<T> *tree, T key, int direction);
};
