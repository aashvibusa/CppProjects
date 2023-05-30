#include <iostream>
#include "node.h"

using namespace std;

Node::Node(int v) {
  value = v;
  color = 'B';
  parent = NULL;
  right = NULL;
  left = NULL;
}
