#include <iostream>
#include <cstring>
#include "hash.h"
#include "student.h"

using namespace std;

/*
 * This program allows a user to add (through a generator or manually), delete, and print students stored in a hash table
 * Author: Aashvi Busa
 * Date: 2/19/23
 */

int main() {

  //Initialize variables
  Hash h;
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

      //Initialize variables
      char* firstName = new char[40];
      char* lastName = new char[40];
      int id = 0;
      float gpa = 0.0f;

      //Get property inputs
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

      //Add properties to a new Student
      Student* s = new Student();
      s->setName(firstName);
      s->setLastName(lastName);
      s->setId(id);
      s->setGpa(gpa);
      h.add(s->getId(), s);

      cout << s->getName() << " " << s->getLastName() << " has been added." << endl;
      cout << " " << endl;
      cin.get();

    } else if(strcmp(command, "print") == 0) {
      h.print();

    } else if(strcmp(command, "quit") == 0) {
      cont = false;

    } else if(strcmp(command, "delete") == 0) {
      int in = 0;
      cout << "Enter an id number to delete: ";
      cin >> in;
      cin.get();
      h.del(in);

    } else {
      cout << "Invalid command" << endl;
      cout << " " << endl;
    }
  }
  return 0;
}
