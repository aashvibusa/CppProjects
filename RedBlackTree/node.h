#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  void setValue(int v);
  int getValue();
 public:
  int value;
  char color;
  Node* parent;
  Node* right;
  Node* left;
};
#endif
