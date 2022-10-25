/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * Name: Drew Gonzales
 * 10/13/2022
 * Due Date: 10-17-2022
 * CLASS: CIS-5 
 * Professor Charles Locke
 */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/* Purpose of program: The purpose of this program is to print a file and output it's content that 
 * describes the salary amounts an their values. Furthermore, it is supposed to demonstrate 3 calculations, average salary
 * highest salary and lowest salary. Finally, this programming assignment is supposed to demonstrate our knowledge and understanding etc.
 */
int main(int argc, char** argv) {    

    
    // Globally declared variables
    //int count keeps track of records processed.
    int count = 0;
    ifstream FILE;
    string file1, file2;
    float salary1, salary2, salary3=0;
    //these values allow us to find the lowest paid job and the highest paid job
    float highsalary =0;
    float lowsalary = 1000000; 
    string readline,readline1,readline2;
    //lowjob and high job keep track of the name and descriptions of the lowest and highest paid jobs in strings.
    string lowjob, lowjob1, highjob, highjob1; 
    //Specify a file you want to open to read an output
    cout<<"Enter the file you want to enter!:"<<endl;
    getline(cin,file1);
    FILE.open(file1.c_str());
   //ofstream OFILE(file2.c_str());
    //if (OFILE.is_open()) {
   //while (getline(FILE,file1)) {
       OFILE<<readline2<< "\n";
  // count++; 
   //}
    //}
   //check the condition to see if the files open
   if (FILE.is_open())
        FILE >> salary1;
   FILE.ignore();
    getline(FILE,readline);  
    count = salary1;
    while(!FILE.eof()) {
    FILE>>readline;
    FILE>>salary1;
    FILE.ignore();
    getline(FILE,readline1);
   cout<<"Enter your output file name "<<endl;
      getline(cin,file2);
    //finds the highest paid job
    if(salary1>highsalary) { 
          highjob = readline;
          highjob1= readline1;
        highsalary = salary1;
    }
    // finds the lowest salary in the document ComputerscienceTopJobs.txt
    if (salary1< lowsalary) {
        lowsalary = salary1;
        lowjob = readline;
        lowjob1 = readline1;
    }
    //Finds the average for salary and reads the given amount
      salary3+=salary1;   
   }
    //FILE OUTPUT FOR THE DOCUMENT, AVERAGE, LOW SALARY, HIGH SALARY
    cout<<"TITLE:"<<setw(50)<<right<<"Drew's Computer Science Job Review \n\n";
    cout<<"Records Processed:"<<setw(14)<<count<<endl;
    cout<<"Lowest Salary:"<<setw(8)<<"$"<<setw(10)<<fixed<<setprecision(2)<<lowsalary<<endl; 
    cout<<lowjob<<setw(7)<<lowjob1<<"\n "<<endl;
    cout<<"Highest Salary:"<<setw(7)<<"$"<<setw(10)<<fixed<<setprecision(2)<<highsalary<<endl;
    cout<<highjob<<highjob1<<"\n"<<endl;
    cout<< "Average Salary:"<<setw(7)<<"$"<<setw(10)<<fixed<<setprecision(2)<<salary3/count<<endl;
   //closes the file
    FILE.close();
    OFILE.close();
    return 0;
}


