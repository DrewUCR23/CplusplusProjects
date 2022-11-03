/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
//Spacing for students headers
const auto F1 = 10;
const auto F2 = 15;
const auto F3 = 8;
const auto F4 = 8;
/*
 * Place Global Constants Below
 */
const int GRADE_WIDTH = 8; // Width of numeric output fields
const int NAME_WIDTH = 15; // Challenge only
const int PRECISION = 1; // Test score output precision
const int MAX_STUDENTS = 30; // Process up to 30 students
const int NUM_GRADES = 2; // Grades recorded per student
/*
 * Place Functions or Function Protypes Below
 */ //display student names

void studentheaders() {
    cout << left
           // << setw(F1) << "Student "
            << setw(F2) << "Student Name"
            << right
            << setw(F3) << "ASGN-1"
            << setw(F4) << "ASSGN-2" << endl;
}
// Display country information
template <class htype>
void displayStudentData(htype GRADE_WITH, string studentname, float grade, float grade1) {
    cout << left
            << setw(F2) << studentname
            << right
            << setw(F3) << fixed<<setprecision(1)<<grade
            << setw(F4) << fixed<<setprecision(1)<<grade1
            << endl;
}
/*
 * Main Program
 * Description: Read and display student names and scores
 * followed by the class average. Demonstrate using parallel
 * and partially filled arrays.
 */
int main() {
    // Variable for user entered filename
    // ??? Declare parallel arrays to hold the data 
    float grade[MAX_STUDENTS] = {};
    float  grade1[MAX_STUDENTS] = {};
    string studentName[MAX_STUDENTS] = {};
    float sum, gradeaverage;
    sum = 0;
    //define the object
    fstream DATA;
    string FILE; 
    //ASK FOR THE FILE
    cout<< "What file name would you like to put in?"<<endl;
    getline(cin, FILE);
    //OPEN THE FILE
    DATA.open(FILE);
    //if statement if the file is open
    int count = 0;
     studentheaders();
  while (count < MAX_STUDENTS && DATA >> studentName[count] >> grade[count] >> grade1[count]) {
      displayStudentData<int>(count, 
              studentName[count],
              grade[count], 
              grade1[count]);
    count++; 
  }
    //Find the general average
    for(int i = 0; i < MAX_STUDENTS; i++) {
        sum = sum+ grade[i]+grade1[i];
    }
    gradeaverage = sum/18;  
    //output for average 
    cout<<"\n";
    cout<< "Class Average:"<<fixed<<setprecision(1)<<setw(9)<<gradeaverage<<endl;
    return(0);
}

    
    