#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(char n);
  ~Node();
  char getValue();
  void setNext(Node* newNext);
  Node* getNext();
  void setRight(Node* newRight);
  Node* getRight();
  void setLeft(Node* newLeft);
  Node* getLeft();
 public:
  char value;
  Node* next;
  Node* right;
  Node* left;
};
#endif
