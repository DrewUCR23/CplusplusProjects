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
//The purpose of this lab is to demonstrate the use of switch statement over the if statement.
//Next, the purpose of this program will be to emulate a simple calculator as well.
using namespace std;
int main(int argc, char** argv) {
    
    //global defined variables
    double  x = 0.0;
    double y = 0.0;
    char choice = '+';
    int result;
    //double result= 0.0; 
   // expression = a;
    //expression2= b;
     cout << "~~~~~~ Professor Locke's Poor-boy Calculator ~~~~~~~\n";
     cout << "Solves arithmetic expressions using *, /, +, -, &, %"<<endl;
   
   //ask the user for a calculation
    // cout<<"Enter your first number:";
    cin>>x; 
     //cout<<"Enter your second number:";
    cin>>y; 
//arithmetic operator for calculation
    //cout<<"Enter your arithmetic operator:";
    cin>> choice;
    //switch statement  you can use brackets within case examples in order to narrow the scope of specific locally declared and defined variables
       switch(choice) {
           case'+':
           cout<<"Your user input:"<< x<<" + " <<y<<"= "<<x+y<<endl; 
           break;
           case'-':
          cout<<"Your user input:"<< x<<"-" <<y<<"= "<<x-y<<endl;
          break;
           case'&':
       cout<<"Your user input:"<< x<<" & " <<y<<"= "<<pow(x,y)<<endl; 
           break;
           case'/':   
        cout<<"Your user input:"<< x<<" / " <<y<< "= "<<x/y<<endl;
          break;        
           case'*':
          cout<<"Your user input:"<< x<<" * " <<y<<"= "<<x*y<<endl; 
          break;
     //switch (choice)  when we control the given scope values the case statement can self contain other rename local variables similar to if statements with brackets
          // Therefore, you do not need a new switch statement since every case is it's own conditional if statement with a self contained variable.
         case'%': 
         { 
             //challenge part of the lab
          int a = x; 
        int b = y;
     result = a%b;
    cout<<"Your user input:"<< a<<"%" <<b<<"="<<result<<endl; 
         }
        break; 
        {
            
            //default is similar to else
           default:           
        cout<<" Error: Invalid Operator!";
        // break;
     }
    //challenge portion of the project.
    return 0;
}
}
