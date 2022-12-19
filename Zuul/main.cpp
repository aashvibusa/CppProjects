#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

int main() {
  
  //Create the rooms
  room *entrance_hall = new room("in the entrance hall of Bilbo's house at Bag End.");
  room *oak_hall = new room("in oak hall.");
  room *parlour = new room("in the parlour. The fireplace is on. Nice and toasty.");
  room *east_hall = new room("in east hall.");
  room *smoking_room = new room("in the smoking room. What a fine collection of cigars.");
  room *spare_room = new room("in the spare room.");
  room *kitchen = new room("in the kitchen. Something smells delicious.");
  room *dining_room = new room("in the dining room.");
  room *pantry = new room("in the pantry. What an enormous amount of food for a single Hobbit.");
  room *cellar = new room("in the cellar.");
  room *atrium = new room("in the atrium. That couch looks too comfortable.");
  room *storage = new room("in the storage. Wow, there is a lot of stuff in here.");
  room *study = new room("in the study. The desk is very messy, someone must have been busy.");
  room *bedroom = new room("in the bedroom.");
  room *west_hall = new room("in west hall.");
  room *back_hall = new room("in the back hall. It looks like the back door is locked.");
  room *guest_room = new room("in the guest room. You can certainly fit 13 dwarves and a wizard here.");
  room *back_room = new room("in the back room.");

  //Initialize room exits
  entrance_hall->setExit("north", oak_hall);
  entrance_hall->setExit("west", parlour);

  oak_hall->setExit("north", smoking_room);
  oak_hall->setExit("south", entrance_hall);
  oak_hall->setExit("east", spare_room);
  oak_hall->setExit("west", east_hall);

  parlour->setExit("north", east_hall);
  parlour->setExit("east", entrance_hall);
  parlour->setExit("west", kitchen);

  east_hall->setExit("south", parlour);
  east_hall->setExit("east", oak_hall);
  east_hall->setExit("west", atrium);

  smoking_room->setExit("south", oak_hall);
  smoking_room->setExit("west", pantry);

  spare_room->setExit("west", oak_hall);

  kitchen->setExit("east", parlour);
  kitchen->setExit("west", dining_room);

  dining_room->setExit("east", kitchen);
  dining_room->setExit("north", atrium);

  pantry->setExit("north", cellar);
  pantry->setExit("south", atrium);
  pantry->setExit("east", smoking_room);
  pantry->setExit("west", storage);

  cellar->setExit("south", pantry);
  cellar->setExit("west", storage);

  atrium->setExit("north", pantry);
  atrium->setExit("south", dining_room);
  atrium->setExit("east", east_hall);
  atrium->setExit("west", west_hall);

  storage->setExit("north", cellar);
  storage->setExit("east", pantry);
  storage->setExit("west", back_room);

  study->setExit("west", bedroom);

  bedroom->setExit("east", study);
  bedroom->setExit("west", back_hall);

  west_hall->setExit("north", back_room);
  west_hall->setExit("south", back_hall);
  west_hall->setExit("east", atrium);
  west_hall->setExit("west", guest_room);

  back_hall->setExit("north", west_hall);
  back_hall->setExit("east", bedroom);

  guest_room->setExit("east", west_hall);

  back_room->setExit("south", west_hall);
  back_room->setExit("east", storage);

  //Set starting room to entrance hall
  room *current_room;
  current_room = entrance_hall;

  //Initialize items
  smoking_room->setItem("pipe");
  parlour->setItem("ring");
  study->setItem("book");
  pantry->setItem("seedcake");
  back_room->setItem("handkerchief");

  vector<item*> inventory;

  //Start play sequence
  bool stillPlaying = true;

  while(stillPlaying) {

    char in[40];
    cout << "Enter a command: ";
    cin.get(in, 40);
    cin.get();

    
    if(strcmp(in, "help") == 0) {
      cout << "You are lost and in need of assistance." << endl;
      cout << "Your command words are: go get drop inventory help quit" << endl;
    } else if(strcmp(in, "inventory") == 0) {
      cout << "You are carrying: " << endl;
      for(int i = 0; i < inventory.size(); i++) {
	cout << inventory.at(i) << " "; 
      }
    } else if(strcmp(in, "quit") == 0) {
      cout << "Thank you for playing. Goodbye." << endl;
      stillPlaying = false;
    } else if(strcmp(in, "go") == 0) {
      cout << "Go where?" << endl;
    } else if(strcmp(in, "get") == 0) {
      cout << "Get what?" << endl;
    } else if(strcmp(in, "drop") == 0) {
      cout << "Drop what?" << endl;
    }
  }
}



