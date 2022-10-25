/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew Gonzales
 * ASSIGNMENT: Lab Exercise 3B
 * DUE DATE:   09/17/2022
 *
 */

/*
 * Main Program
 * Description: This assignment will demonstrate the use of  floating point numbers and integers along with the  setw
 * method. This program will calcUlate total cost of the order, ask for the item, price per unit and the quantity of the given purchase and give the total cost of that
 * order.
 */
// it is essential to use the <iomanip> include function in order to use an output field of setw(x)
 //this value is restricted within the parameters of roughly 25 before the value resets
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
    //global variables 
    float UP,Q, TP; 
    string IN;
 
    //Input Vales
    cout<<"What is the item name:";
    getline(cin,IN);
    cout<<"What is the unit price for this item:";
    cin>>UP; 
    //getline can only be used to extract values from strings rather than integers
    cout<<"What is the quantity of the item you've purchased?:";
    cin>>Q; 
    // basic outputs
    
    
    // fixed and set precision determines the amount of the printed values of zero, by using the fixed amount more heavily influences the digit amount.
    cout<<"Item Name:"<<setw(1)<<"    "<<IN<<endl;
    cout<<"Unit Price:"<<setw(8)<<"$****"<<UP<< endl; 
    cout<< "Quantity:"<<setw(15)<<Q<< endl;
    cout<<"Total price:"<<setw(6)<<"$***"<<fixed<<setprecision(2)<<UP*Q<< endl;
    return 0;
}

