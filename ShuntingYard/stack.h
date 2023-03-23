#include <iostream>
#include "node.h"

using namespace std;

class Stack {
 public:
  Stack();
  void push(char n);
  void pop();
  char peek();
  void display();
 private:
  Node* top;
};
