#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student* newStudent, int k) {
  student = newStudent;
  key = k;
  next = NULL;
}

Node::~Node() {
  delete &student;
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
