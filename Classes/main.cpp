#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "videoGames.h"
#include "music.h"
#include "movies.h"

using namespace std;

/*
 * This program allows a user to add, delete, and search through media in a database
 * Referenced Student List project
 * Author: Aashvi Busa
 * Data: 12/04/22
 */

//Function prototypes
int add(vector<media*> &x);
int search(vector<media*> &x);
int del(vector<media*> &x);

int main() {

  //Initialize vector and variables
  vector<media*> digMedia;
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    char in[30];
    cout << "Enter a command: ";
    cin.get(in, 30);
    cin.get();

    for(int i = 0; i < strlen(in); i++) in[i] = toupper(in[i]);

    //Execute function corresponding to input
    if(strcmp(in, "ADD") == 0) {
      add(digMedia);
    } else if(strcmp(in, "SEARCH") == 0) {
      search(digMedia);
    } else if(strcmp(in, "DELETE") == 0) {
      del(digMedia);
    } else if(strcmp(in, "QUIT") == 0) {
      cont = false;
    } else {
      cout << "Invalid input. Try again." << endl;
      cout << " " << endl;
    }
  }
  return 0;
}

//Add media types to the database
int add(vector<media*> &x) {

  //Get user input for media type
  char in[30];
  cout << "What type of media do you want to add: ";
  cin.get(in, 30);
  cin.get();

  for(int i = 0; i < strlen(in); i++) in[i] = tolower(in[i]);

  //Get video game property inputs
  if(strcmp(in, "video game") == 0) {
    videoGames* vid = new videoGames;
    char t[40];
    char p[40];
    int y;
    int r;
    
    cout << "Enter a title: ";
    cin.get(t, 40);
    vid->setTitle(t);
    cin.get();
    cout << "Enter a year: ";
    cin >> y;
    vid->setYear(y);
    cin.get();
    cout << "Enter a publisher: ";
    cin.get(p, 40);
    vid->setPublisher(p);
    cin.get();
    cout << "Enter a rating: ";
    cin >> r;
    vid->setRating(r);
    cout << vid->getTitle() << " has been added." << endl;
    cout << " " << endl;
    cin.get();
    
    x.push_back(vid);

  //Get music property inputs  
  } else if(strcmp(in, "music") == 0) {
    music* mus = new music;
    char t[40];
    char a[40];
    char p[40];
    int y;
    int d;
    
    cout << "Enter a title: ";
    cin.get(t, 40);
    mus->setTitle(t);
    cin.get();
    cout << "Enter an artist: ";
    cin.get(a, 40);
    mus->setArtist(a);
    cin.get();
    cout << "Enter a year: ";
    cin >> y;
    mus->setYear(y);
    cout << "Enter a duration (seconds): ";
    cin >> d;
    mus->setDuration(d);
    cin.get();
    cout << "Enter a publisher: ";
    cin.get(p, 40);
    mus->setPublisher(p);
    cin.get();
    cout << mus->getTitle() << " has been added." << endl;
    cout << " " << endl;

    x.push_back(mus);
    return 0;
    
  //Get movie property inputs  
  } else if(strcmp(in, "movie") == 0) {
    movies* mov = new movies;
    char t[40];
    char d[40];
    int y;
    int du;
    int r;
    
    cout << "Enter a title: ";
    cin.get(t, 40);
    mov->setTitle(t);
    cin.get();
    cout << "Enter a director: ";
    cin.get(d, 40);
    mov->setDirector(d);
    cin.get();
    cout << "Enter a year: ";
    cin >> y;
    mov->setYear(y);
    cout << "Enter a duration (minutes): ";
    cin >> du;
    mov->setDuration(du);
    cout << "Enter a rating: ";
    cin >> r;
    mov->setRating(r);
    cout << mov->getTitle() << " has been added." << endl;
    cout << " " << endl;
    cin.get();

    x.push_back(mov);
    return 0;

  } else {
    cout << "Invalid input. Media type not found." << endl;
    cout << " " << endl;
  }
  return 0;
}

//Search through database for media
int search(vector<media*> &x) {

  //Check if user wants to search using title or year
  char in[30];
  cout << "Would you like to search using the title or the year: ";
  cin.get(in, 30);
  cin.get();
  bool valid = false;

  //Search using title
  if(strcmp(in, "title") == 0) {
    char t[40];
    cout << "Enter a title: ";
    cin.get(t, 40);
    cin.get();

    for(int i = 0; i < x.size(); i++) {
      if(strcmp(t, x.at(i)->getTitle()) == 0) {
	cout << x.at(i)->getTitle() << ", " << x.at(i)->getYear() << endl;
	valid = true;
      }
    }

    if(!valid) {
      cout << "No entries in the database match that search." << endl;
      cout << " " << endl;
      return 0;
    }

    cout << " " << endl;

  //Search using year
  } else if(strcmp(in, "year") == 0) {
    int y;
    cout << "Enter a year: ";
    cin >> y;
    cin.get();
    int num = 0;

    for(int i = 0; i < x.size(); i++) {
      if(y == x.at(i)->getYear()) {
	cout << x.at(i)->getTitle() << ", " << x.at(i)->getYear() << endl;
	valid = true;
      }
    }

    if(!valid) {
      cout << "No entries in the database match that search." << endl;
      cout << " " << endl;
    }

    cout << " " << endl;
    
  } else {
    cout << "Invalid input. Can't search using that property." << endl;
    cout << " " << endl;
  }
  return 0;
}

//Delete media from the database
int del(vector<media*> &x) {

  //Check is user wants to delete using title or year
  char in[30];
  cout << "Would you like to delete using a title or a year: ";
  cin.get(in, 30);
  cin.get();
  bool valid = false;

  //Delete using title
  if(strcmp(in, "title") == 0) {
    char t[40];
    cout << "Enter a title to delete: ";
    cin.get(t, 40);
    cin.get();

    for(vector<media*>::iterator it = x.begin() ; it != x.end(); ++it)
      if(strcmp(t, (*it)->title) == 0) {
	cout << (*it)->title << ", " << (*it)->year << endl;
	valid = true;
      }
    
    if(!valid) {
      cout << "No entries in the database match that search." << endl;
      cout << " " << endl;
    } else {
      char confirmation;
      cout << "Are you sure that you want to delete these items (y/n): ";
      cin >> confirmation;
      cin.get();
    
      if(valid && confirmation == 'y') {
	for(vector<media*>::iterator it = x.begin() ; it != x.end(); )
	  if(strcmp(t, (*it)->title) == 0) {
	    x.erase(it);
	  }
	cout << "Your items were deleted." << endl;
	cout << " " << endl;
      } else if(valid && confirmation == 'n') {
	cout << "Your items were not deleted." << endl;
	cout << " " << endl;
      }
    }

  //Delete using year
  } else if(strcmp(in, "year") == 0) {
    int y;
    cout << "Enter a year to delete: ";
    cin >> y;
    cin.get();
    
    for(vector<media*>::iterator it = x.begin() ; it != x.end(); ++it)
      if(y == (*it)->year) {
	cout << (*it)->title << ", " << (*it)->year << endl;
	valid = true;
      }
    
    if(!valid) {
      cout << "No entries in the database match that search." << endl;
      cout << " " << endl;
    } else {
      char confirmation;
      cout << "Are you sure that you want to delete these items (y/n): ";
      cin >> confirmation;
      cin.get();
    
      if(valid && confirmation == 'y') {
	for(vector<media*>::iterator it = x.begin() ; it != x.end(); )
	  if(y == (*it)->year) {
	    x.erase(it);
	  }
	cout << "Your items were deleted." << endl;
	cout << " " << endl;
      } else if(valid && confirmation == 'n') {
	cout << "Your items were not deleted." << endl;
	cout << " " << endl;
      }
    }
    
  } else {
    cout << "Invalid input. Can't search using that property." << endl;
    cout << " " << endl;
  }
  return 0;
}
