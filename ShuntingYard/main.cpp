#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

/*
 * This program allows a user to input an infix expression and output the expression in prefix, infix, or postfix form from an expresison tree
 * Author: Aashvi Busa
 * Date: 3/19/23
 */

//Function prototypes
int precedence(char op);
char* shuntingYard(char* infix, Stack s, Queue q);
void push(Node** &tree, Node* t, int &top);
Node* pop(Node** &tree, int &top);
void buildTree(Node** &tree, int &top, char* postfix);
void pre(Node* t);
void in(Node* t);
void post(Node* t);

int main() {

  //Initializing stack and queue
  Stack stack;
  Queue queue;

  //Get user input for infix
  char* input = new char[40];
  cout << "Enter an infix expression: ";
  cin.get(input, 40);
  cin.get();

  //Output postfix
  char* postfix = shuntingYard(input, stack, queue);
  cout << "Postfix expression: " << postfix << endl;
  cout << " " << endl;

  //Build expression tree
  int len = strlen(postfix);
  Node** tree = new Node*[len];
  int top = -1;
  buildTree(tree, top, postfix);

  //Continue until user quits
  bool cont = true;
  while(cont) {

    //Get user input for expression
    char* input2 = new char[40];
    cout << "Would you like to output the prefix, infix, or postfix expression (may also choose quit): ";
    cin.get(input2, 40);
    cin.get();

    //Execute function according to input
    if(strcmp(input2, "prefix") == 0) {
      pre(tree[0]);
      cout << " " << endl;
      cout << " " << endl;
    } else if(strcmp(input2, "infix") == 0) {
      in(tree[0]);
      cout << " " << endl;
      cout << " " << endl;
    } else if(strcmp(input2, "postfix") == 0) {
      post(tree[0]);
      cout << " " << endl;
      cout << " " << endl;
    } else if(strcmp(input2, "quit") == 0) {
      cont = false;
    } else {
      cout << "Invalid input." << endl;
      cout << " " << endl;
    }
  }
  return 0;
}

//Get precedence of operators
int precedence(char op) {
  if(op == '^') {
    return 3;
  } else if(op == '*'|| op == '/') {
    return 2;
  } else if(op == '+'|| op == '-') {
    return 1;
  } else if(op == '(' || op == ')') {
    return -1;
  } else if(op == ' ') {
    return -2;
  } else {
    return 0;
  }
  return 0;
}

//Shunting Yard algorithm for infix to postfix conversion
char* shuntingYard(char* infix, Stack s, Queue q) {

  int len = strlen(infix);
  int count = 0;

  while(count < len) { //Continue until there are no more characters
    
    if(precedence(infix[count]) == 0) { //Enqueue if number
      q.enqueue(infix[count]);
      count++;
	
    } else {

      if(infix[count] == '(') { //Push if left brack
	s.push(infix[count]);
	count++;
	  
      } else if(infix[count] == ')') { //Enqueue and pop from stack until left bracket, then remove left bracket
	while(s.peek() != '(') {
	  q.enqueue(s.peek());
	  s.pop();
	}
	s.pop();
	count++;
	  
      } else if(precedence(infix[count]) == 1 || precedence(infix[count]) == 2 || precedence(infix[count]) == 3) { //Enqueue operators while precedence is higher
	while(precedence(infix[count]) <= precedence(s.peek())) { 
	  q.enqueue(s.peek());
	  s.pop();
	}
	s.push(infix[count]);
	count++;
	
      } else { //if space
	count++;
      }
    }
  }

  //Enqueue remaining operators from stack
  while(s.peek() != 'x') { 
    q.enqueue(s.peek());
    s.pop();
  }

  return(q.display());
}

//Push to tree
void push(Node** &tree, Node* t, int &top) {
  top++;
  tree[top] = t;
}

//Pop from tree
Node* pop(Node** &tree, int &top) {
  top--;
  return(tree[top + 1]);
}

//Build expression tree
void buildTree(Node** &tree, int &top, char* postfix) {

  Node* n;
  Node* p1;
  Node* p2;
  int len = strlen(postfix);
  int x;

  //Loop until there are no more characters
  for(int i = 0; i < len; i++) {
    x = precedence(postfix[i]);
    
    if(x > 3 || x < 1) { //If number set left & right to NULL and push to tree
      n = new Node(postfix[i]);
      n->setLeft(NULL);
      n->setRight(NULL);
      push(tree, n, top);
      
    } else { //If operator set left & right to top 2 tree elements and push to tree
      p1 = pop(tree, top);
      p2 = pop(tree, top);
      n = new Node(postfix[i]);
      n->setLeft(p2);
      n->setRight(p1);
      push(tree, n, top);
    }
  }
}

//Output prefix expression
void pre(Node* t) {
  if(t != NULL) {
    cout << t->getValue();
    pre(t->getLeft());
    pre(t->getRight());
  }
}

//Output infix expression
void in(Node* t) {
  if(t != NULL) {
    in(t->left);
    cout << t->value;
    in(t->right);
  }
}

//Output postfix expression
void post(Node* t) {
  if(t != NULL) {
    post(t->left);
    post(t->right);
    cout << t->value;
  }
}
