#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/*
 * This program allows users to add (manually or from a file), remove, and print numbers in a heap
 * Author: Aashvi Busa
 * 3/5/23
 */

//Initialize function prototypes
void heap(int *x, int n, int i);
void sort(int *x, int n);
void add(int *x, int &n, int val);
int remove(int *x, int &n);
void removeAll(int *x, int &n);
void print(int *x, int space, int root);

int main() {

  //Initialize variables
  int *arr = new int[100];
  int arrSize = 0;
  char *command = new char[15];
  bool cont = true;

  //Continue until user quits
  while(cont) {

    //Get user input for command
    cout << "Enter a command (add, file, remove, removeAll, print, or quit): ";
    cin.get(command, 10);
    cin.get();

    //Execute function according to corresponding input
    if(strcmp(command, "add") == 0) {

      //Get value input
      int value = 0;
      cout << "Enter a number: ";
      cin >> value;
      cin.get();
      
      add(arr, arrSize, value);
      cout << " " << endl;

    } else if(strcmp(command, "print") == 0) {

      //Sort and print heap
      sort(arr, arrSize);
      print(arr, 0, 0);
      cout << " " << endl;

    } else if(strcmp(command, "quit") == 0) {

      cont = false;

    } else if(strcmp(command, "remove") == 0) {

      //Remove root
      cout << remove(arr, arrSize) << " was removed" << endl;
      cout << " " << endl;

    } else if(strcmp(command, "removeAll") == 0) {

      //Remove all values
      removeAll(arr, arrSize);
      cout << " " << endl;

    } else if(strcmp(command, "file") == 0) {

      //Read in file
      ifstream numbers("numbers.txt");

      //Loop through numbers and add to array
      while(arrSize < 100 && numbers >> arr[arrSize]) ++arrSize;

      //Sort and print heap
      sort(arr, arrSize);
      print(arr, 0, 0);
      cout << " " << endl;

    } else {
      cout << "Invalid command" << endl;
      cout << " " << endl;
    }
  }
  return 0;
}

//Build heap
void heap(int *x, int n, int i) {

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if((left < n) && (x[left] > x[largest])) {
    largest = left;
  }

  if((right < n) && (x[right] > x[largest])) {
    largest = right;
  }

  if(largest != i) {
    int temp = x[i];
    x[i] = x[largest];
    x[largest] = temp;

    heap(x, n, largest);
  }
}

//Sort heap to max hierarchy
void sort(int *x, int n) {

  for(int i = (n / 2) - 1; i >= 0; i--) {
    heap(x, n, i);
  }
}

//Add values to heap
void add(int *x, int &n, int val) {

  x[n] = val;
  n++;

  cout << val << " was added";
  cout << " " << endl;
}

//Remove root from heap
int remove(int *x, int &n) {

  int last = x[n - 1];
  int root = x[0];

  x[0] = last;
  x[n - 1] = 0;
  n--;

  heap(x, n, 0);

  return root;
}

//Remove all values in heap
void removeAll(int *x, int &n) {

  int length = n;
  
  cout << "Removed: ";
  for(int i = 0; i < length; i++) {
    cout << remove(x, n) << " ";
  }

  cout << " " << endl;
}

//Print heap
void print(int *x, int space, int root) {

  if(x[root] < 1 || x[root] > 1000) {
    return;
  }
  
  space += 3;
  print(x, space, 2 * root + 2);

  for(int i = 4; i < space; i++) {
    cout << " ";
  }

  cout << x[root] << endl;
  print(x, space, 2 * root + 1);
}
