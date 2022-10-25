/*    CLASS 10 CIS-5-44378/44380 FALL 2022
 *
 * Student: Drew Gonzales
 * ASSIGNMENT: Programming Assignment Make a calculation
 * Due date: 09/7/202
 */

/* 
 * 
 * Drew Gonzales
 *
 * Main Program:  
 The goal of this exercise is to practice and demonstrate the use of floating point numbers in 
 * in arithmetic formulas 
//// * Description:
 */ 
/*    CLASS 10 CIS-5-44378/44380 FALL 2022
 *
 * Student: Drew Gonzales
 * ASSIGNMENT: Programming Assignment Make a calculation
 * Due date: 09/7/202
 */

/* 
 * 
 * Drew Gonzales
 *
 * Main Program:  
 The goal of this exercise is to practice and demonstrate the use of floating point numbers in 
 * in arithmetic formulas 
//// * Description:
 */ 

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
//global defined variables
    int Carnumber, Laps;
    string DriverL;
    float COSTPL1, TC,COSTPL2;
    const double rookie = 2.00;
    const double novice = 1.80;
    const double contender = 1.60;
    const double champion = 1.40;
   //print statements
    cout<<"Professor Locke's Get-Up-And-GoKart Track"<<endl;
    //User input
    cout<< "What is your car number?"<<endl;
    cin>>Carnumber;
     //error message 
      if (Carnumber<0 || Carnumber >99) { 
            cout<<"Key Scan error"<< endl;   
            exit(0);
    }
    cout<< "How many laps did you do?"<<endl; 
    cin>>Laps;
    // statements that identify how many laps you've run and how many levels
    // or || and &&
    if (Laps <= 19 && Laps>=0)  {
        COSTPL2= rookie;
        COSTPL1 = Laps*rookie;
        DriverL = "Rookie";
        cout<<" You have achieved the rank of rookie"<<endl;
    }
    else if ( Laps>=20 && Laps<=29) {
        COSTPL2 = novice;
         COSTPL1 = Laps*novice;
        DriverL = "Novice";
        cout<<"You have achieved the rank of novice"<< endl;
    }
    else if (Laps>=30 && Laps<=49){
        COSTPL2= contender;
         COSTPL1 = Laps*contender;
        DriverL = "Contender";
        cout<<"You have achieved the rank of contender!"<< endl;
    }
    else if (Laps>=50 && Laps<=200) {
        COSTPL2= champion;
         COSTPL1 = Laps*champion;
        DriverL = "Champion";
        cout<<"You have achieved the rank of Champion with 50+ laps!"<< endl;
    }
    else {
        cout<<"This is an error you put in the wrong input!"<< endl;
    exit(0);
    }
   //calculations 
    TC = COSTPL1;
    //output
    cout<<"Car number:"<<setw(14)<<Carnumber<<endl;
    cout<<"Laps Completed:"<<setw(10)<<Laps<<endl;
    cout<<"Driver Level:"<<setw(12)<<DriverL<<endl;
    cout<<"Cost per Lap:"<<fixed<<setprecision(2)<<setw(4)<<"$"<<setw(8)<<COSTPL2<<endl;
    cout<<"Total cost:"<<setw(6)<<fixed<<setprecision(2)<<"$"<<setw(8)<<TC<<endl<<endl;
    
    cout<<"Thank you and drive safely!"<<endl;
    return 0;
}

