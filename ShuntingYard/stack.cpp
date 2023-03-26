#include <iostream>
#include "node.h"
#include "stack.h"

using namespace std;

Stack::Stack() {
  top = NULL;
}

void Stack::push(char n) {

  Node* temp = new Node(n);

  temp->next = top;
  top = temp;
}

void Stack::pop() {

  if(top == NULL) {
    cout << "Stack underflow" << endl;
    return;
  } else {
    Node* temp = top;
    top = top->next;
    free(temp);
  }
}

char Stack::peek() {

  if(top == NULL) {
    return 'x';
  } else {
    return top->value;
  }
  return top->value;
}

void Stack::display() {

  Node* temp;

  if(top == NULL) {
    cout << "Stack underflow" << endl;
    return;
  } else {
    temp = top;
    while(temp != NULL) {
      cout << temp->value << " ";
      temp = temp->next;
    }
  }
}
