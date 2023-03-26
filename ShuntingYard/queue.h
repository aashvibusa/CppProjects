#include <iostream>
#include "node.h"

using namespace std;

class Queue {
 public:
  Queue();
  void enqueue(char n);
  void dequeue();
  char* display();
 public:
  Node* front;
  Node* rear;
};
