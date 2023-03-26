#include <iostream>
#include "node.h"
#include "queue.h"

using namespace std;

Queue::Queue() {
  front = NULL;
  rear = NULL;
}

void Queue::enqueue(char n) {

  Node* temp = new Node(n);

  if(rear == NULL) {
    front = temp;
    front->next = NULL;
    rear = temp;
    rear->next = NULL;
    return;
  } else {
    rear->next = temp;
    temp->next = NULL;
    rear = temp;
  }
}

void Queue::dequeue() {

  if(front == NULL) {
    return;
  }

  Node* temp = front;
  front = front->next;

  if(front == NULL) {
    rear = NULL;
  }

  free(temp);
}

char* Queue::display() {

  Node* temp = front;
  char* postfix = new char[40];
  int index = 0;

  while(temp != NULL) {
    postfix[index] = temp->value;
    temp = temp->next;
    index++;
  }

  return postfix;
}
