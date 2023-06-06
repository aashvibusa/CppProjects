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
void rotateRight(Node* x, RedBlackTree* r);
void rotateLeft(Node* x, RedBlackTree* r);
void add(int v, RedBlackTree* r);
void transplant(Node* x, Node* y, RedBlackTree* r);
void del(int v, RedBlackTree* r);
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
      add(in2, rbt);

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
	add(arr[i], rbt);
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
      del(in3, rbt);

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

//Performs right rotation
void rotateRight(Node* x, RedBlackTree* r) {
  
  Node* y;
  if(x != NULL) {
    y = x->left;
  }
  
  if(x != NULL && y != NULL) {
    x->left = y->right;
    if(y->right != NULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
  }

  if(x != NULL && x->parent == NULL) { //If x is the root
    r->root = y;
  } else if(x != NULL && x == x->parent->right) { //If x is the right child
    x->parent->right = y;
  } else if(x != NULL) { //If x is the left child
    x->parent->left = y;
  }

  if(x != NULL && y != NULL) {
    y->right = x;
    x->parent = y;
  }
}

//Performs left rotation
void rotateLeft(Node* x, RedBlackTree* r) {

  Node* y;
  if(x != NULL) {
    y = x->right;
  }
  
  if(x != NULL && y != NULL) {
    x->right = y->left;
    if(y->left != NULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
  }

  if(x != NULL && x->parent == NULL) { //If x is the root
    r->root = y;
  } else if(x != NULL && x == x->parent->left) { //If x is the left child
    x->parent->left = y;
  } else if(x != NULL) { //If x is the right child
    x->parent->right = y;
  }

  if(x != NULL && y != NULL) {
    y->left = x;
    x->parent = y;
  }
}

//Adds number to tree
void add(int v, RedBlackTree* r) {

  //Define new node to be added
  Node* n = new Node(v);
  n->color = 'R';
  Node* y = NULL;
  Node* x = r->root;

  //Find location to insert
  while(x != NULL) {
    y = x;
    if(n->value < x->value) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  n->parent = y;
  if(y == NULL) {
    r->root = n;
  } else if(n->value < y->value) {
    y->left = n;
  } else {
    y->right = n;
  }

  if(n->parent == NULL) {
    n->color = 'B';
    return;
  }

  if(n->parent->parent == NULL) {
    return;
  }

  if(n != NULL) {
    n->left = NULL;
    n->right = NULL;
    n->color = 'R';
  }

  //Balancing tree
  Node* z;
  while(n != NULL && n->parent != NULL && n->parent->color == 'R') {

    //If n->parent is the left child
    if(n != NULL && n->parent != NULL && n->parent->parent != NULL && n->parent == n->parent->parent->right) {
      z = n->parent->parent->left;

      if(z != NULL && z->color == 'R') { //Uncle and new node are red
	z->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else {
	if(n == n->parent->left) { //Uncle is black and new node is left child
	  n = n->parent;
	  rotateRight(n, r);
	}

	//Uncle is black and new node is right child
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	rotateLeft(n->parent->parent, r);
      }
    } else { //If n->parent is the left child

      if(n != NULL && n->parent != NULL && n->parent->parent != NULL) {
	z = n->parent->parent->right;
      }

      if(z != NULL && z->color == 'R') { //Uncle and new node are red
	z->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else { //Uncle is black and new node is right child
	if(n == n->parent->right) {
	  n = n->parent;
	  rotateLeft(n, r);
	}
	n->parent->color = 'B';

	//Uncle is black and new node is left child
	if(n->parent->parent != NULL) {
	  n->parent->parent->color = 'R';
	}
	rotateRight(n->parent->parent, r);
      }
    }
    
    if(n == r->root) {
      break;
    }
  }
  r->root->color = 'B';
}

//Transplants subtree in place of another subtree
void transplant(Node* x, Node* y, RedBlackTree* r) {

  if(x != NULL && x->parent == NULL) { //x is the root
    r->root = y;
  } else if(x != NULL && x->parent != NULL && x == x->parent->left) { //x is the left child
    x->parent->left = y;
  } else if(x != NULL && x->parent != NULL) { //x is the right child
    x->parent->right = y;
  }

  if(y != NULL && x != NULL) {
    y->parent = x->parent;
  }
}

//Deletes number from tree
void del(int v, RedBlackTree* r) {

  Node* z = NULL;
  Node* p;
  Node* q;
  Node* b = r->root;

  //Find location to delete
  while(b != NULL) {
    if(b->value == v) {
      z = b;
    }

    if(b->value <= v) {
      b = b->right;
    } else {
      b = b->left;
    }
  }

  //Return if value is not in tree
  if(z == NULL) {
    cout << "Value is not in tree." << endl;
    return;
  }

  q = z;
  char origColor = q->color;

  if(z->left == NULL) { //No children or only right children are present
    p = z->right;
    transplant(z, z->right, r);
    
  } else if(z->right == NULL) { //Only left children are present
    p = z->left;
    transplant(z, z->left, r);
    
  } else { //Both children are present

    Node* c = z->right;
    while(c->left != NULL) {
      c = c->left;
    }
    q = c;
    origColor = q->color;
    p = q->right;
    
    if(q != NULL && p != NULL && q->parent == z) { //q is a child of z
      p->parent = q;
      
    } else if(q != NULL) {
      transplant(q, q->right, r);
      q->right = z->right;

      if(q->right != NULL) {
	q->right->parent = q;
      }
    } 

    transplant(z, q, r);
    q->left = z->left;
    q->left->parent = q;
    q->color = z->color;
  }
  
  delete z;
  
  if(origColor == 'B') {
    Node* a;

    while(p != NULL && p != r->root && p->color == 'B') {

      if(p == p->parent->left) {
	a = p->parent->right;

	//If a is red
	if(a->color == 'R') {
	  a->color = 'B';
	  p->parent->color = 'R';
	  rotateLeft(p->parent, r);
	  a = p->parent->right;
	}

	//If right and left child are black
	if(a->left->color == 'B' && a->right->color == 'B') { 
	  a->color = 'R';
	  p = p->parent;
	  
	} else {
	  if(a->right->color == 'B') { //Right child is black
	    a->left->color = 'B';
	    a->color = 'R';
	    rotateRight(a, r);
	    a = p->parent->right;
	  }

	  //Last case
	  a->color = p->parent->color;
	  p->parent->color = 'B';
	  a->right->color = 'B';
	  rotateLeft(p->parent, r);
	  p = r->root;
	}
      } else {
	a = p->parent->left;

	//If a is red
	if(a->color == 'R') {
	  a->color = 'B';
	  p->parent->color = 'R';
	  rotateRight(p->parent, r);
	  a = p->parent->left;
	}

	//If right and left child are black
	if(a->left->color == 'B' && a->right->color == 'B') {
	  a->color = 'R';
	  p = p->parent;
	  
	} else {
	  if(a->left->color == 'B') { //Left child is black
	    a->right->color = 'B';
	    a->color = 'R';
	    rotateLeft(a, r);
	    a = p->parent->left;
	  }

	  //Last case
	  a->color = p->parent->color;
	  p->parent->color = 'B';
	  a->left->color = 'B';
	  rotateRight(p->parent, r);
	  p = r->root;
	}
      }
    }
    if(p != NULL) {
      p->color = 'B';
    }
  }
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

  //Loops till value is found or not found
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
    cout << r->value << "(" << r->color << ")" << endl;

    //Recursion to display left subtree
    print(space, r->left);
  }
}


