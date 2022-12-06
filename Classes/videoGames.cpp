#include <iostream>
#include <cstring>
#include "videoGames.h"

using namespace std;

//Main videoGames function
videoGames::videoGames() {
  publisher = new char[40];
}

//Getters and setters
void videoGames::setPublisher(char *p) {
  publisher = new char[40];
  strcpy(publisher, p);
}

char* videoGames::getPublisher() {
  return publisher;
}

void videoGames::setRating(int r) {
  rating = r;
}

int videoGames::getRating() {
  return rating;
}
