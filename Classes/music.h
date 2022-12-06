#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media {
 public:
  music();
  virtual void setArtist(char *a);
  virtual char* getArtist();
  virtual void setDuration(int d);
  virtual int getDuration();
  virtual void setPublisher(char *p);
  virtual char* getPublisher();
 public:
  char *artist;
  int duration;
  char *publisher;
};
