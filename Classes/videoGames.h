#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videoGames : public media {
 public:
  videoGames();
  virtual void setPublisher(char *p);
  virtual char* getPublisher();
  virtual void setRating(int r);
  virtual int getRating();
 public:
  char *publisher;
  int rating;
};
