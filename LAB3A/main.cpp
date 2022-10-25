/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */
/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    your name
 * ASSIGNMENT: Lab Exercise 3a
 * DUE DATE:   09/9/2022
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
/*
 * Main Program
 * Description: Provdes variables with pre-assigned values. These values 
 * are used to solve formulas written by the student.
 *
 */
int main() {
  //--------------------
  // *** FORMULA 1 ***
  // define variables
  double P   =  1000.00;   // Present Value
  double i   =  0.032567; // Interest Rate per Year
  double t   =  20;      // Number of Years
  double n   =  12;     // Compunding periods per year
  double F;            // results
  
  // Replace ??? with Formula 1
  F = P*(pow(1+i/n,n*t));
  cout << "Formula 1 results = " << F << endl;
  //--------------------
  // *** FORMULA 2 ***
  // Define variables
    double x = 14;     // data variable
  double y;           // results
  
  // Replace ??? with Formula 2
  y = 4*pow(x,3)+ 8*pow(x,2)+9*x-18;
  cout << "Formula 2 results = " << y << endl;
  
  //--------------------
  // *** FORMULA 3 ***
  // Define variables
  double MA = 4.5;      // data variable
  double V;           // results
  V= 1.0/12*sqrt(2)*pow(MA,3); 
    //pow represent a possible square root value 
   //since you need an extension to write sqrt(function)
       cout << "Formula 3 results = " << V << endl;
  // *** FORMULA 4 ***
  // Define values
   double a = 3.5;  // data variables
  double b = 4.5; // 
  double A;      // results
  
//////////////////////////////////////////////
  A = M_PI*(a/2)*(b/2);
  cout << "Formula 4 results = " << A << endl;
  
  //-------------------
  // *** FORMULA 5 ***
  // Define variables
  double x1 = 0.0;    // Data variables
  double y1 = 2.0;   //
  double x2 = 5.0;  //
  double y2 = 0.0; //
  double D;       // results
  // Replace ??? with Formula 5
  D = sqrt(pow(x2-x1,2)+ pow(y2-y1,2));
  cout << "Formula 5 results = " << D << endl;
  cout << "End of Lab Exercise 3a" << endl; 
  return 0;
  
}

