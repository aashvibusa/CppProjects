#include <iostream>

using namespace std;

class Node {
 public:
  Node(int v);
 public:
  int value;
  Node* left;
  Node* right;
};
