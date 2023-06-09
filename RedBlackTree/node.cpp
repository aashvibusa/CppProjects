#include <iostream>
#include "node.h"

using namespace std;

Node::Node() {
  value = 0;
  color = 'B';
  parent = NULL;
  right = NULL;
  left = NULL;
}

void Node::setValue(int v) {
  value = v;
}

int Node::getValue() {
  return value;
}
