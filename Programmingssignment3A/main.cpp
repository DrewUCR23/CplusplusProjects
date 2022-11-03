/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: drew gonzales
 *Charles Lockes
 * CIS-5
 * 
 * PURPOSE OF PROOGRAMMING ASSIGNMENT:
 * Demonstrate writing a function that will open an input file, search for data, close the file and return the data as described below.
 */
#include <iomanip> 
#include <cstdlib> 
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string Population_FILENAME = "worldPopulation.txt";
long int getPopulation(string country) {
    ifstream FILE;
    string country1;
    long int populationsize, p2;
    FILE.open(Population_FILENAME);
    //reads string int string int pattern to output the data datatype accordingly
    //string file3= file1;
    if (!FILE.is_open()) {
        return (-1);
    } //return value can return any value
    while (!FILE.eof()) {
        FILE>>country1;
        //    FILE.ignore();
        FILE >> populationsize;
        if (country1 == country) {
            FILE.close();
            return (populationsize);
        }
    }
    FILE.close();
    return (0);
}
int main(int argc, char** argv) {
    ifstream FILE;
    string country;
    long int population;
    string country2[15];
    int count;
    //ask the user for the country he wants to know the population size of 
    //cout << "Name the country that you wish to know it's population size:\n" << endl;
    cout << left<<setw(25) << "Country: " <<right<< setw(15) << "Population:" << endl;
    do {
        getline(cin, country);
        population = getPopulation(country);
        if(country!="quit" && population >0)
           cout<<left<<setw(25)<<country<<right<<setw(15)<< population << endl;
         if (population ==0)
           cout<<left<<setw(25)<<country<<right<<setw(15)<< "not found" << endl;
    } while (country != "quit");
    
    cout<<"\n End of program"<<endl;
    
    //calls the population quantity  
    return 0;
}
