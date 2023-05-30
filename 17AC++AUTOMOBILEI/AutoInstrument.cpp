/* 
 * Drew Gonzales
 * 5/12/2023
 * Professor Conrad
 * Objective:  The objective of this assignment will be to design a set of classes that simulates the car fuel gauge along with it's odometer
 * In doing so I will demonstrate the various types of classes along with the concepts of encapsulation, private members, public members, getters and setters and much more. 
 */

#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

int main (int argc, char** argv) {

    int USERINPUT, GASQUANTITY, GASTYPE;
    bool caroff = false;

    FuelGauge gauge;
    Odometer odometer(gauge); // The odometer object now has a reference to the gauge object


    std::cout << "WELCOME TO DREW'S automobile instrument" << std::endl;
    std::cout << "NOTE: That when the car is on for every 1 second the mile increase will increment by exactly 1 mile"
            "this will serve to simulate driving and the car mileage to go up to demonstrate that it works"
            "this will be tracked by a tracker which will also report how long the car has been on for:" << std::endl;
    while (USERINPUT != 0) {


        std::cout << "1. TO CHECK HOW MUCH GAS YOU HAVE, " << std::endl
                << "2. TO CHECK HOW MUCH IT COST FOR A FULL TANK OF GAS, " << std::endl
                << "3. To put gas in your car, " << std::endl
                << "4. To check the number of Car miles you have, " << std::endl
                << "5. To turn off your Car, " << std::endl
                << "6. To turn on your Car, " << std::endl
                << "7. To report the Number of Car miles"<<std::endl
                << "0. To end this program accordingly." << std::endl;
        std::cin >> USERINPUT;

        switch (USERINPUT) {

            case 0:
                //this ends the program accordingly 
                break;
            case 1:
                // code to be executed if USERINPUT equals 1
                gauge.checkGas();
                break;
            case 2:
                // code to be executed if USERINPUT equals 2
                // You will need to implement this method in the FuelGauge class
                gauge.checkFullTankCost();
                break;
            case 3:
                // You will need to implement this method in the FuelGauge class
                std::cout << "These are your following choices 87, 89, 91"
                        "87 costs 2.55$, 89 costs 2.75$, 91 costs 3.00$" << std::endl;
                std::cout << "Which type of gas do you want in your car?" << std::endl;
                std::cin >> GASTYPE;
                std::cout << "How much gas do you want in your car?" << std::endl;
                std::cin >> GASQUANTITY;

                gauge.incrementGas(GASQUANTITY, GASTYPE);
                break;
            case 4:
                // Report car miles
                odometer.KNOWCARMILES();
                break;
            case 5:
                odometer.carStatus(USERINPUT);
                break;
            case 6:
                // Turn off car
                odometer.carStatus(USERINPUT);
                break;
            case 7:
                //this will output the number of carmiles and report it accordingly.. 
                odometer.REPORTCARMILES();
                break;

            default:
                // code to be executed if USERINPUT doesn't match any cases
                break;
        }

    }

    return 0;
}
