#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student() {
  firstName = new char[40];
}

void Student::setFirstName(char* a) {
  firstName = new char[40];
  strcpy(firstName, a);
}

char* Student::getFirstName() {
  return firstName;
}
