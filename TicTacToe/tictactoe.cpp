#include <iostream>
#include <cstring>

using namespace std;

/*
 * This program allows two users to play Tic-Tac-Toe
 * Referenced java Tic-Tac-Toe project
 * Author: Aashvi Busa
 * Date: 10/10/22
 */

void printBoard(char varBoard[][3]);
void clearBoard(char (&varBoard)[3][3]);
bool checkWin(char varBoard[][3], char player);
bool checkTie(char varBoard[][3]);

int main() {

  //Initialize board and other variables
  char board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
  int x_wins = 0;
  int o_wins = 0;
  int ties = 0;
  char x_move = 'X';
  char o_move = 'O';
  bool x_turn = false;
  bool stillPlaying = true;
  bool gameEnd = false;
  
  //Runs while user is still playing
  while(stillPlaying) {
    cout << "Welcome to TicTacToe!" << endl;
    x_turn = true;

    //Runs until someone wins or there is a tie
    while(!checkWin(board, x_move) && !checkWin(board, o_move) && !checkTie(board)) {
      printBoard(board);
      char coordinate[80];
      cout << " " << endl;

      //Gets user input for the coordinate
      if(x_turn) {
	cout << "It's X's turn! Enter a coordinate: ";
	cin.get(coordinate, 80);
	cin.get();
      } else {
	cout << "It's O's turn! Enter a coordinate: ";
	cin.get(coordinate, 80);
	cin.get();
      }

      //Checks user input and updates board
      if(strlen(coordinate) != 2) {
	cout << "Invalid input. Enter a letter followed by a number." << endl;
	cout << " " << endl;
      } else if(coordinate[0] != 'a' && coordinate[0] != 'b' && coordinate[0] != 'c') {
	cout << "Invalid input. Row must be an a, b, or c." << endl;
	cout << " " << endl;
      } else if(coordinate[1] != '1' && coordinate[1] != '2' && coordinate[1] != '3') {
	cout << "Invalid input. Column must be a 1, 2, or 3" << endl;
	cout << " " << endl;
      } else {
	int row = coordinate[0] - 'a';
	int x = coordinate[1];
	int column = x - 49;
	if (board[row][column] == 0) {
	  if (x_turn) {
	    board[row][column] = x_move;
	    x_turn = false;
	  } else {
	    board[row][column] = o_move;
	    x_turn = true;
	  }
	} else {
	  cout << "There is a piece there!" << endl;
	  cout << " " << endl;
	}
      }
    }

    //Checks if someone won or if there is a tie and updates win counts
    if(checkWin(board, x_move)) {
      cout << "X wins!" << endl;
      x_wins += 1;
      printBoard(board);
      cout << " " << endl;
      clearBoard(board);
      gameEnd = true;
    } else if(checkWin(board, o_move)) {
      cout << "O wins!" << endl;
      o_wins += 1;
      printBoard(board);
      cout << " " << endl;
      clearBoard(board);
      gameEnd = true;
    } else if(checkTie(board)) {
      cout << "It's a tie!" << endl;
      ties += 1;
      printBoard(board);
      cout << " " << endl;
      clearBoard(board);
      gameEnd = true;
    } else {
      gameEnd = false;
    }

    //Checks if user would like to continue playing
    if(gameEnd) {
      cout << "X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << endl;
      bool validInput = false;
      char in = ' ';
      while (!validInput) {
	cout << "Would you like to continue playing (Y or N): ";
	cin.get(in);
	cin.get();
	if (in == 'Y' || in == 'y') {
	  cout << " " << endl;
	  validInput = true;
	} else if (in == 'N' || in == 'n') {
	  cout << "Thanks for playing!" << endl;
	  stillPlaying = false;
	  validInput = true;
	} else {
	  cout << "Invalid input. Try entering Y or N." << endl;
	  validInput = false;
	}
      }
    }
  }
}

//Prints the board for the user
void printBoard(char varBoard[][3]) {
  char label = 96;
  cout << "  1 2 3"; 
  for(int i = 0; i < 3; i++) {
    label += 1;
    cout << "\n" << label;
    for(int j = 0; j < 3; j++) {
      if(varBoard[i][j] == 0) {
	cout << "  ";
      } else if (varBoard[i][j] == 'X') {
	cout << " X";
      } else if (varBoard[i][j] == 'O') {
	cout << " O";
      }
    }  
  }
  cout << "\n";
}

//Resets the board
void clearBoard(char (&varBoard)[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      varBoard[i][j] = 0;
    }
  }
  
}

//Checks if any win conditions have been met
bool checkWin(char varBoard[][3], char player) {
  if(varBoard[0][0] == player && varBoard[0][1] == player && varBoard[0][2] == player) {
    return true;
  } else if(varBoard[1][0] == player && varBoard[1][1] == player && varBoard[1][2] == player) {
    return true;
  } else if(varBoard[2][0] == player && varBoard[2][1] == player && varBoard[2][2] == player) {
    return true;
  } else if(varBoard[0][0] == player && varBoard[1][0] == player && varBoard[2][0] == player) {
    return true;
  } else if(varBoard[0][1] == player && varBoard[1][1] == player && varBoard[2][1] == player) {
    return true;
  } else if(varBoard[0][2] == player && varBoard[1][2] == player && varBoard[2][2] == player) {
    return true;
  } else if(varBoard[0][0] == player && varBoard[1][1] == player && varBoard[2][2] == player) {
    return true;
  } else if(varBoard[0][2] == player && varBoard[1][1] == player && varBoard[2][0] == player) {
    return true;
  } else {
    return false;
  }
}

//Checks if the game is tied
bool checkTie(char varBoard[][3]) {
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      if(varBoard[row][column] == 0) {
	return false;
      }
    }
  }
  return true;
}
