/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew  Goznales
 * ASSIGNMENT: Lab Exercise 9b
 * DUE DATE:   11/19/2022
 *
 */
/* Place Library References Here */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Variables for holding monthly sales figures
    float TOTAL = 0; // Total of all sales
    float AVERAGE; // Average of monthly sales
    float NUMSALES; // Number of sales to be processed
    // Establish output characteristics
    cout << fixed << showpoint << setprecision(2);
    // Get the number of monthly sales to process from user
    cout << "How many monthly sales will be processed? ";
    cin >> NUMSALES;
    // Fill in the code to dynamically allocate a float array
    // that will hold the monthly sales figures entered by the user.
    //declaring the float array along with the pointer variable that can call the array
    // float NUM = [40];
    float *MONTHLY_SALES = new float (NUMSALES);
    // int  SALESPTR = &NUMSALES; 
    // Get the monthly sales values from the user and store them
    // in the monthly sales array
    if (NUMSALES) {
        //number of months to be processed
        for (int MONTH = 0; MONTH < NUMSALES; MONTH++) {
             cout << "Enter the sales below:" << endl;
            cin >> MONTHLY_SALES[MONTH];
                TOTAL += MONTHLY_SALES[MONTH];
        cout << "Sales for month " << MONTH + 1 << ": $" << MONTHLY_SALES[MONTH] << endl;
        }
    }
        // Skip a line
        cout << endl << endl;
        // Fill in the code to output the monthly sales followed by
        // the average
        AVERAGE = TOTAL / NUMSALES;
        
        
       // monthly sales output
         for (int MONTH = 0; MONTH < NUMSALES; MONTH++) {
    cout << "Sales for month " << MONTH+1 << ": $" << MONTHLY_SALES[MONTH] << endl;
  }
        cout << "Average Monthly Sales:" << AVERAGE << endl;
        // Fill in the code to deallocate memory assigned to the array
        //deallocation means to delete the main memory value accordingly
         delete[] MONTHLY_SALES; 
        return 0;
    }
