#include <iostream>
#include <cstring>
#pragma once

using namespace std;

class media {
 public:
  media();
  virtual void setTitle(char *t);
  virtual char* getTitle();
  virtual void setYear(int y);
  virtual int getYear();
 public:
  char *title;
  int year;
};
