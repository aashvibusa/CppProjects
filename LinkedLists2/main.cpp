#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

/*
 * This program allows a user to add students to a linked list and print the list
 * Author: Aashvi Busa
 * Date: 1/29/23
 */

//Function prototypes
void add(Student* newStudent, Node*& h, Node* p, Node* c);
void print(Node* next, Node* h);

int main() {

  //Initialize variables
  Node* head = NULL;
  char* command = new char[10];
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    cout << "Enter a command: ";
    cin.get(command, 10);
    cin.get();

    //Execute function according to corresponding input
    if(strcmp(command, "add") == 0) {
      
      char* firstName = new char[40];
      char* lastName = new char[40];
      int id = 0;
      float gpa = 0.0f;
      
      cout << "Enter a first name: ";
      cin.get(firstName, 40);
      cin.get();
      cout << "Enter a last name: ";
      cin.get(lastName, 40);
      cin.get();
      cout << "Enter a student ID: ";
      cin >> id;
      cin.get();
      cout << "Enter a GPA: ";
      cin >> gpa;

      Student* s = new Student();
      s->setName(firstName);
      s->setLastName(lastName);
      s->setId(id);
      s->setGpa(gpa);

      add(s, head, head, head);
      
      cout << s->getName() << " " << s->getLastName() << " has been added." << endl;
      cout << " " << endl;
      cin.get();
      
    } else if(strcmp(command, "print") == 0) {
      
      print(head, head);
      cout << " " << endl;
      
    } else if(strcmp(command, "quit") == 0) {
      cont = false;
    } else {
      cout << "Invalid command" << endl;
    }
  }

  return 0;
}

//Add a new node to the linked list
void add(Student* newStudent, Node*& h, Node* p, Node* c) {

  if(h == NULL) {
    h = new Node(newStudent);
  } else if(newStudent->getId() < h->getStudent()->getId()) {
    Node* temp = h;
    h = new Node(newStudent);
    h->setNext(temp);
  } else if(c == NULL) {
    p->setNext(new Node(newStudent));
    p->getNext()->setNext(NULL);
  } else if(newStudent->getId() < c->getStudent()->getId()) {
    Node* newNode = new Node(newStudent);
    p->setNext(newNode);
    newNode->setNext(c);
  } else {
    add(newStudent, h, c, c->getNext());
  }
}

//Print the linked list
void print(Node* next, Node* h) {
  if(next != NULL) {
    Student* s = next->getStudent();
    cout << s->getName() << " " << s->getLastName() << ", " << s->getId() << ", " << fixed << setprecision(2) << s->getGpa() << endl;
    print(next->getNext(), h);
  }
}
