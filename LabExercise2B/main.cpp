/* 
 *  CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 * File:   main.cpp
 * Student: Drew Gonzales
 *Assignment: Programming Assignment Lab 2B
 * DUE DATE: 9/3/202
 */
#include <cstdlib>
#include <iostream> 
#include <cmath>
using namespace std;
/* A string is used to store letters or messages rather than variables 
 *  Char recognizes as a non numeric value, if you assume a variable as a number c++ will run it 
 * 
 * *
 *  Main Program 
 * Description: Ask the user for 3  test scores, first name and last name and then output the average!
 */ 
int main(int argc, char** argv) {
    //declare values for testscore
    std::string firstnamelastname;
    string firstnamelastname2;
    double testscores1;
    double testscores2;
    double testscores3;
    float average;
    //Ask the user for his first-last name 
    cout<< "What is your first name & Last name?" ;
     cin>>firstnamelastname>> firstnamelastname2;
     //Ask for the first test score
            cout<<" Enter Three test scores."<<endl;
            cin>>testscores1>>testscores2>>testscores3;
            //calculation for your averages for your test scores
             average = (testscores1+testscores2+testscores3)/3;
           //output portion
             
             cout<<"Student Average:"<< endl; 
             
             
             
             
             
             cout<<"Student: "<<firstnamelastname<<" "<< firstnamelastname2<< endl;
            cout<<"Score 1 is:"<<testscores1<< endl;
            cout<<"Score 2 is:"<<testscores2<< endl;
            cout<<"Score 3 is:"<<testscores3<< endl;
            cout<<"Your average Test score is:"<<average<< endl;
    return 0;
}

