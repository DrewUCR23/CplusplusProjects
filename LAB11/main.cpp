/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:  Drew Gonzales
 * ASSIGNMENT: Lab Exercise 11a
 * DUE DATE:   12/03/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
/*
 * Main Program
 * Description: Define  structure, initilaize the fields, output the data from the 
structure.
 */
int main() {
    
    // Define the planetData structure here
    // ???
    struct PLANETDATA {
         // Declare  variable here of tyype planetData
        string name;  //string for the planet
        float MASS;    // mass for the planet
        float diameter;   // size of the planet
        float GRAVITY;   // amount of gravity 
        float RP;       //rotation period
        float LOD;        //length of DAY
        float DFS;     //Distance from sun
        float MT;       // MEAN TEMPERATURE 
        float NOM;     //NUMBER OF MOONS
        string RING;   //RING SYSTEM IS DEFINED AS BOOL Y/N   
    };
    
    // Intialize it with the data for one of the planets in the assigment
    // ???
    PLANETDATA PLANET = {"Earth",5.97,12756,9.8,23.9,24.0,149.6,15,1,"No"};
    // Output the planet data from the structure as shown in the assignment
    // ???
    cout<<"PLANET NAME:"<<setw(15)<<PLANET.name<<endl;
    cout<<"MASS:"<<setw(21)<<PLANET.MASS<<endl;
    cout<<"DIAMETER:"<<setw(18)<<PLANET.diameter<<endl;
    cout<<"Gravity:"<<setw(17)<<PLANET.GRAVITY<<endl;
    cout<<"Rotation Period:"<<setw(10)<<PLANET.RP<<endl;
    cout<<"Length of Day:"<<setw(10)<<PLANET.LOD<<endl;
    cout<<"Distance From Sun:"<<setw(9)<<PLANET.DFS<<endl;
    cout<<"Mean Temperature:"<<setw(7)<<PLANET.MT<<endl;
    cout<<"Number of Moons:"<<setw(7)<<PLANET.NOM<<endl;
    cout<<"Ring System:"<<setw(12)<<PLANET.RING<<endl;
    return 0;
}