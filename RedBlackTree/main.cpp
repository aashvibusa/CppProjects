#include <iostream>
#include <cstring>
#include "node.h"
#include "redBlackTree.h"

using namespace std;

void rotateRight(Node* x, RedBlackTree* r);
void rotateLeft(Node* x, RedBlackTree* r);
void add(int v, RedBlackTree* r);
void transplant(Node* x, Node* y, RedBlackTree* r);
void del(int v, RedBlackTree* r);
void print(int space, Node* r);

int main() {
  RedBlackTree* rbt = new RedBlackTree();
  //add(3, rbt);
  //add(21, rbt);
  //add(32, rbt);
  //add(15, rbt);
  add(1, rbt);
  add(4, rbt);
  add(6, rbt);
  add(3, rbt);
  add(5, rbt);
  add(7, rbt);
  add(8, rbt);
  add(2, rbt);
  add(9, rbt);
  int s = -3;
  print(s, rbt->root);
  cout << "- - - - - - " << endl;
  del(4, rbt);
  del(2, rbt);
  print(s, rbt->root);
  return 0;
}

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

  if(x != NULL && x->parent == NULL) {
    r->root = y;
  } else if(x != NULL && x == x->parent->right) {
    x->parent->right = y;
  } else if(x != NULL) {
    x->parent->left = y;
  }

  if(x != NULL && y != NULL) {
    y->right = x;
    x->parent = y;
  }
}

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

  if(x != NULL && x->parent == NULL) {
    r->root = y;
  } else if(x != NULL && x == x->parent->left) {
    x->parent->left = y;
  } else if(x != NULL) {
    x->parent->right = y;
  }

  if(x != NULL && y != NULL) {
    y->left = x;
    x->parent = y;
  }
}

void add(int v, RedBlackTree* r) {

  Node* n = new Node(v);
  n->color = 'R';
  Node* y = NULL;
  Node* x = r->root;

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

    if(n != NULL && n->parent != NULL && n->parent->parent != NULL && n->parent == n->parent->parent->right) {
      z = n->parent->parent->left;

      if(z != NULL && z->color == 'R') {
	z->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else {
	if(n == n->parent->left) {
	  n = n->parent;
	  rotateRight(n, r);
	}
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	rotateLeft(n->parent->parent, r);
      }
    } else {

      if(n != NULL && n->parent != NULL && n->parent->parent != NULL) {
	z = n->parent->parent->right;
      }

      if(z != NULL && z->color == 'R') {
	z->color = 'B';
	n->parent->color = 'B';
	n->parent->parent->color = 'R';
	n = n->parent->parent;
	
      } else {
	if(n == n->parent->right) {
	  n = n->parent;
	  rotateLeft(n, r);
	}
	n->parent->color = 'B';

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

void transplant(Node* x, Node* y, RedBlackTree* r) {

  if(x != NULL && x->parent == NULL) {
    r->root = y;
  } else if(x != NULL && x->parent != NULL && x == x->parent->left) {
    x->parent->left = y;
  } else if(x != NULL && x->parent != NULL) {
    x->parent->right = y;
  }

  if(y != NULL && x != NULL) {
    y->parent = x->parent;
  }
}

void del(int v, RedBlackTree* r) {

  Node* z = NULL;
  Node* x;
  Node* y;
  Node* b = r->root;

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

  if(z == NULL) {
    cout << "Value is not in tree." << endl;
    return;
  }

  y = z;
  char origColor = y->color;

  if(z->left == NULL) {
    x = z->right;
    transplant(z, z->right, r);
    
  } else if(z->right == NULL) {
    x = z->left;
    transplant(z, z->left, r);
    
  } else {

    Node* c = z->right;
    while(c->left != NULL) {
      c = c->left;
    }
    y = c;
    origColor = y->color;
    x = y->right;
    
    if(y != NULL && x != NULL && y->parent == z) {
      x->parent = y;
      
    } else if(y != NULL) {
      transplant(y, y->right, r);
      y->right = z->right;

      if(y->right != NULL) {
	y->right->parent = y;
      }
    } 

    transplant(z, y, r);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  
  delete z;
  
  if(origColor == 'B') {
    Node* a;

    while(x != NULL && x != r->root && x->color == 'B') {

      if(x == x->parent->left) {
	a = x->parent->right;

	if(a->color == 'R') {
	  a->color = 'B';
	  x->parent->color = 'R';
	  rotateLeft(x->parent, r);
	  a = x->parent->right;
	}

	if(a->left->color == 'B' && a->right->color == 'B') {
	  a->color = 'R';
	  x = x->parent;
	  
	} else {
	  if(a->right->color == 'B') {
	    a->left->color = 'B';
	    a->color = 'R';
	    rotateRight(a, r);
	    a = x->parent->right;
	  }

	  a->color = x->parent->color;
	  x->parent->color = 'B';
	  a->right->color = 'B';
	  rotateLeft(x->parent, r);
	  x = r->root;
	}
      } else {
	a = x->parent->left;
	
	if(a->color == 'R') {
	  a->color = 'B';
	  x->parent->color = 'R';
	  rotateRight(x->parent, r);
	  a = x->parent->left;
	}

	if(a->left->color == 'B' && a->right->color == 'B') {
	  a->color = 'R';
	  x = x->parent;
	  
	} else {
	  if(a->left->color == 'B') {
	    a->right->color = 'B';
	    a->color = 'R';
	    rotateLeft(a, r);
	    a = x->parent->left;
	  }

	  a->color = x->parent->color;
	  x->parent->color = 'B';
	  a->left->color = 'B';
	  rotateRight(x->parent, r);
	  x = r->root;
	}
      }
    }
    if(x != NULL) {
      x->color = 'B';
    }
  }
}

void print(int space, Node* r) {

  if(r != NULL) {
    space = space + 3;
    print(space, r->right);
    cout << " " << endl;
    for(int i = 0; i < space; i++) {
      cout << " ";
    }
    cout << r->value << "(" << r->color << ")" << endl;
    print(space, r->left);
  }
}


