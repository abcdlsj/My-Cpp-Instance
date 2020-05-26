#ifndef DATA_STRUCTURES_BTREE
#define DATA_STRUCTURES_BTREE

#include <iostream>
#include <utility>

class BTreeNode {
private:
  // array of keys
  int *keys;

  // Minimum degree
  int t;

  // array of child pointers
  BTreeNode **C;

  // number of keys
  int n;

  // true:is leaf
  bool leaf;

public:
  BTreeNode(int _t, bool _leaf);

  void insertNonFull(int k);

  void splitChild(int i, BTreeNode *y);

  void traverse();

  BTreeNode *search(int k);

  friend class BTree;
};

class BTree {
  BTreeNode *root;
  int t;

public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  };

  void traverse() {
    if (root != NULL) {
      return root->traverse();
    }
    return;
  }

  BTreeNode *search(int k) {
    if (root == NULL) {
      return NULL;
    }
    return root->search(k);
  }

  void insert(int k);
};

BTreeNode::BTreeNode(int _t, bool _leaf) {
  t = _t;
  leaf = _leaf;

  keys = new int[2 * t - 1];
  C = new BTreeNode *[2 * t];

  n = 0;
}

void BTreeNode::traverse() {

  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false) {
      C[i]->traverse();
    }
    std::cout << " " << keys[i];
  }

  if (leaf == false) {
    C[i]->traverse();
  }
}

BTreeNode *BTreeNode::search(int k) {
  int i = 0;
  while (i < n && k > keys[i]) {
    i++;
  }

  if (keys[i] == k) {
    return this;
  }

  if (leaf == true) {
    return NULL;
  }

  return C[i]->search(k);
}

void BTree::insert(int k) {
  if (root == NULL) {

    root = new BTreeNode(t, true);
    root->keys[0] = k;
    root->n = 1;

  } else if (root->n == 2 * t - 1) {

    BTreeNode *s = new BTreeNode(t, false);
    s->C[0] = root;
    s->splitChild(0, root);

    int i = 0;
    if (s->keys[0] < k) {
      i++;
    }
    s->C[i]->insertNonFull(k);

    root = s;

  } else {
    root->insertNonFull(k);
  }
}

void BTreeNode::insertNonFull(int k) {
  int i = n - 1;

  if (leaf == true) {
  }
}

#endif // !DATA_STRUCTURES_BTREE_H