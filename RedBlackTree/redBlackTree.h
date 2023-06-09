#include <iostream>
#include "node.h"

using namespace std;

class RedBlackTree {
 public:
  Node* root;
  Node* N;
 public:
  RedBlackTree();
  void rotateRight(Node* a);
  void rotateLeft(Node* a);
  void add(int v);
  void transplant(Node* x, Node* y);
  void del(int v);
};
