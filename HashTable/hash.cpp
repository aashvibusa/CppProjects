#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "hash.h"
#include "node.h"
#include "student.h"

using namespace std;

Hash::Hash() {
  buckets = 100;
  table = new Node*[buckets];

  for(int i = 0; i < buckets; i++) {
    table[i] = NULL;
  }
}

//Hash function 
int Hash::hashFunction(int k) {
  return (k % buckets);
}

//Add a student to the hash table and check for rehash
void Hash::add(int k, Student *s) {
  int chain = 0;
  int index = hashFunction(k);

  Node *current = table[index];
  if(table[index] != NULL) {
    while(current != NULL) {
      current = current->getNext();
      chain++;
    }
  } 
  
  if(chain == 3) {
    rehash();
    add(k, s);
  } else {
    if(table[index] == NULL) {
      Node *newNode = new Node(s, k);
      table[index] = newNode;
    } else {
      Node *current = table[index];
      while(current->getNext() != NULL) {
	current = current->getNext();
      }
      Node *newNode = new Node(s, k);
      current->setNext(newNode);
    }
  }
}

//Delete a student from the hash table
void Hash::del(int k) {
  int index = hashFunction(k);
  Node *current = table[index];

  if(table[index] == NULL) {
    cout << "That student is not in the list!" << endl;
  } else {
    while(current->getStudent()->getId() != k && current != NULL) {
      current = current->getNext();
    }
    if(table[index]->getNext() == NULL) {
      table[index] = NULL;
    } else if(table[index] == current) {
      current = table[index]->getNext();
      table[index] = current;
    } else if(current != NULL) {
      if(current->getNext() == NULL) {
	Node *temp = table[index];
	while(temp->getNext()->getNext() != NULL) {
	  temp = temp->getNext();
	}
	Node *last = temp->getNext();
	temp->setNext(NULL);
	free(last);
      } else {
	Node *temp = current->getNext();
	delete current;
	current = temp;
      }
    } else {
      cout << "That student is not in this list!" << endl;
    } 
  }
}

//Rehash exsiting hash table
void Hash::rehash() {
  int oldCapacity = buckets;
  Node **temp = table;

  buckets = oldCapacity * 2;
  table = new Node*[buckets];

  for(int i = 0; i < buckets; i++) {
    table[i] = NULL;
  }

  for(int i = 0; i < oldCapacity; i++) {
    Node *current = temp[i];
    while(current != NULL) {
      add(current->getStudent()->getId(), current->getStudent());
      current = current->getNext();
    }
  }

  delete[] temp;
}

//Print the hash table
void Hash::print() {
  cout << " " << endl;
  for(int i = 0; i < buckets; i++) {
    Node *current = table[i];
    if(current != NULL) {
      cout << "index: " << i << endl;
      while(current != NULL) {
	cout << current->getStudent()->getName() << " " << current->getStudent()->getLastName() << ", " << current->getStudent()->getId() << ", " << fixed << setprecision(2) << current->getStudent()->getGpa() << endl;
	current = current->getNext();
      }
      cout << " " << endl;
    }
  }
}
