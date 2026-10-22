/******************************************************************************
# Author:           Andy Joy
# Assignment:       Midterm
# Date:             10/21/2026
# Description:      This program
#                   
# Input:            
# Output:           
# Sources:          
#******************************************************************************/
#include <iostream>

using namespace std;

//Function prototypes
int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int &val);
void printQueue(int queue[], int size);

//Constants
const int MAX = 3; // maximum size of queue

//Main function
int main() {
  int queue[MAX]; // integer array for queue
  int size = 0;   // contains number of elements in queue
  char option = ' ';
  int tempNum = 0;

  cout << "Welcome to the FIFO Queue Program!" << endl;

  cout << "\nEnter option: ";
  cin >> option;
  option = tolower(option);

  while (option != '+' && option != '-' && option != 'p' && option != 'q') {
    cout << "Invalid option." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\nEnter option: ";
    cin >> option;
    option = tolower(option);
  }
  cin.ignore(10, '\n');

  while (option != 'q') {
    if (option == '+') {
      cout << "Integer: ";
      cin >> tempNum;

      while (!cin || (tempNum < 0)) {
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Integer: ";
        cin >> tempNum;
      }
      cin.ignore(10, '\n');

      if (enqueue(queue, size, tempNum) == 1) {
        cout << "Error: Queue Overflow!" << endl;
      }
      printQueue(queue, size);
    }

    else if (option == '-') {
      cout << "Integer: ";
      cin >> tempNum;

      while (!cin || (tempNum < 0)) {
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Integer: ";
        cin >> tempNum;
      }
      cin.ignore(10, '\n');

      if (dequeue(queue, size, tempNum) == 1) {
        cout << "Queue Empty." << endl;
      }
      printQueue(queue, size);
    }

    else if (option == 'p') {
      printQueue(queue, size);
    }
    cout << "\nEnter option: ";
    cin >> option;
    option = tolower(option);

    while (option != '+' && option != '-' && option != 'p' && option != 'q') {
      cout << "Invalid option." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << "\nEnter option: ";
      cin >> option;
      option = tolower(option);
    }
    cin.ignore(10, '\n');
  } 
  cout << "\nGoodbye!" << endl;
  return 0;
}

//Enqueue function
int enqueue(int queue[], int &size, int val){
  int overFlow = 0;

  if (size < MAX) {
    queue[size] = val;
    size++;
  }
  else {
    overFlow = 1;
  }
  return overFlow;
}

//Dequeue function
int dequeue(int queue[], int &size, int &val){
  int underFlow = 0;
  int dequeueIndex = -1;
  int searchCount = 0;

  if (size > 0) {
    while (dequeueIndex == -1) { //loop to find first index of val
      if (queue[searchCount] == val) {
        dequeueIndex = searchCount + 1;
      }
      searchCount++;
    }
    for (int i = dequeueIndex; i > 0; i--) { //loop removes one val by shifting all elemtents left, loops based on dequeueIndex
      for (int j = 0; j < size - 1; j++){
        queue[j] = queue[j+1];
      }
      size--;
      queue[size] = 0;
    }
  }
  else {
    underFlow = 1;
  }
  return underFlow;
}

//Print queue function
void printQueue(int queue[], int size){
  cout << "[";
  for (int i = 0; i < size; i++){
    cout << queue[i];
      
    if (i != size - 1)
      cout << ", " ;
  }
  cout << "]" << endl;
}