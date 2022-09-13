#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * This is an implementation of guessing game
 * Created by: Aashvi Busa
 * Date: 9/12/22
 * 
 * The three rules for c++ are no global variables, no strings, and include <iostream> (not stdio)
 */

int main() {

  //Initialize variables
  int randomNum;
  int guesses;
  bool newNum;
  newNum = true;

  //Loop while user is still playing
  bool playing;
  playing = true;
  while(playing) {

    //Create random number and set number of guesses
    if(newNum) {  
      srand (time(NULL));
      randomNum = rand() % 101;
      guesses = 0;
      newNum = false;
    }  

    //Get user input
    int a;
    cout << "Enter a number: ";
    cin >> a;

    char playAgain;

    //Check input
    if(a < randomNum) {
      guesses++;
      cout << "too low!" << endl;
    } else if(a > randomNum) {
      guesses++;
      cout << "too high!" << endl;
    } else {
      guesses++;
      cout << "you took: " << guesses << " guesses" << endl;
      cout << "you win! do you want to play again? (y/n)" << endl;
      cin >> playAgain;
      if(playAgain == 'y') {
	newNum = true;
      } else {
	playing = false;
      }
    }
  }
  cout << "thanks for playing guessing game!" << endl;
  return 0;
}  
