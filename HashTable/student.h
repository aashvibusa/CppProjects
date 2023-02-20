#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  Student();
  void setName(char* f);
  char* getName();
  void setLastName(char* l);
  char* getLastName();
  void setId(int i);
  int getId();
  void setGpa(float g);
  float getGpa();
 private:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};
#endif
