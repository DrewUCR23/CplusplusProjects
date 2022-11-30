/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew  Goznales
 * ASSIGNMENT: Programming Assignment 5
 * DUE DATE:   11/28/2022
 *
 * 
 * object for assignment: This assignment will ascertain if a file follows bendfords law or not
 */
/* Place Library References Here */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
    //ifstream FILE;
    string FILE1;
    //string NUMBER;
    // ARRAY of values for this function
    int n = 9;
    int BEDFORD[9] = {0};
    string firstChar;
    int num;
    ifstream myfile;
    cout << "Enter the file you want to read:";
     cin >> FILE1;
    myfile.open(FILE1);
    string myline;
    cout<<"Benford's Law"<<endl;
    if (myfile.is_open()) {
        getline(myfile, myline);
        while (getline(myfile, myline)) { // equivalent to myfile.good()
            //Read the first character of every string
            firstChar = myline.substr(0, 1);
              //convert integer values to string values
            num = stoi(firstChar);
            //allocate the values for the iterations in accordance to benfords law from 1-9 each num value now stores the counts of 1-9 which can
            //be searched later
            BEDFORD[num] = BEDFORD[num] + 1;
        }
 //output for the name of benfords law
        cout<<myline<<endl;
        //for loop that searches the array for the number of digits 1-9 and prints the horizional lines in accordance to the iterations
        //counted within the given file.
        
        
        for (int i = 1; i <= n; i++) {

            cout << i << ": ";
            for (int j = 0; j < BEDFORD[i]; j++) {
                //output for benfords law that matches the number of 1st digits 
                //from 1-9
                cout << "-";
            }
            cout << "\n";
        }
    } else {
        cout << "Couldn't open file\n";
    }
    return 0;
}

