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
    rear = temp;
    return;
  }

  rear->next = temp;
  rear = temp;
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

  delete(temp);
}
