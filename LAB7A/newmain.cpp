/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    your name
 * ASSIGNMENT: Lab Exercise 7a
 * DUE DATE:   10/29/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * Main Program
 * Description: reads a series of gades, calculates
 * simple stats, and counts letter grades, output the stats.
 * The grades are floating point numbers.
 *
 */
int main() {
    // Define Constants
    const int GRADE_COUNT = 240; // Number of grades in file
    const string GRADE_DATA_FILENAME = "Lab7aScores.dat";
    // Define input stream object
    ifstream inFile;
    float highestgrade1 = 0;
    int lowestgrade1 = 101;
    //float lowestGrade, highestGrade;
    float sum, average;
    float grade [240]; //this is an example of an array structure

    // ??? Define an array that will hold the grades. Intialize to 0's.
    // Open the intput file
    inFile.open(GRADE_DATA_FILENAME);
    if (inFile.is_open()) {
        // ??? Using a for loop, read the data into the array
        // ??? Using another for loop, calculate the average grade
        // and find the lowest and highest grades.
        for (int i = 0; i < 240; i++) { //when you are writing an arra make sure to speciy the index value
            inFile >> grade[i];
            //cout << grade[i] << endl;
            if (grade[i] < lowestgrade1) {
                lowestgrade1 = grade[i];
            }  if (grade[i] > highestgrade1) {
                highestgrade1 = grade[i];
            }

        }
    } else {
        cout << "\nUnable to open file \"" << GRADE_DATA_FILENAME << "\".\n";
    }
    // use for loop to find the average grade.
    for (int i = 0; i < 240; i++) {
        //a variable always need a semicolon
        sum = sum + grade[i];
    }
    average = sum / GRADE_COUNT;
    //  inFile.close;
    // Challenge (optional)
    //cout << "Grade A:" << endl;
    // cout << "Grade B:" << endl;
    //cout << "Grade C:" << endl;
    //cout << "Grade D:" << endl;
    //cout << "Grade F:" << endl;
    // ??? Output the number of 'A' grades, 'B' grades, etc. 
    
    cout<<"The number of grades read is:"<<GRADE_COUNT<<endl;
    cout << "Lowest Grade:" << setw(4)<<fixed<<setprecision(1)<<lowestgrade1 << endl;
    cout << "Highest Grade:" <<setw(6)<< fixed<<setprecision(1)<<highestgrade1 << endl;
    cout << "Average Grade:" << setw(5)<<fixed<<setprecision(1)<<average << endl;
    return 0;

}

