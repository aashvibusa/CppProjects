#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include "room.h" 

using namespace std;

struct item;

room::room() {
  roomDescription = new char[100];
  itemDescription = new char[100];
  direction = new char[30];
}

room::room(const char *d) {
  roomDescription = new char[100];
  strcpy(roomDescription, d);
}

char* room::getDescription() {
  return roomDescription;
}

void room::setExit(const char *dir, room *r) {
  direction = new char[30];
  strcpy(direction, dir);
  exits[direction] = r;
}

room* room::getExit(const char *dir) {
  direction = new char[30];
  strcpy(direction, dir);
  return exits.at(direction);
}

void room::setItem(const char *n) {
  itemDescription = new char[100];
  strcpy(itemDescription, n);
  item *i = new item;
  i->description = itemDescription;
  itemsList.push_back(i);
}

void room::removeItem(const char *n) {
  if(itemsList.size() != 0) {
    for(vector<item*>::iterator it = itemsList.begin() ; it != itemsList.end(); )
      if(strcmp((*it)->description, n) == 0) {
	itemsList.erase(it);
      }
  } else {
    cout << "That item is not here!" << endl;
  }
}

void room::getRoomDetails() {
  cout << "Exits: ";
  for(auto i = exits.begin(); i != exits.end(); i++)
    cout << i->first << ", ";

  cout << "Items: ";
  if(itemsList.size() != 0) {
    for(int i = 0; i < itemsList.size(); i++) {
      cout << itemsList.at(i)->description;
    }
  }
}
