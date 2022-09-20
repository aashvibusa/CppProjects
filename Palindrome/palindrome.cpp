#include <iostream>
#include <cstring>

using namespace std;

/*
 * This program checks whether an inputted word or phrase is a palindrome
 * Created by: Aashvi Busa
 * Date: 9/17/22
 */

int main() {

  //Get user input
  char input[80];
  cout << "Enter a word or phrase: ";
  cin.get(input, 80);
  cin.get();

  //Check input
  int checkPalindrome(char a[]);
  checkPalindrome(input);
  return 0;
}

//Function to check if input is a palindrome
int checkPalindrome(char a[]) {

  //Initialize modified array and count variable
  char modified[80];
  int count = 0;

  //Make lowercase and remove spaces, numbers, and other punctuation
  for(int i = 0; i < strlen(a); i++) {
    if(a[i] != '\0') {
      a[i] = tolower(a[i]);
      if((a[i] >= 'a' && a[i] <= 'z') || isdigit(a[i])) {
	modified[count] = a[i];
	count++;
      }
    }  
  }

  //Initialize backwards array
  char backwards[count];

  //Place characters in backwards array
  for(int i = 0; i < count; i++) {
    backwards[i] = modified[count - 1 - i];
  }
  
  //Compare modified and backwards arrays
  for(int i = 0; i < count; i++) {
    if(modified[i] != backwards[i]) {
      cout << "Not a palindrome." << endl;
      return 0;
    }  
  }
  cout << "Palindrome." << endl;
  return 0;
}  
