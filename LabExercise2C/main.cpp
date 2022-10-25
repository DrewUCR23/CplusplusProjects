/*    CLASS 10 CIS-5-44378/44380 FALL 2022
 *
 * Student: Drew Gonzales
 * ASSIGNMENT: Programming Assignment Make a calculation
 * Due date: 09/7/202
 */

/* 
 * 
 * Drew Gonzales
 *
 * Main Program:  
 The goal of this exercise is to practice and demonstrate the use of floating point numbers in 
 * in arithmetic formulas 
 * Description:
 */ 

#include <cstdlib>
#include <iostream> 
#include <cmath>
using namespace std;
/*
 *
 * 
 */

 int main(int argc, char** argv) {
    //GLOBAL DEFINED VARIABLES
    float triangleS,triangle2,triangle3; 
    float a;
    float hf2a;
   //Ask user for input on all 3 sides of the triangle
    cout<< "Herons Formula:"<< endl;
    cout<<"Give the length for the 3 sides of the triangle!"<< endl;
    cin>>triangleS;
    cin>>triangle2;
    cin>>triangle3;
    //CALCULATION 
    a = (triangleS+triangle2+triangle3)/2;   
    hf2a = sqrt(a*(a-triangleS)*(a-triangle2)*(a-triangle3));
    //OUTPUT for the side lengths and calculate A
    cout<<"The values of the 3 sides:"<<triangleS<<"   "<<triangle2<<"    "<<triangle3<<endl;
    cout <<"The value for herons formula step one:"<<a<<endl;
    cout <<"The value for the total AREA:"<<hf2a<<endl;
          
    return 0;
}

