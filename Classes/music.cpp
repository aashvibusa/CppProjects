#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//Main music function
music::music() {
  artist = new char[40];
  publisher = new char[40];
}

//Getters and setters
void music::setArtist(char *a) {
  artist = new char[40];
  strcpy(artist, a);
}

char* music::getArtist() {
  return artist;
}

void music::setDuration(int d) {
  duration = d;
}

int music::getDuration() {
  return duration;
}

void music::setPublisher(char *p) {
  publisher = new char[40];
  strcpy(publisher, p);
}

char* music::getPublisher() {
  return publisher;
}
