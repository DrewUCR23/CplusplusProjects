/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    <your name>
 * ASSIGNMENT: Lab Exercise 7c
 * DUE DATE:   11/05/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
/*
 * Place Global Constants Below
 */

//predefined constant values
const string INPUT_FILENAME = "Lab7cScores.dat";
const int ROWS = 9; // Number of students
const int COLS = 6; // Number of assignments
const int FIELD_WIDTH = 9;
// spacing for student headers
const auto F1 = 10;
const auto F2 = 25;
const auto F3 = 18;
const auto F4 = 10;
const auto F5 = 10;
const auto F6 = 20;
const auto F7 = 30;
const auto F8 = 25;
//Place Functions or Function Protypes Below
//displays titles for students and grade info

void studentheaders() {
    cout << left
            //<< setw(F1) << "Student "
            << setw(F2) << "Student Name"
            << right
            << setw(F3) << "ASGN-1"
            << setw(F4) << "ASGN-2" << endl
    << setw(F5) << "ASGN-3" << endl
    << setw(F6) << "ASGN-4" << endl
    << setw(F7) << "ASGN-5" << endl
    << setw(F8) << "ASGN-6" << endl;
}

//template <class htype>
/*void displayStudentData(htype hdr, string studentname[ROWS], float GRADE[][COLS], float GRADE1[][COLS]) {  
    for(int i =0; i<9; i++)  {
       cout << left << setw(F1) << hdr;
        // keeping the track
          cout<<setw(F2) << studentname[i];
    for(int j =0; j<6; j++) {
            //<< setw(F2) << studentname
            cout<< right
            << setw(F3) << GRADE[i][j]
            << setw(F4) << GRADE1[i][j]
             <<setw(F5) 
              << endl;
    }
    }
}
 */

/* Filename: openInputFile
 * Descritpion: Opens the named input file using the provided 
 * ifstream object. Filename parameter defaults to INPUT_FILENAME
 * constant. Returns false if file failed, true if file is open.
 */
bool OPENINPUTFILE(ifstream& inputFile, string inputFilename = INPUT_FILENAME) {
    // Open the requested file
    inputFile.open(inputFilename);
    // Return false if failed, true if not
    return !inputFile.fail();
}
/*
 * Main Program
 * Description: <Demonstrate use of a matrix, reading data from a file into a matrix
 *  performing matrix operations, outputting data from arrays.>
 */
int main() {
    // The algoritm for writing this program is show below.
    // ??? Declare an array to store the student names.
    // Use the ROWS defined above for the array size.
    //PARALLEL ARRAYS
   // ??? Declare a two-dimensional array to store the data from the file.
  // Use the ROWS and COLS constants defined above for the array size.
    float GRADE[ROWS][COLS];
    string STUDENTN[ROWS];
    float GRADEAVERAGE, SUM;
    string STUDENT[ROWS];
    SUM = 0;
    // Declare stream object 'dataIn'.
    ifstream dataIn;
    //check if the file is open and check otherwise if it fails 
    // Check to make sure file opened (using value retuned by the function)
    if (OPENINPUTFILE(dataIn,INPUT_FILENAME)) {
        // ??? Read the table data from the file into the array.
            // ADDING second while loop to keep track of index
      //  while (count < ROWS  && dataIn >> STUDENTN[count]) {
        for (int count =0; count < ROWS; count++) {
            dataIn>>STUDENTN[count];
            //reading the second level of columns after the rows
            //while (C1 < COLS && dataIn >> GRADE[count][C1]) {
                       for (int C1=0; C1< COLS; C1++) {
            dataIn>>GRADE[count][C1];
            }
        }
        
        //store a second level of string 
         for (int count =0; count < ROWS; count++) {
            dataIn>>STUDENT[count];
        }
        
 
        //for loop for finding the the values
       // studentheaders();
        cout<<"\n"<<endl;
        
        // this should read the in the pattern of string>>integer>>>string>>integer and pull the information from the multidimensional array 
        // the iostreams have no effect on moving the strings to the left hand side
        for (int i = 0; i < 9; i++) {
            // keeping the track
                  cout<<STUDENTN[i];
            for (int j = 0; j < 6; j++) {
             cout<<right<< setw(10)<<GRADE[i][j]<<endl;                
            }
    }  
        //printing the average for grade
        cout << "Class Average:"  << GRADEAVERAGE << endl;
                //output for the STUDENT DALTA      
        // ??? Close the output file.
        dataIn.close();
        // ??? Output the array to the screen as a table using FIELD_WIDTH
        // for each entry using 1 digit of precision.
        // FINDING GRADE AVERAGE
        for (int i = 0; i < ROWS; i++) {
         for (int k = 0; k<COLS; k++) {
             SUM = SUM + GRADE[i][k];
         }
            cout << "\n" << endl;
        }
        GRADEAVERAGE = SUM / 9*6;
    } else
        cout << "Failed to open input file: " << INPUT_FILENAME << ".\n";
    return 0;

}
