/* Drew Gonzales
 * 3/24/2023
 * Introduction to C++ OBJECTS
 * Professor Paul Conrad 
 * 3/24/2023
 * Objective: The objective of this project is to create a structure of arrays which will store values
 * for total rainfall, total snowfall, low temperature along with outputting the average temperature as well
 */
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

    struct WEATHERSTATS {
        double TOTAL_RAINFALL;
        double TOTAL_SNOWFALL;
        double high_temperature;
        double low_temperature;
        double average_temperature;
    };

    WEATHERSTATS WEATHER[12];
    std::string MONTHNAMES[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December"};
    int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::cout << "Enter all the data for each month" << std::endl;
    std::cout << "Enter the information for all 12 Months" << std::endl;

    int counter = 0;
    double totalAverageTemperature = 0;

    while (counter < 12) {
        std::cout << "Enter the data for " << MONTHNAMES[counter] << ":" << std::endl;
        std::cout << "Enter the total rainfall: ";
        std::cin >> WEATHER[counter].TOTAL_RAINFALL;
        std::cout << "Enter the total snowfall: ";
        std::cin >> WEATHER[counter].TOTAL_SNOWFALL;
        std::cout << "Enter the high temperature: ";
        std::cin >> WEATHER[counter].high_temperature;
        std::cout << "Enter the low temperature: ";
        std::cin >> WEATHER[counter].low_temperature;

        // Input validation for temperature
        if (WEATHER[counter].low_temperature < -150 || WEATHER[counter].high_temperature > 150) {
            std::cout << "You entered an invalid value. Try again." << std::endl;
            continue;
        }
        if (WEATHER[counter].TOTAL_SNOWFALL < 0 || WEATHER[counter].TOTAL_RAINFALL < 0) {
            std::cout << "This value is not valid. Enter a valid snowfall and total rainfall value." << std::endl;
        } else {
            WEATHER[counter].average_temperature = (WEATHER[counter].high_temperature + WEATHER[counter].low_temperature) / 2;
            totalAverageTemperature += WEATHER[counter].average_temperature;
            counter++;
        }
    }

    for (int i = 0; i < 12; i++) {
        std::cout << MONTHNAMES[i] << " Total RainFall: " << WEATHER[i].TOTAL_RAINFALL << std::endl;
        std::cout << MONTHNAMES[i] << " Average RainFall: " << WEATHER[i].TOTAL_RAINFALL / DAYS_IN_MONTH[i] << std::endl;
        std::cout << MONTHNAMES[i] << " Total Snowfall: " << WEATHER[i].TOTAL_SNOWFALL << std::endl;
        std::cout << MONTHNAMES[i] << " Average SnowFall: " << WEATHER[i].TOTAL_SNOWFALL / DAYS_IN_MONTH[i] << std::endl;
        std::cout << MONTHNAMES[i] << " High Temperature: " << WEATHER[i].high_temperature << std::endl;
        std::cout << MONTHNAMES[i] << " Low Temperature: " << WEATHER[i].low_temperature << std::endl;
        std::cout << MONTHNAMES[i] << " Average Temperature: " << WEATHER[i].average_temperature << std::endl;
    }
    double averageMonthlyTemperature = totalAverageTemperature / 12;
    std::cout << "Average of monthly temperatures for all the months: " << averageMonthlyTemperature << std::endl;

    // Exit the program with a status of 0 (success)
    return 0;
}




