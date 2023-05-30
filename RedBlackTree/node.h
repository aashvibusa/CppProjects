#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
 public:
  Node(int v);
 public:
  int value;
  char color;
  Node* parent;
  Node* right;
  Node* left;
};
#endif
