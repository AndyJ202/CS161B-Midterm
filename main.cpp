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

int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int &val);
void printQueue(int queue[], int size);

const int MAX = 3; // maximum size of queue

int main() {
  int queue[MAX]; // integer array for queue
  int size = 0;   // contains number of elements in queue
  char option = ' ';

  cout << "Welcome to the FIFO Queue Program!" << endl;
  cin >> option;
  option = tolower(option);

  while (option != 'q') {
    if (option == '+') {
      cout << "Add" << endl;
      printQueue(queue, size);
    }

    else if (option == '-') {
      cout << "Remove" << endl;
      printQueue(queue, size);
    }

    else if (option == 'p') {
      printQueue(queue, size);
    }
  } 
  cout << "\nGoodbye!" << endl;
  return 0;
}

int enqueue(int queue[], int &size, int val){
  
// add your code here
    
}

int dequeue(int queue[], int &size, int &val){

// add your code here
}

// Call this function to print the queue
void printQueue(int queue[], int size){
  cout << "[";
  for (int i = 0; i < size; i++){
    cout << queue[i];
      
    if (i != size - 1)
      cout << ", " ;
  }
  cout << "]" << endl;
}