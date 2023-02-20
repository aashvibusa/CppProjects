#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student() {
  firstName = new char[40];
  lastName = new char[40];
}

void Student::setName(char* f) {
  firstName = new char[40];
  strcpy(firstName, f);
}

char* Student::getName() {
  return firstName;
}

void Student::setLastName(char* l) {
  lastName = new char[40];
  strcpy(lastName, l);
}

char* Student::getLastName() {
  return lastName;
}

void Student::setId(int i) {
  id = i;
}

int Student::getId() {
  return id;
}

void Student::setGpa(float g) {
  gpa = g;
}

float Student::getGpa() {
  return gpa;
}
