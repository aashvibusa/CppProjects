#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(char n) {
  value = n;
  next = NULL;
  right = NULL;
  left = NULL;
}

Node::~Node() {
  delete &value;
  next = NULL;
}

char Node::getValue() {
  return value;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node* Node::getNext() {
  return next;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

Node* Node::getRight() {
  return right;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

Node* Node::getLeft() {
  return left;
}
