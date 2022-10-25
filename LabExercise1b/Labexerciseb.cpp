/* 
 * 
 * Class ID: CIS/CSC-5-4863/48683
 *Student:  Drew Gonzales 
 * Assignment: Lab Exercise 1B
 * Due Date: 08/27/2022
 */


#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/* Main Program
 * Description < priv-1 demonstration>
 */
int main() {
    
    double hours, rate,  pay;
    //Get the number of hours worked
    cout << "How many hours did you work? ";
    cin >> hours;
    
    //Get the hourly pay rate 
    cout << "How much do you get paid per hour? ";
    cin >> rate;
    
    //Calculate the pay
    pay = hours * rate;
    
    //Display the pay
    cout << "Drew Gonzales earned $ "   << pay << endl;
            
    return 0;
}

