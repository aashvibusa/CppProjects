#include <iostream>
#include <cstring>
#include <fstream>
#include "hash.h"
#include "student.h"

using namespace std;

/*
 * This program allows a user to add (through a generator or manually), delete, and print students stored in a hash table
 * Referenced LinkedLists2 project
 * First names from: https://www.usna.edu/Users/cs/roche/courses/s15si335/proj1/files.php%3Ff=names.txt.html
 * Last names from: https://www.powershellgallery.com/packages/TelligentCommunitySample/0.1.1/Content/Surnames.txt
 * Author: Aashvi Busa
 * Date: 2/19/23
 */

int main() {

  //Initialize variables
  Hash h;
  char* command = new char[10];
  bool cont = true;
  int randId = 1;

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
      cout << " " << endl;
      
    } else if(strcmp(command, "random") == 0) {

      //Initialize variables
      char* tempFirstName = new char[40];
      char* tempLastName = new char[40];
      int randomNum1;
      int randomNum2;
      float randomGpa;

      //Get user input
      int in = 0;
      cout << "Enter the number of students to generate: ";
      cin >> in;
      cin.get();

      //Add random students
      srand (time(NULL));
      for(int i = 0; i < in; i++) {

	Student* s = new Student();

	ifstream firstNames("firstNames.txt");
	randomNum1 = 1 + (rand() % 100);
	for(int j = 0; j < randomNum1; j++) {
	  firstNames.getline(tempFirstName, 40);
	}
	s->setName(tempFirstName);
	firstNames.close();

	ifstream lastNames("lastNames.txt");
	randomNum2 = 1 + (rand() % 100);
	for(int j = 0; j < randomNum2; j++) {
	  lastNames.getline(tempLastName, 40);
	}
	s->setLastName(tempLastName);
	lastNames.close();

	s->setId(randId);
	randId++;

	randomGpa = (float)(rand() % 501) / 100;
	s->setGpa(randomGpa);

	h.add(s->getId(), s);
      }

      cout << "The students have been added to the list." << endl;
      cout << " " << endl;

    } else {
      cout << "Invalid command" << endl;
      cout << " " << endl;
    }
  }
  return 0;
}
