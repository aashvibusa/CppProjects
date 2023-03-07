#include <iostream>
#include <cstring>

using namespace std;

void heap(int *x, int n, int i);
void sort(int *x, int n);
void add(int *x, int &n, int val);
int remove(int *x, int &n);
void removeAll(int *x, int n);
void print(int *x, int space, int root);

int main() {

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

      int value = 0;
      cout << "Enter a number: ";
      cin >> value;
      cin.get();
      
      add(arr, arrSize, value);
      cout << " " << endl;

    } else if(strcmp(command, "print") == 0) {

      sort(arr, arrSize);
      print(arr, 0, 0);
      cout << " " << endl;

    } else if(strcmp(command, "quit") == 0) {

      cont = false;

    } else if(strcmp(command, "remove") == 0) {

      cout << remove(arr, arrSize) << " was removed" << endl;
      cout << " " << endl;

    } else if(strcmp(command, "removeAll") == 0) {

      removeAll(arr, arrSize);
      cout << " " << endl;

    } else if(strcmp(command, "file") == 0) {

      ifstream numbers("numbers.txt");
      while(

    } else {
      cout << "Invalid command" << endl;
      cout << " " << endl;
    }
  }
  
  return 0;
}

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

void sort(int *x, int n) {

  for(int i = (n / 2) - 1; i >= 0; i--) {
    heap(x, n, i);
  }
}

void add(int *x, int &n, int val) {

  x[n] = val;
  n++;

  cout << val << " was added";
  cout << " " << endl;
}

int remove(int *x, int &n) {

  int last = x[n - 1];
  int root = x[0];

  x[0] = last;
  x[n - 1] = -1;
  n = n - 1;

  heap(x, n, 0);

  return root;
}

void removeAll(int *x, int n) {

  int length = n;

  cout << "Removed: ";
  for(int i = 0; i < length; i++) {
    cout << remove(x, n) << " ";
  }

  cout << " " << endl;
}

void print(int *x, int space, int root) {

  if(x[root] < 1 || x[root] > 1000) {
    return;
  }
  
  space += 3;
  print(x, space, 2 * root + 2);

  for(int i = 3; i < space; i++) {
    cout << " ";
  }

  cout << x[root] << endl;
  print(x, space, 2 * root + 1);
  
}
