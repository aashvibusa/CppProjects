#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

struct item {
  char *description;
};

class room {
 public:
  room();
  room(const char*);
  char* getDescription();
  void setExit(const char *dir, room *r);
  room* getExit(const char *dir);
  void setItem(const char *n);
  void removeItem(const char *n);
  void getRoomDetails();
 public:
  vector<item*> itemsList;
  unordered_map<char*, room*> exits;
  char *roomDescription;
  char *itemDescription;
  char *direction;
  room *roo;
  char *itemName;
};
