#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

int add(vector<item*> &x, char *d);

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

  //Set starting room to entrance hall and print welcome message
  cout << "Welcome to the Shire!" << endl;
  cout << "Find all the items to get ready for an adventure." << endl;
  cout << "Type 'help' if you need help." << endl;
  cout << " " << endl;
  room *current_room;
  current_room = entrance_hall;
  cout << "You are " << entrance_hall->getDescription() << endl;
  current_room->getRoomDetails();

  //Initialize items
  smoking_room->setItem("pipe");
  parlour->setItem("ring");
  study->setItem("book");
  pantry->setItem("seedcake");
  back_room->setItem("handkerchief");

  vector<item*> inventory;
  //char* ItemRing

  //Start play sequence
  bool stillPlaying = true;

  while(stillPlaying) {

    //Win condition: find all the items
    if(inventory.size() == 5) {
      cout << "Great job you found all the items! You are now ready to go on an adventure." << endl;
      stillPlaying = false;
    }

    //Get user input
    char in[40];
    cout << "> ";
    cin.get(in, 40);
    cin.get();

    //Execute command based on user input
    if(strcmp(in, "help") == 0) {
      cout << "You are lost and in need of assistance." << endl;
      cout << "Your command words are: go get drop inventory help quit" << endl;
    } else if(strcmp(in, "inventory") == 0) {
      if(!inventory.empty()) {
	cout << "You are carrying: ";
	for(int i = 0; i < inventory.size(); i++) {
	  cout << inventory.at(i)->description << " ";
	}
	cout << " " << endl;
      } else {
	cout << "You currently have no items in your inventory." << endl;
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
    } else {
      
      //Split commands with two words
      char *token = strtok(in, " ");
      char *firstWord;
      char *secondWord;
      int count = 1;
      while(token != NULL) {
	if(count == 1) {
	  firstWord = token;
        }
	if(count == 2) {
	  secondWord = token;
	}
	token = strtok(NULL, " ");
	count++;
      }

      //Execute command based on user input
      if(strcmp(firstWord, "go") == 0) {
	current_room = current_room->getExit(secondWord);
	cout << " " << endl;
	cout << "You are " << current_room->getDescription() << endl;
	current_room->getRoomDetails();
      } else if(strcmp(firstWord, "get") == 0) {
	current_room->removeItem(secondWord);
	item *i = new item;
	if(strcmp("pipe", secondWord) == 0) {
	  i->description = "pipe";
	  inventory.push_back(i);
	} else if(strcmp("ring", secondWord) == 0) {
	  i->description = "ring";
	  inventory.push_back(i);
	} else if(strcmp("book", secondWord) == 0) {
	  i->description = "book";
	  inventory.push_back(i);
	} else if(strcmp("seedcake", secondWord) == 0) {
	  i->description = "seedcake";
	  inventory.push_back(i);
	} else if(strcmp("handkerchief", secondWord) == 0) {
	  i->description = "handkerchief";
	  inventory.push_back(i);
	}
      } else if(strcmp(firstWord, "drop") == 0) {
	current_room->setItem(secondWord);
	bool there = false;
	if(!inventory.empty()) {
	  for(vector<item*>::iterator it = inventory.begin() ; it != inventory.end(); )
	    if(strcmp((*it)->description, secondWord) == 0) {
	      there = true;
	      inventory.erase(it);
	    }
	
	  if(there) {
	    cout << "Dropped: " << secondWord << endl;
	  } else {
	    cout << "You do not have that item in your inventory." << endl;
	  }
	} else {
	  cout << "You currently have no items in your inventory." << endl;
	}
      }
    }
  }
  return 0;
}



