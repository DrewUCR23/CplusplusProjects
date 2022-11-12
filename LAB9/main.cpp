/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew Gonzales
 * ASSIGNMENT: Lab Exercise 9a
 * DUE DATE:   11/12/2022
 *
 */
/* Place Library References Here */
#include <iostream>
using namespace std;
/*
 * Main Program
 * Description: Calculate the area of a triangle using pointers
 */
int main() {
  int LENGTH; // holds length
  int WIDTH; // holds width
  int AREA; // holds area
  // Fill in the code to declare an integer pointer named lengthPtr
  int *LENGTHPTR;
  // Intialize it to the null pointer.
  // int *NULL = NULL; 
  // Fill in the code to declare an integer pointer named widthPt.
  int *WIDTHPT;
  // Intialize it to the null pointer.
  cout << "Please input the length of the rectangle: ";
  cin >> LENGTH;
  cout << "Please input the width of the rectangle: ";
  cin >> WIDTH;
  // Fill in code to assign the address of variable length to lengthPtr
  LENGTHPTR = &LENGTH;
  // Fill in the ode to assign the address of variable width to widthPtr
  WIDTHPT = &WIDTH;
  // Fill in code to find the area by using only the pointer
  AREA = (*WIDTHPT)*(*LENGTHPTR);  //when writing a pointer variable you need to use a multiplier before it in order to call a dereference from the variable.
  cout << "The area is: " << AREA << endl;
  // Fill in the condition length > width by using only the pointer
  if (*LENGTHPTR>*WIDTHPT) {
    cout << "The length is greater than the width:" <<*LENGTHPTR<< endl;
    cout<<"The address of length is:"<< &LENGTHPTR<<endl;
  }
  // Fill in the condition of width > length by using only the pointer
  else if (*WIDTHPT >*LENGTHPTR) {
    cout << "The width is greater than the length:" <<*WIDTHPT<< endl;
    //Specifies the given address for the pointer variable
        cout<<"The address of length is:"<< &WIDTHPT<<endl;
  }
  else
    cout << "The width and length are the same" << endl;
  return 0;
}