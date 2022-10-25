/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 * STUDENT:   Drew Gonzales
 * ASSIGNMENT: Lab Exercise 4a
 * DUE DATE:   09/30/2022
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
// The purpose of this lab is to demonstrate the use of for loops and to stop the calc when it hits #.
// Next, the purpose of this program will be to emulate a simple calculator as well.
using namespace std;
int main(int argc, char **argv)
{
  // global defined variables
  double x = 0.0;
  double y = 0.0;
  char choice = '+';
  double result;
  cout << "~~~~~~ Professor Locke's Rich-boy Calculator ~~~~~~~\n";
  cout << "Solves arithmetic expressions using *, /, +, -, &, %" << endl;
  // ask the user for a calculation
  //take input
  
  
  cout<<"Calculator ON"<<endl;
    cin >> x >> choice >> y;
  while (choice != '#')
  {
    // Get formula from user  ////INPUT
    switch (choice)
    {
    case '+':
      cout << "Your user input:" << x << " + " << y << "= " << x + y << endl;
      break;
      cin >> x >> choice >> y;
    case '-':
      cout << "Your user input:" << x << " - " << y << "= " << x - y << endl;
      break;
    case '*': ////PROCESS
      cout << "Your user input:" << x << " * " << y << "= " << x * y << endl;
      break;
    case '/':
      cout << "Your user input:" << x << " / " << y << "= " << x / y << endl;
      break;
    case '&':
      cout << "Your user input:" << x << "&" << y << "= " << pow(x, y) << endl;
      break;
    case '%':
    {
      // challenge part of the lab
      int a = x;
      int b = y;
      result = a % b;
      cout << "Your user input:" << a << "%" << b << "=" << result << endl;
      break;
    }
    default:
      cout << " Error: Invalid operator:" << '"' << choice << '"' << endl;
    } // end of switch
      // end loop here

    cin >> x >> choice >> y;
    
  }
  cout << "CALCULATOR OFF" << endl;
return 0;
}
