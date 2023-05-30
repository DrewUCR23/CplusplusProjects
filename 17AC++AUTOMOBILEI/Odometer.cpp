#include "Odometer.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <thread> 
#include <atomic>

Odometer::Odometer(FuelGauge &gauge) : CARMILES(0), NEWCARMILES(0), CARON(false), fuelGauge(gauge) {
}



void Odometer::KNOWCARMILES() { 
    std::cout << "Current car miles: " << CARMILES << std::endl;
}

void Odometer::REPORTCARMILES() {
    std::cout << "Reporting car miles: " << CARMILES << std::endl;
}

void Odometer::INCREMENTCARMILES() {
    if (CARON) {
        CARMILES++;
        std::cout << "Car has been running for " << CARMILES << " seconds." << std::endl;
        if (CARMILES > 999999) CARMILES = 0; // Reset to 0 if maximum exceeded

        if (CARMILES % 32 == 0) {  // For every 32 miles...
            fuelGauge.decrementGas();
            std::cout << "Fuel decreased by 1 gallon. Current fuel: " << fuelGauge.getFuel() << " gallons." << std::endl;
            if (fuelGauge.getFuel() <= 0) {
                std::cout << "Out of fuel! Car is turning off." << std::endl;
                CARON = false;
            }
        }
    }
}

void Odometer::DECREASECARMILES(int decrease) {
    if (CARMILES >= decrease) {
        NEWCARMILES = CARMILES - decrease;
        CARMILES = NEWCARMILES;
        std::cout << "Decreased car miles to: " << CARMILES << std::endl;
    } else {
        std::cout << "Cannot decrease miles below zero" << std::endl;
    }
}

void Odometer::carStatus(int USERINPUT) {
    std::atomic<bool> stopFlag(false);
    std::thread userInputThread([&stopFlag]() {
        int userInput;
        while (true) {
            std::cin >> userInput;
            if (userInput == 5) {
                stopFlag = true;
                break;
            } else if (!std::cin) { // if the stream enters a fail state due to invalid input
                std::cin.clear(); // clear the fail state
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        }
    });

    userInputThread.detach();

    CARON = true;
    std::cout << "Car is now on." << std::endl;

    while (CARON && fuelGauge.getFuel() > 0) {
        INCREMENTCARMILES();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // wait for 1 second

        if (stopFlag) {
            CARON = false;
        }
    }

    if (fuelGauge.getFuel() == 0) {
        std::cout << "Car has run out of fuel." << std::endl;
    } else {
        std::cout << "Car is now off." << std::endl;
    }
}
