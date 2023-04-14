#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

/*
 * This program allows users to add (manually or from a file), remove, search, and print numbers in a binary tree
 * Author: Aashvi Busa
 * Date: 4/13/23
 */

//Initialize function prototypes
void add(Node*& r, int v);
Node* del(Node* r, int v);
void search(Node* r, int v);
void print(Node* r, int n);

int main() {

  //Initialize variables
  Node* root = NULL;
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    char in[30];
    cout << "Enter a command (add, file, delete, search, print, or quit): ";
    cin.get(in, 30);
    cin.get();

    //Format input
    for(int i = 0; i < strlen(in); i++) in[i] = tolower(in[i]);

    //Execute function according to corresponding input
    if(strcmp(in, "add") == 0) {

      //Get user input for numbers to add
      char in2[100];
      cout << "Enter a number or a list of numbers to add to the tree: ";
      cin.getline(in2, 100);

      //Add numbers to tree
      char* ptr;
      ptr = strtok(in2, " ");
      while(ptr != NULL) {
	add(root, atoi(ptr));
	ptr = strtok(NULL, " ");
      }
      cout << "The number(s) have been added to the tree." << endl;
      cout << " " << endl;
      
    } else if(strcmp(in, "file") == 0) {

      //Read in file
      ifstream numbers("numbers.txt");

      int arrSize = 0;
      int* arr = new int[100];

      //Loop through numbers and add to array
      while(arrSize < 100 && numbers >> arr[arrSize]) ++arrSize;

      //Add numbers to tree
      for(int i = 0; i < arrSize; i++) {
	add(root, arr[i]);
      }
      
      cout << "File numbers have been added." << endl;
      cout << " " << endl;

    } else if(strcmp(in, "delete") == 0) {

      int in3;
      cout << "Enter a number to delete: ";
      cin >> in3;
      cin.get();
      del(root, in3);
      cout << in3 << " has been deleted." << endl;
      cout << " " << endl;
      
    } else if(strcmp(in, "print") == 0) {
      
      print(root, -1);
      cout << " " << endl;
      
    } else if(strcmp(in, "search") == 0) {

      int in4;
      cout << "Enter a number to search: ";
      cin >> in4;
      cin.get();
      search(root, in4);
      
    } else if(strcmp(in, "quit") == 0) {
      cont = false;
      
    } else {
      cout << "Invalid input. Try again." << endl;
      cout << " " << endl;
    }
  }
  return 0;
}

//Add number to tree
void add(Node*& r, int v) {

  Node* n = new Node(v);
  if(r == NULL) {
    r = n;
    return;
  }

  Node* p = NULL;
  Node* temp = r;

  //Find position for number
  while(temp != NULL) {

    if(temp->value > v) {
      p = temp;
      temp = temp->left;
      
    } else if(temp->value < v) {
      p = temp;
      temp = temp->right;
    }
  }

  //Add number to either left or right side
  if(p->value > v) {
    p->left = n;
    
  } else {
    p->right = n;
  }
}

//Delete number from tree
Node* del(Node* r, int v) {
  
  if(r == NULL) {
    return r;
  }

  //Find position of number
  if(v > r->value) {
    r->right = del(r->right, v);
    
  } else if(v < r->value) {
    r->left = del(r->left, v);
    
  } else { //If number is found
    
    if(r->left == NULL && r->right == NULL) {
      free(r);
      r = NULL;
      
    } else if(r->left == NULL) {
      Node* temp = r;
      r = r->right;
      free(temp);
      
    } else if(r->right == NULL) {
      Node* temp = r;
      r = r->left;
      free(temp);
      
    } else {

      Node* temp = r->right;
      while(temp->left != NULL) {
	temp = temp->left;
      }
      
      r->value = temp->value;
      r->right = del(r->right, temp->value);
    }
  }
  return r;
}

//Search tree for number
void search(Node* r, int v) {

  Node* temp = r;

  //Continue traversing tree until number is found or not found
  while(temp != NULL) {

    if(temp->value == v) {
      cout << temp->value << " is in the tree." << endl;
      cout << " " << endl;
      return;
      
    } else if(temp->value > v) {
      temp = temp->left;
      
    } else {
      temp = temp->right;
    }
  }

  cout << v << " is not in the tree." << endl;
  cout << " " << endl;
}

//Print tree
void print(Node* r, int n) {

  if(r == NULL) {
    return;
  }

  //Add space for each level
  n += 1;
  print(r->right, n);

  //Print according to number of spaces
  for(int i = 0; i < n; i++) {
    cout << "   ";
  }
  cout << r->value << endl;

  print(r->left, n);
}
