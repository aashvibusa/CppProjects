#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  Student();
  void setFirstName(char* firstName);
  char* getFirstName();
 private:
  char* firstName;
};
#endif
