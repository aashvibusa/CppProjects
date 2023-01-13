#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

/*
 * This program allows a user to add students to a linked list and print the list
 * Author: Aashvi Busa
 * Date: 1/13/23
 */

//Function prototypes
void add(Student* newStudent, Node*& h);
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
      char* name = new char[40];
      cout << "Enter a name: ";
      cin.get(name, 40);
      cin.get();
      Student* s = new Student();
      s->setFirstName(name);
      add(s, head);
    } else if(strcmp(command, "print") == 0) {
      print(head, head);
      cout << " " << endl;
    } else if(strcmp(command, "quit") == 0) {
      cont = false;
    }
  }
  
  return 0;
}

//Add a new node to the linked list
void add(Student* newStudent, Node*& h) {
  Node* current = h;
  if(current == NULL) {
    h = new Node(newStudent);
  } else {
    while(current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
  }
}

//Print the linked list
void print(Node* next, Node* h) {
  if(next == h) {
    cout << "students: ";
  }
  if(next != NULL) {
    Student* s = next->getStudent();
    cout << s->getFirstName() << " ";
    print(next->getNext(), h);
  }
}
