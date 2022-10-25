/*  CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 * File:   main.cpp
 * Student: Drew Gonzales
 *Assignment: Programming Assignment Lab 2B, or Lab 2B
 * DUE DATE: 9/3/202
 */


#include <cstdlib>
#include <iostream> 
#include <cmath>
using namespace std;
/*
 *  Main Program 
 * Description: Ask the user to enter the length, width, height of a rectangular box 
 * and then calculate the footprint(area of the bottom and the  given volume of the potential box
 */ 
int main(int argc, char** argv) {
    string box = "Box Dimensions:";
    double length;
    double width;
    double height;
    int dozen = {12};
    
      int number = 23;
     
   
cout << "The number is " << number << endl;
    //double footprint;
    //double volume;
// ask the user for the length 
    cout<<"What is the length";
    cin>>length;
    //calculate/ask the user for the width 
    cout<<"What is the width"<< endl;
    cin>>width;
    //calculate/ask the user for the height
            cout<<"What is the height"<< endl;
            cin>>height;
    //calculate/ask the user for the footprint
            //cout<<"Enter the number for user Footprint."<<endl;
           // cin>>footprint;
      //calculate volume  and ask for volume
            //cin>>volume;
            //The lines will merge if their is no endl to finish the existing codeline
    //output of Length, Width, Height, footprint and volume
            cout<< box << endl;
            cout<< "This is the length: "<< length<< endl;
            cout<<"This is the width: "<<width<<endl;
            cout<<"This is the height: " <<height<<endl;
            cout<<"This is the footprint: "<<length *width<<endl;
            cout<<"This is the volume: " << length *width *height;
    return 0;
}

