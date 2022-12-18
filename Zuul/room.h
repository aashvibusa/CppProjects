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
  room(char*);
  char* getDescription();
  void setExit(char *dir, room *r);
  room* getExit(char *dir);
  void setItem(char *n);
  void removeItem(char *n);
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
