#include "FuelGauge.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>



// This will increment the amount of gas accordingly

void FuelGauge::incrementGas(int GASQUANTITY, int GASTYPE) {
    std::vector<int> GASFUELING;
    if (GASQUANTITY <= 22) {
        for (auto i = 0; i < GASQUANTITY; ++i) {
            GASFUELING.push_back(i+1);
            std::cout << "Your car is currently fueling now" << std::endl;
            std::cout << "Your car currently has "<< GASFUELING[i] << " gallons of gas." << std::endl;
        }
        fuel += GASQUANTITY;
        std::cout << "You've added " << GASQUANTITY << " gallons today." << std::endl;
        std::cout << "Your current gas is at " << fuel << " gallons." << std::endl;
    } else {
        std::cout << "Your input is beyond the maximum allotted limit for this given car gas odometer. Try again" << std::endl;
    }
}

void FuelGauge::decrementGas() {
    if (fuel > 0) {
        --fuel;
    } else {
        std::cout << "You're out of gas!" << std::endl;
    }
}



void FuelGauge::checkFullTankCost() {
    double costPerGallon = 15;
    double tankCapacity = 22.0; // gallons
    double mpg = 32.0; // miles per gallon
    double fullTankCost = costPerGallon * tankCapacity;
    double fullTankMiles = mpg * tankCapacity;
    std::cout << "The cost to fill up the tank is: $" << fullTankCost << std::endl;
    std::cout << "The car can drive " << fullTankMiles << " miles on a full tank." << std::endl;
}
int FuelGauge::getFuel() {
    return fuel;
}
// This function tells how much gas there is

void FuelGauge::knowGas() {
    std::cout << "The current amount of gas you have is: " << getFuel() << std::endl;
}

// This reports the amount of gas on command

void FuelGauge::checkGas() {
    std::cout << "Your car has: " << getFuel() << " gallons of gas." << std::endl;
}

FuelGauge::FuelGauge() {
    fuel = 0;
    fuel2 = 0;
}

