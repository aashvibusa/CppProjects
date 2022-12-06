#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

//Main movies function
movies::movies() {
  director = new char[40];
}

//Getters and setters
void movies::setDirector(char *d) {
  director = new char[40];
  strcpy(director, d);
}

char* movies::getDirector() {
  return director;
}

void movies::setDuration(int d) {
  duration = d;
}

int movies::getDuration() {
  return duration;
}

void movies::setRating(int r) {
  rating = r;
}

int movies::getRating() {
  return rating;
}
