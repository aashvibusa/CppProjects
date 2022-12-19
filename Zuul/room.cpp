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
  itemDescription = new char[100];
  direction = new char[30];
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
  direction = new char[10];
  strcpy(direction, dir);
  for(auto i = exits.begin(); i != exits.end(); i++)
    if(strcmp(i->first, direction) == 0) {
      return exits.at(i->first);
    }
  cout << "There is no exit there!" << endl; 
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
  bool there = false;
  if(!itemsList.empty()) {
    for(vector<item*>::iterator it = itemsList.begin() ; it != itemsList.end(); )
      if(strcmp((*it)->description, n) == 0) {
	cout << "Picked up: " << (*it)->description << endl;
	itemsList.erase(it);
	there = true;
      }
  } else {
    if(!there) {
      cout << "That item is not here!" << endl;
    }
  }
}

void room::getRoomDetails() {

  cout << "Exits: ";
  for(auto i = exits.begin(); i != exits.end(); i++)
    cout << i->first << " ";

  cout << " " << endl;
  cout << "Items: ";
  if(itemsList.size() != 0) {
    for(int i = 0; i < itemsList.size(); i++) {
      cout << itemsList.at(i)->description;
    }
    cout << " " << endl;
  } else {
    cout << "none" << endl;
  }
}
