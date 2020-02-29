#include "r_b_tree.hpp"

using namespace std;
/*
RB Tree Rule:
1.Black or red.
2.root node is BLACK
3.potential leaf is BLACK
4. A node must be black if its parent is RED
5. Same amount of BLACK on each path
*/

template <class T> RBTree<T>::~RBTree() { destroy(); }

template <class T> void RBTree<T>::preOrder(RBTNode<T> *tree) const {
  if (tree != NULL) {
    cout << tree->key << " ";
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

template <class T> void RBTree<T>::preOrder() { preOrder(root); }

template <class T> void RBTree<T>::inOrder(RBTNode<T> *tree) const {
  if (tree != NULL) {
    inOrder(tree->left);
    cout << tree->key << " ";
    inOrder(tree->right);
  }
}

template <class T> void RBTree<T>::inOrder() { inOrder(root); }

template <class T> void RBTree<T>::postOrder(RBTNode<T> *tree) const {
  if (tree != NULL) {
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->key << " ";
  }
}

template <class T> void RBTree<T>::postOrder() { postOrder(root); }

template <class T> RBTNode<T> *RBTree<T>::search(RBTNode<T> *x, T key) const {
  if (x == NULL || x->key == key)
    return x;

  if (key < x->key)
    return search(x->left, key);
  else
    return search(x->right, key);
}

template <class T> RBTNode<T> *RBTree<T>::search(T key) { search(root, key); }

template <class T>
RBTNode<T> *RBTree<T>::iterativeSearch(RBTNode<T> *x, T key) const {
  while ((x != NULL) && (x->key != key)) {
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  return x;
}

template <class T> RBTNode<T> *RBTree<T>::iterativeSearch(T key) {
  iterativeSearch(root, key);
}

template <class T> RBTNode<T> *RBTree<T>::minimum(RBTNode<T> *tree) const {
  if (tree == NULL)
    return NULL;

  while (tree->left != NULL)
    tree = tree->left;
  return tree;
}

template <class T> T RBTree<T>::minimum() {
  RBTNode<T> *p = minimum(root);
  if (p != NULL)
    return p->key;

  return (T)NULL;
}

template <class T> RBTNode<T> *RBTree<T>::maximum(RBTNode<T> *tree) const {
  if (tree == NULL)
    return NULL;

  while (tree->right != NULL)
    tree = tree->right;
  return tree;
}

template <class T> T RBTree<T>::maximum() {
  RBTNode<T> *p = maximum(root);
  if (p != NULL)
    return p->key;

  return (T)NULL;
}

template <class T> RBTNode<T> *RBTree<T>::successor(RBTNode<T> *x) const {
  if (x->right != NULL)
    return minimum(x->right);

  RBTNode<T> *y = x->parent;
  while ((y != NULL) && (x == y->right)) {
    x = y;
    y = y->parent;
  }

  return y;
}

template <class T> RBTNode<T> *RBTree<T>::predecessor(RBTNode<T> *x) const {
  if (x->left != NULL)
    return maximum(x->left);

  RBTNode<T> *y = x->parent;
  while ((y != NULL) && (x == y->left)) {
    x = y;
    y = y->parent;
  }

  return y;
}

template <class T>
void RBTree<T>::removeFixUp(RBTNode<T> *&root, RBTNode<T> *node,
                            RBTNode<T> *parent) {
  RBTNode<T> *other;

  while ((!node || rb_is_black(node)) && node != root) {
    if (parent->left == node) {
      other = parent->right;
      if (rb_is_red(other)) {
        rb_set_black(other);
        rb_set_red(parent);
        leftRotate(root, parent);
        other = parent->right;
      }
      if ((!other->left || rb_is_black(other->left)) &&
          (!other->right || rb_is_black(other->right))) {
        rb_set_red(other);
        node = parent;
        parent = rb_parent(node);
      } else {
        if (!other->right || rb_is_black(other->right)) {
          rb_set_black(other->left);
          rb_set_red(other);
          rightRotate(root, other);
          other = parent->right;
        }
        rb_set_color(other, rb_color(parent));
        rb_set_black(parent);
        rb_set_black(other->right);
        leftRotate(root, parent);
        node = root;
        break;
      }
    } else {
      other = parent->left;
      if (rb_is_red(other)) {
        rb_set_black(other);
        rb_set_red(parent);
        rightRotate(root, parent);
        other = parent->left;
      }
      if ((!other->left || rb_is_black(other->left)) &&
          (!other->right || rb_is_black(other->right))) {
        rb_set_red(other);
        node = parent;
        parent = rb_parent(node);
      } else {
        if (!other->left || rb_is_black(other->left)) {
          rb_set_black(other->right);
          rb_set_red(other);
          leftRotate(root, other);
          other = parent->left;
        }
        rb_set_color(other, rb_color(parent));
        rb_set_black(parent);
        rb_set_black(other->left);
        rightRotate(root, parent);
        node = root;
        break;
      }
    }
  }
  if (node)
    rb_set_black(node);
}

template <class T> void RBTree<T>::remove(RBTNode<T> *&root, RBTNode<T> *node) {
  RBTNode<T> *child, *parent;
  RBTColor color;

  if ((node->left != NULL) && (node->right != NULL)) {
    RBTNode<T> *replace = node;

    replace = replace->right;
    while (replace->left != NULL)
      replace = replace->left;

    if (rb_parent(node)) {
      if (rb_parent(node)->left == node)
        rb_parent(node)->left = replace;
      else
        rb_parent(node)->right = replace;
    } else
      root = replace;

    child = replace->right;
    parent = rb_parent(replace);
    color = rb_color(replace);

    if (parent == node) {
      parent = replace;
    } else {
      if (child)
        rb_set_parent(child, parent);
      parent->left = child;

      replace->right = node->right;
      rb_set_parent(node->right, replace);
    }

    replace->parent = node->parent;
    replace->color = node->color;
    replace->left = node->left;
    node->left->parent = replace;

    if (color == BLACK)
      removeFixUp(root, child, parent);

    delete node;
    return;
  }

  if (node->left != NULL)
    child = node->left;
  else
    child = node->right;

  parent = node->parent;
  color = node->color;

  if (child)
    child->parent = parent;

  if (parent) {
    if (parent->left == node)
      parent->left = child;
    else
      parent->right = child;
  } else
    root = child;

  if (color == BLACK)
    removeFixUp(root, child, parent);
  delete node;
}

template <class T> void RBTree<T>::remove(T key) {
  RBTNode<T> *node;

  if ((node = search(root, key)) != NULL)
    remove(root, node);
}

template <class T> void RBTree<T>::destroy(RBTNode<T> *&tree) {
  if (tree == NULL)
    return;

  if (tree->left != NULL)
    return destroy(tree->left);
  if (tree->right != NULL)
    return destroy(tree->right);

  delete tree;
  tree = NULL;
}

template <class T> void RBTree<T>::destroy() { destroy(root); }

template <class T>
void RBTree<T>::print(RBTNode<T> *tree, T key, int direction) {
  if (tree != NULL) {
    if (direction == 0)
      cout << setw(2) << tree->key << "(B) is root" << endl;
    else
            cout << setw(2) << tree->key <<  (tree->color == RED)?"(R)":"(B)") << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

    print(tree->left, tree->key, -1);
    print(tree->right, tree->key, 1);
  }
}

template <class T> void RBTree<T>::print() {
  if (root != NULL)
    print(root, root->key, 0);
}
template <class T> void RBTree<T>::lRotate(RBTNode<T> *&root, RBTNode<T> *x) {
  // declear the right child of x as y
  RBTNode<T> *x_rc = x->rChild;

  // make the lChild of x->rChild as rChild of x
  x->rChild = x_rc->lChild;
  // if the lChile of x->rChild is not NULL , make x as parent of x_rc's lChild
  if (x_rc->lChild != NULL) {
    x_rc->lChild->parent = x;
  }
  // transfer x's parent to x_rc
  x_rc->parent = x->parent;

  // if x's parent is NULL, make x_rc as root
  if (x->parent == NULL) {
    root = x_rc;
  } else {
    // if x is its parent's lChild, use x_rc replace its position
    if (x->parent->lChild == x) {
      x->parent->lChild = x_rc;
    } else { // or rChild...
      x->parent->rChild = x_rc;
    }
  }

  // make x as x_rc's lChild
  x_rc->lChild = x_rc;
  // make x_rc as x's parent
  x->parent = x_rc;
}

template <class T> void RBTree<T>::rRotate(RBTNode<T> *&root, RBTNode<T> *x) {
  // declear the left child of x as y
  RBTNode<T> *x_lc = x->rChild;

  // make the rChild of x_lc as rChild of x
  x->lChild = x_lc->rChild;
  // if the rChile of x->x_lc is not NULL , make x as parent of x_rc's rChild
  if (x_lc->rChild != NULL) {
    x_lc->lChild->parent = x;
  }
  // transfer x's parent to x_rc
  x_lc->parent = x->parent;

  // if x's parent is NULL, make x_lc as root
  if (x->parent == NULL) {
    root = x_lc;
  } else {
    // if x is its parent's rChild, use x_lc replace its position
    if (x->parent->rChild == x) {
      x->parent->rChild = x_lc;
    } else { // or lChild...
      x->parent->lChild = x_lc;
    }
  }

  // make x as x_lc's rChild
  x_lc->rChild = x;
  // make x_rc as x's parent
  x->parent = x_lc;
}

template <class T> void insert(T key) {
  RBTNode<T> *z = NULL;
  if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL) {
    return;
  }
  insert(root, z);
}

template <class T> void insert(RBTNode<T> *&root, RBTNode<T> *node) {
  RBTNode<T> *y = NULL;
  RBTNode<T> *x = root;

  // BST searching
  while (x != NULL) {
    y = x;
    if (node->key < x->key) {
      x = x->lChild;
    } else {
      x = x->rChild;
    }
    node->parent = y;
  }

  if (y != NULL) {
    if (node->key < y->key) {
      y->lChild = node;
    } else {
      y->rChild = node;
    }
  } else {
    root = node;
  }

  // set the corlor to RED
  node->color = RED;
  // fix up the tree
  insertFixUp(root, node);
}

template <class T> void insertFixUp(RBTNode<T> *&root, RBTNode<T> *node) {
  RBTNode<T> *parent, *gparent;

  // if there is parent with red:
  while ((parent = node->parent) && (parent->color == RED)) {
    gparent = parent->parent;
    // if parent is lChild of gparent
    if (parent == gparent->lChild) {
      // case 1: uncle is RED
      RBTNode<T> *uncle = gparent->rChild;
      if (uncle && uncle->color == RED) {
        uncle->color = BLACK;
        parent->color = BLACK;
        gparent->color = RED;
        node = gparent;
        continue;
      }
      // case 2: uncle is black nad current node is right child
      if (parent->rChild == node) {
        RBTNode<T> *tmp;
        lRotate(root, parent);
        tmp = parent;
        parent = node;
        node = tmp;
      }
      // case 3: uncle is black and current node is left child
      parent->color = BLACK;
      parent->color = RED;
      rRotate(root, gparent);
    } else {
      // if z's parent is right child of z's grand gparent
      RBTNode<T> *uncle = gparent->left;
      // case 1: if uncle is red
      if (uncle && (uncle->color == RED)) {
        uncle->color = BLACK;
        parent->color = BLACK;
        gparent->color = RED;
        node = gparent;
        continue;
      }

      // case 2: if uncle is black and current node is left child
      if (parent->lChild == node) {
        RBTNode<T> *tmp;
        rRotate(root, parent);
        tmp = parent;
        parent = node;
        node = tmp;
      }

      // case 3: right child
      parent->color = BLACK;
      gparent->color = RED;
      lRotate(root, gparent);
    }
  }
  // set the root as BLACK
  root->color = BLACK;
}
