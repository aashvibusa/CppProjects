#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student* newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNext);
 private:
  Student* student;
  Node* next;
};
#endif
