/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: drewe
 *
 * Created on October 31, 2022, 10:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * //test out basc values and ideas from memory without needing help
 */
int main(int argc, char** argv) {
    string name;
    float  h1,h2;
     char choice = '-';
     
     cout<<"Welcome to my lovely practice calculaor for coding purposes"<<endl;
     cout<<"You can use the following symbols to manipulate integers"<<"+, -, *, %, /, etc"<<endl;
    cout<< "What's your first name?"<<endl;
    getline(cin,name);
    
    while(choice != '#') {
    cout<<"What character would you like to use?"<<endl;
       cin>>choice;
    cout<< "Enter your first number"<<endl;
    cin>>h1;
    cout<<"Enter your second number"<<endl;
    cin>>h2;
    
    
    if(choice == '+')   {
        float add1;
        add1 = h1+h2;
        cout<<"This is the sum value"<< h1<<"+"<<h2<<"="<<add1<<endl;
    }
    else if (choice =='-')  {
        float add1;
        add1= h1-h2;
        cout<<"This is the difference of these two numbers"<<h1<<"-"<<h2<< "="<<add1<<endl;  
    }
    
    else if (choice == '*')    {
        float add2;
         add2 = h1*h2;
    cout<<"This are these two values multiplied together"<<h1<<"*"<<h2<<"="<<add2<<endl;
    }
    
    else if(choice =='^') {
        float add3;
    add3 = pow(h1,h2);
    cout<<"This is the power of these two given values"<<h1<<"^"<<h2<<"="<<add3<<endl;
    }
    else if(choice=='/') {
        float add4;
        add4= h1/h2;
        
        cout <<"This is the division of these two numbers"<<h1<<"/"<<h2<<"="<<add4<<endl;
        
    }
    
    else if(choice == '%') {
        int add4;
        int a = h1;
        int b = h2;
       add4=  a%b;
        cout<<"This is the remainder of those values"<< h1<<'%'<<h2<<'='<<add4<<endl;
            
}
    else if (choice =='#') {
        
        cout<<"The program has ended"<<endl;
      //  exit(0);
    }
    else  {
        cout<<"This input is not valid right now"<<endl;
    }

    return 0;
}
}