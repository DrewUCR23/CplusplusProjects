/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Your Name
 * ASSIGNMENT: Lab Exercise 9c
 * DUE DATE:   11/19/2022
 */
/* Place Library References Here */
#include <iostream>
#include <iomanip>
using namespace std;
/*
 * Function Name: allocateList
 * Description:   Dynamically allocates a float array with "num"
 *                elements and returns the pointer.
 */
float *ALLOCATELIST(int NUMOFSALES)  {
    // Fill in the code to complete this function
    float *NUM = new float (NUMOFSALES);
    return(NUM);
}
int main()
{
  // Variables for holding monthly sales figures
  float TOTAL = 0;  // Total of all sales
  float AVERAGE;    // Average of monthly sales
  int  NUMOFSALES; // Number of sales to be processed
  // Establish output characteristics
  cout << fixed << showpoint << setprecision(2);
  // Get the number of monthly sales to process from user
  cout << "How many monthly sales will be processed? ";
  cin >> NUMOFSALES;
  // Fill in the code to dynamically allocate a float array
  // by calling the allocateList function.
  float *MONTHLYSALES = ALLOCATELIST(NUMOFSALES);
  // Get the monthly sales values from the user and store them
  // in the monthly sales array
  for (int month = 0; month < NUMOFSALES; month++) {
    cout << "Enter the sales for month " << month + 1 << ": $";
    cin  >> MONTHLYSALES[month] ;
  }    
  // Output Table Title
  cout << "\n\nMonthly Sales\n\n";
  // Output the monthly sales followed by the average.
  for (int month = 0; month < NUMOFSALES; month++) {
    cout << "Sales for month " << month+1 << ": $" << MONTHLYSALES[month] << endl;
    TOTAL += MONTHLYSALES[month];
  }
  AVERAGE = TOTAL/NUMOFSALES;
  cout << "Average Monthly Sale is $" << AVERAGE << endl;
  // Deallocate memory assigned to the array
  delete [] MONTHLYSALES;
  return 0;
}
