#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movies : public media {
 public:
  movies();
  virtual void setDirector(char *d);
  virtual char* getDirector();
  virtual void setDuration(int d);
  virtual int getDuration();
  virtual void setRating(int r);
  virtual int getRating();
 public:
  char *director;
  int duration;
  int rating;
};
