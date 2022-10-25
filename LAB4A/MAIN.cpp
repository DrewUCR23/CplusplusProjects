
/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:   Drew Gonzales
 * ASSIGNMENT: Lab Exercise 4a
 * DUE DATE:   09/21/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(int argc, char** argv) {
    
    //global defined variables
    float  x;
    float y;
   // expression = a;
    //expression2= b;
     cout << "~~~~~~ Professor Locke's Poor-boy Calculator ~~~~~~~\n";
  cout << "Solves arithmetic expressions using *, /, +, -, or ^\n\n";
  
   //ask the user for a calculation
   cout<<"Enter an arithmetic expression";
    cin>>x;
     cout<<"Enter an arithmetic expression:";
    cin>>y; 

    //if statement that triggers these expressions -addition
       if (x >= 0) {
       
             cout<<"This is sum of x and y"<<x+y<<x*y<<x-y<<x/y<<endl;
             
             
      
       }  
       else if (x<=0){ 
           cout<<"The value of x and y is less than zero"<< endl;
       }

    //final output for the calculation
    
    //cout<<"Your final calculation is"<<x<<y<<endl; 
    
    return 0;
}
