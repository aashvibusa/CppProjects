#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

/*
 * This program allows a user to add students to a list, delete them from it, or print out the list
 * Author: Aashvi Busa
 * Date: 11/04/22
 */

//Define Student struct
struct Student {
  char firstName[30];
  char lastName[30];
  int id;
  float gpa;
};

//Function prototypes
int add(vector<Student*> &x);
int print(vector<Student*> &x);
int del(vector<Student*> &x);

int main() {

  //Initialize vector and variables
  vector<Student*> list;
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    char in[30];
    cout << "Enter a command: ";
    cin.get(in, 30);
    cin.get();

    for(int i = 0; i < strlen(in); i++) in[i] = toupper(in[i]);

    //Execute function corresponding to input
    if(strcmp(in, "ADD") == 0) {
	add(list);
    } else if(strcmp(in, "PRINT") == 0) {
	print(list);
    } else if(strcmp(in, "DELETE") == 0) {
	del(list);
    } else if(strcmp(in, "QUIT") == 0) {
	cont = false;
    } else {
	cout << "Invalid input. Try again." << endl;
	cout << " " << endl;
    }
  }
  return 0;
}

//Add new student to list
int add(vector<Student*> &x) {
  Student* stu = new Student;

  //Get student property inputs
  cout << "Enter a first name: ";
  cin >> stu->firstName;
  cout << "Enter a last name: ";
  cin >> stu->lastName;
  cout << "Enter a student ID: ";
  cin >> stu->id;
  cout << "Enter a GPA: ";
  cin >> stu->gpa;
  cout << stu->firstName << " " << stu->lastName << " has been added." << endl;
  cout << " " << endl;
  cin.get();

  x.push_back(stu);
  return 0;
}

//Print out student(s) in list
int print(vector<Student*> &x) {
  for(vector<Student*>::iterator it = x.begin() ; it != x.end(); ++it)
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << fixed << setprecision(2) << (*it)->gpa << endl;
  cout << " " << endl;
  return 0;
}

//Delete student in list
int del(vector<Student*> &x) {
  int studentID;
  bool valid = false;
  cout << "Enter a student ID number to delete: ";
  cin >> studentID;
  cin.get();
  
  //Remove student if ID matches input
  for(vector<Student*>::iterator it = x.begin() ; it != x.end(); ++it)
    if(studentID == (*it)->id) {
      cout << (*it)->firstName << " " << (*it)->lastName << " has been deleted." << endl;
      x.erase(it);
      valid = true;
      break;
    }

  if(!valid) {
    cout << "Invalid ID number entered" << endl;
  }

  cout << " " << endl;
  return 0;
}
