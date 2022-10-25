/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew Gonzales
 * ASSIGNMENT: Lab Exercise 4b
 * DUE DATE:   09/24/2022
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
 * Main Program
 * Description: <describe what main program does>
 */
int main(int argc, char** argv) {
  // Named constants for customer status codes
  const char NORMAL  = 'N';
  const char STUDENT = 'S';
  const char RETIREE = 'R';
  const char VETERAN = 'V';
  // Named constants for the discount amounts
  const double NORMAL_DISCOUNT          = 0.00;
  const double STUDENT_DISCOUNT         = 0.10;
  const double RETIREE_VETERAN_DISCOUNT = 0.20;
  
  // Output constants
  const auto LABEL_WIDTH = 17;
  const auto NUM_WIDTH   =  8;
  // Define variables used in program
  char   customerS;  // User input
  double amountSpent;     // User input
  double discount;        // Set to discount amount based on customer status
  double amountPaid;      // Amount paid after discount
  double discount1;      // stores the percent values for varying discounts of N S R V characters
  // Display Welcome Banner
  cout << "\n\nWelcome to Professor Locke's Organic Market and Holistic Dispensary\
n\n";
  // Get the customer statis form the cashier
  cout << "Enter the customer status (N)ormal, (S)tudent, (R)etiree, or (V)eteran:";
  cin >> customerS;
   // If a lower-case status is entered, convert it to upper case.
  customerS = toupper(customerS);
  // Get the amount spent by the customer from the cashier
  cout << "Enter amount spent: ";
  cin >> amountSpent;
  // Calculation for discount
  //IF Statements for given discount values 
   if (customerS == 'N') {
      
      discount = amountSpent*NORMAL_DISCOUNT;
      cout<<"Normal discount"<<amountSpent*NORMAL_DISCOUNT<<endl; 
    
  }
   else if (customerS == 'S') {
       discount = amountSpent*STUDENT_DISCOUNT;
          discount1= STUDENT_DISCOUNT;
 }
   else if (customerS =='R') {
     
       discount = amountSpent*RETIREE_VETERAN_DISCOUNT; 
        discount1= RETIREE_VETERAN_DISCOUNT;
   }
   else if (customerS == 'V') {
       discount = amountSpent * RETIREE_VETERAN_DISCOUNT;
      discount1= RETIREE_VETERAN_DISCOUNT;
       
   }
   //amount paid- discount
    amountPaid = amountSpent -discount;
  // Output the customer receipt
  cout << fixed << setprecision(2) << endl; // Set numeric output format and add an
  cout << left << setw(LABEL_WIDTH) << "Customer status:"  << ' ' << right << 
setw(NUM_WIDTH) << customerS   << endl;
  cout << left << setw(LABEL_WIDTH) << "Amount spent:"     << '$' << right << 
setw(NUM_WIDTH) << amountSpent      << endl;
  cout << left << setw(LABEL_WIDTH) << "Discount:"         <<'%' << right << 
setw(NUM_WIDTH) << 100.0*discount1 << endl;
  cout << left << setw(LABEL_WIDTH) << "Amount paid:"      << '$' << right << 
setw(NUM_WIDTH) << amountPaid       << endl;
  
  //100.0 * discount
  
  cout << "\nThank you for shopping at PLOM&HD\n";
  
  return 0;  
}

