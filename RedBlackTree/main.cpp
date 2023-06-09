#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"
#include "redBlackTree.h"

using namespace std;

/*
 * This program allows users to add (manually or from a file), remove, search, and print numbers in a red-black tree
 * Author: Aashvi Busa
 * Date: 06/03/23
 */

//Initialize function prototypes
bool search(int v, RedBlackTree* r);
void print(int space, Node* r);

int main() {
  
  //Initialize variables
  RedBlackTree* rbt = new RedBlackTree();
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    char in[30];
    cout << "Enter a command (add, read, delete, search, print, or quit): ";
    cin.get(in, 30);
    cin.get();

    //Format input
    for(int i = 0; i < strlen(in); i++) in[i] = tolower(in[i]);

    //Execute function according to corresponding input
    if(strcmp(in, "add") == 0) {

      //Get user input for number to add
      int in2;
      cout << "Enter a number to add to the tree: ";
      cin >> in2;
      cin.get();

      //Add number to tree
      rbt->add(in2);

      cout << in2 << " has been added to the tree." << endl;
      cout << " " << endl;
      
    } else if(strcmp(in, "read") == 0) {

      //Read in file
      ifstream numbers("numbers.txt");

      int arrSize = 0;
      int* arr = new int[100];

      //Loop through numbers and add to array
      while(arrSize < 100 && numbers >> arr[arrSize]) ++arrSize;

      //Add numbers to tree
      for(int i = 0; i < arrSize; i++) {
	rbt->add(arr[i]);
      }

      cout << "File numbers have been added." << endl;
      cout << " " << endl;
      
    } else if(strcmp(in, "delete") == 0) {

      //Get user input for number to delete
      int in3;
      cout << "Enter a number to delete: ";
      cin >> in3;
      cin.get();

      //Delete number from tree
      rbt->del(in3);

      cout << in3 << " has been deleted." << endl;
      cout << " " << endl;
      
    } else if(strcmp(in, "print") == 0) {

      //Print out tree
      if(rbt->root == NULL) {
	cout << "Tree is empty. " << endl;
	cout << " " << endl;	
      } else {
	int s = -3;
	print(s, rbt->root);
	cout << " " << endl;
      }
      
    } else if(strcmp(in, "search") == 0) {

      //Get user input for number to search
      int in4;
      cout << "Enter a number to search: ";
      cin >> in4;
      cin.get();

      //Search tree for number
      bool s;
      s = search(in4, rbt);

      if(s == true) {
	cout << in4 << " is in the tree." << endl;
	cout << " " << endl;
      } else {
	cout << in4 << " is not in the tree." << endl;
	cout << " " << endl;
      }
      
    } else if(strcmp(in, "quit") == 0) {

      //End while loop if user quits
      cont = false;
      
    } else {

      //Check for invalid input
      cout << "Invalid input. Try again." << endl;
      cout << " " << endl;
    }
  }
  return 0;
}

//Searches number in tree
bool search(int v, RedBlackTree* r) {

  //Base case
  if(r->root == NULL) {
    cout << "No nodes in tree." << endl;
    return false;
  }

  Node* n = r->root;
  int there = 0;

  //Loops until value is found or not found
  while(n != NULL && there == 0) {
    
    if(n->value == v) {
      there = 1;
    }

    if(n->value < v) {
      n = n->right;
    } else {
      n = n->left;
    }
  }

  //Return according to above results
  if(there == 1) {
    return true;
  } else {
    return false;
  }
  return false;
}

//Prints out tree
void print(int space, Node* r) {

  if(r != NULL) {
    space = space + 3;

    //Recursion to display right subtree
    print(space, r->right);
    cout << " " << endl;
    for(int i = 0; i < space; i++) {
      cout << " ";
    }
    
    if(r->value != 0) {
      cout << r->value << "(" << r->color << ")" << endl;
    }

    //Recursion to display left subtree
    print(space, r->left);
  }
}
