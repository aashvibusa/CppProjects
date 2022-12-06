#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

//Main media function
media::media() {
  title = new char[40];
}

//Getters and setters
void media::setTitle(char *t) {
  title = new char[40];
  strcpy(title, t);
}

char* media::getTitle() {
  return title;
}

void media::setYear(int y) {
  year = y;
}

int media::getYear() {
  return year;
}
