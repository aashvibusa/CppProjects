#include <iostream>
#include "redBlackTree.h"
#include "node.h"

using namespace std;

//Initialize red-black tree variables
RedBlackTree::RedBlackTree() {

  N = new Node;
  N->color = 'B';
  N->left = NULL;
  N->right = NULL;
  root = N;
}

//Performs right rotation
void RedBlackTree::rotateRight(Node* a) {
  
  Node* b = a->left;
  a->left = b->right;
  
  if(b->right != N) {
    b->right->parent = a;
  }

  b->parent = a->parent;
  if(a->parent == NULL) { //If a is the root
    root = b;
  } else if(a == a->parent->right) { //If a is the right child
    a->parent->right = b;
  } else { //If a is the left child
    a->parent->left = b;
  }

  b->right = a;
  a->parent = b;
}

//Performs left rotation
void RedBlackTree::rotateLeft(Node* a) {

  Node* b = a->right;
  a->right = b->left;

  if(b->left != N) {
    b->left->parent = a;
  }

  b->parent = a->parent;
  if(a->parent == NULL) { //If a is the root
    root = b;
  } else if(a == a->parent->left) { //If a is the left child
    a->parent->left = b;
  } else { //If a is the right child
    a->parent->right = b;
  }

  b->left = a;
  a->parent = b;
}

//Adds number to tree
void RedBlackTree::add(int v) {

  //Define new node to be added
  Node* n = new Node();
  n->parent = NULL;
  n->value = v;
  n->left = N;
  n->right = N;
  n->color = 'R';

  Node* a = root;
  Node* b = NULL;

  //Find location to insert
  while(a != N) {
    b = a;
    if(n->value < a->value) {
      a = a->left;
    } else {
      a = a->right;
    }
  }

  n->parent = b;
  if(b == NULL) {
    root = n;
  } else if(n->value < b->value) {
    b->left = n;
  } else {
    b->right = n;
  }

  if(n->parent == NULL) {
    n->color = 'B';
    return;
  }

  if(n->parent->parent == NULL) {
    return;
  }

  //Balancing tree
  Node* c;
  while(n->parent->color == 'R') {

    //If parent is the right child
    if(n->parent == n->parent->parent->right) {
      c = n->parent->parent->left;

      if(c->color == 'R') { //Uncle and new node are red
	c->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else {

	if(n == n->parent->left) { //Uncle is black and new node is left child
	  n = n->parent;
	  rotateRight(n);
	}

	//Uncle is black and new node is right child
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	rotateLeft(n->parent->parent);
      }
      
    } else { //If parent is the left child

      c = n->parent->parent->right;

      if(c->color == 'R') { //Uncle and new node are red
	c->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else { //Uncle is black and new node is right child

	if(n == n->parent->right) {
	  n = n->parent;
	  rotateLeft(n);
	}

	//Uncle is black and new node is left child
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	rotateRight(n->parent->parent);
      }
    }
    if(n == root) {
      break;
    }
  }
  root->color = 'B';
}

//Transplants subtree in place of another subtree
void RedBlackTree::transplant(Node* a, Node* b) {

  if(a->parent == NULL) { //a is the root
    root = b;
    
  } else if(a == a->parent->left) { //a is the left child
    a->parent->left = b;
    
  } else { //a is the right child
    a->parent->right = b;
  }
  
  b->parent = a->parent;
}

//Deletes number from tree
void RedBlackTree::del(int v) {

  Node* a = root;
  Node* b = N;
  Node* c;
  Node* d;

  //Find location to delete
  while(a != N) {
    
    if(a->value == v) {
      b = a;
    }

    if(a->value <= v) {
      a = a->right;
    } else {
      a = a->left;
    }
  }

  //Return if value is not in tree
  if(b == N) {
    cout << "Value is not in tree." << endl;
    return;
  }

  d = b;
  char origColor = d->color;

  if(b->left == N) { //No children or only right children are present
    c = b->right;
    transplant(b, b->right);
    
  } else if(b->right == N) { //Only left children are present
    c = b->left;
    transplant(b, b->left);
    
  } else { //Both children are present
    Node* e = b->right;
    while(e->left != N) {
      e = e->left;
    }
    
    d = e;
    origColor = d->color;
    c = d->right;

    if(d->parent == b) { //d is a child of b
      c->parent = d;
      
    } else {
      transplant(d, d->right);
      d->right = b->right;
      d->right->parent = d;
    }

    transplant(b, d);
    d->left = b->left;
    d->left->parent = d;
    d->color = b->color;
  }

  delete b;

  if(origColor == 'B') {

    Node* f;
    while(c != root && c->color == 'B') {

      if(c == c->parent->left) {
	f = c->parent->right;

	//If f is red
	if(f->color == 'R') {
	  f->color = 'B';
	  c->parent->color = 'R';
	  rotateLeft(c->parent);
	  f = c->parent->right;
	}

	//If right and left child are black
	if(f->left->color == 'B' && f->right->color == 'B') {
	  f->color = 'R';
	  c = c->parent;
	  
	} else {

	  //Right child is black
	  if(f->right->color == 'B') {
	    f->left->color = 'B';
	    f->color = 'R';
	    rotateRight(f);
	    f = c->parent->right;
	  }

	  //Last case
	  f->color = c->parent->color;
	  c->parent->color = 'B';
	  f->right->color = 'B';
	  rotateLeft(c->parent);
	  c = root;
	}
	
      } else {
	f = c->parent->left;

	//If f is red
	if(f->color == 'R') {
	  f->color = 'B';
	  c->parent->color = 'R';
	  rotateRight(c->parent);
	  f = c->parent->left;
	}

	//If right and left child are black
	if(f->left->color == 'B' && f->right->color == 'B') {
	  f->color = 'R';
	  c = c->parent;
	  
	} else {

	  //If left child is black
	  if(f->left->color == 'B') {
	    f->right->color = 'B';
	    f->color = 'R';
	    rotateLeft(f);
	    f = c->parent->left;
	  }

	  //Last case
	  f->color = c->parent->color;
	  c->parent->color = 'B';
	  f->left->color = 'B';
	  rotateRight(c->parent);
	  c = root;
	}
      }
    }
    c->color = 'B';
  }
}
