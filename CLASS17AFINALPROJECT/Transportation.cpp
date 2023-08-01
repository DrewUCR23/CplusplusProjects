//#include "COLORS.h"
#include "Transportation.h"
#include <exception>
// Instance of structure that we can pass by reference into each method 

int Transportation::GETMOVEMENT() const {
    return MOVEMENT;
}

int Transportation::GETGASREQUIREMENT() const {
    return GASREQUIREMENT;
}

void Transportation::SETMOVEMENT(int value) {
    MOVEMENT = value;
}

void Transportation::SETGASREQUIREMENT(int value) {
    GASREQUIREMENT = value;
}
//you must declare the virtual definitions even if their not going to be used
void Transportation::DISPLAYCOLORS(COLORSTRUCTURE& REF) {
    // Do nothing or some base functionality here
}

void Transportation::COST1() {
    // Do nothing or some base functionality here
}


void CAR::CARINFO() {
    std::cout << "Cars are popular vehicles used for personal transportation." << std::endl;
    std::cout << "They are typically made of materials like steel, aluminum, and fiberglass." << std::endl;
    std::cout << "Cars offer various features such as comfortable seating, advanced technology, and safety systems." << std::endl;
    std::cout << "They are commonly used for commuting, family transportation, and long-distance travel." << std::endl;
    std::cout << "Cars come in different sizes, models, and types, including sedans, SUVs, and sports cars." << std::endl;
    std::cout << "They are powered by internal combustion engines or electric motors." << std::endl;
    std::cout << "Cars have evolved over the years, incorporating fuel efficiency, connectivity, and autonomous driving capabilities." << std::endl;
    std::cout << "They contribute to air pollution and carbon emissions, but efforts are being made to develop eco-friendly alternatives." << std::endl;
}

int CAR::GETMPG() const {
    std::vector<int> GASRANGE = {5, 15, 25, 35, 45, 55, 75, 100};
    
    std::cout << "The average MPG for a car can be from the following: ";
    for (auto i : GASRANGE) {
        std::cout << i;
        if (i != GASRANGE.back()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    
    return MPG;
}

int CAR::GETNUMBEROFWINDOWS() const {
    int SIZE = 4;
    int window[SIZE] = {4, 6, 8, 10};
    std::cout << "A car typically has " << NUMBEROFWINDOWS << " windows." << std::endl;
    std::cout << "However, sometimes cars can have as many as ";
    
    for (int i = 0; i < SIZE; ++i) {
        std::cout << window[i];
        if (i != SIZE - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " windows." << std::endl;
    
    return NUMBEROFWINDOWS;
}

//set the cost value for car as an input 
int CAR::GETCOST() const  {
      return NEWCOST;     
    }
void CAR::SETMPG(int value) {
    MPG = value;
}

void CAR::SETNUMBEROFWINDOWS(int value) {
    NUMBEROFWINDOWS = value;
}
//ANOTHER SETTER 
void CAR::SETCOST(int value)  {
    NEWCOST = value;
}

void CAR::DISPLAYCOLORS(COLORSTRUCTURE& REF) {
    std::cout << "Color Menu\n"
                 "-----------\n"
                 "1. Red\n"
                 "2. Blue\n"
                 "3. Green\n"
                 "4. Yellow\n"
                 "5. Purple\n"
                 "6. Orange\n"
                 "7. Pink\n"
                 "8. Cyan\n"
                 "9. Magenta\n"
                 "10. Brown\n";
    int colorNumber; // This should be dynamically determined
     std::cout << "Please enter the number corresponding to your color choice: ";
    std::cin >> colorNumber;
    std::string colorName = REF.getColor(colorNumber);
    std::cout << "Car color: " << colorName << std::endl;
}

void CAR::COST1() {
    int AVERAGE = 10000;
    std::cout << "The cost of the car is: " << AVERAGE << std::endl;
}
//car composition values 


void CAR::setDoor(const Door& door) {
    this->DOOR = door;
}

Door CAR::getDoor() const {
    return this->DOOR;
}

void CAR::setEngine(const Engine<int>& engine) {
    this->ENGINE = engine;
}

Engine<int> CAR::getEngine() const {
    return this->ENGINE;
}

void CAR::setWheel(const Wheel& wheel) {
    this->WHEEL = wheel;
}

Wheel CAR::getWheel() const {
    return this->WHEEL;
}

//set the values 
void BOAT::SETSPEED(int value) {
    SPEED = value;
}
void BOAT::SETAVERAGECOST(int value) {
    AVERAGECOST = value;
}

void BOAT::SETPROPELLERS(int value) {
    NUMBEROFPROPELLERS = value;
}
void BOAT::SETFUELEFFICIENCY(int value) {
    FUELEFFICIENCY = value;
}

void BOAT::SETTYPICALMAINTENANCE(const std::string& value) {
    TYPICALMAINTENANCE = value;
}
//get the values 
int BOAT::GETSPEED() const {
    return SPEED;
}

int BOAT::GETAVERAGECOST() const {
    return AVERAGECOST;
}

int BOAT::GETPROPELLERS() const {
    return NUMBEROFPROPELLERS;
}
  
int BOAT::GETFUELEFFICIENCY() const {
        return FUELEFFICIENCY; 
    }

std::string BOAT::GETTYPICALMAINTENANCE() const {
    return TYPICALMAINTENANCE;
}
void BOAT::BOATINFO() {
    std::cout << "Boats have been used for thousands of years and provide various functionalities for traveling on water." << std::endl;
    std::cout << "A boat is typically composed of the following components:" << std::endl;
    std::cout << "- Hull: The main body of the boat, responsible for buoyancy and supporting the structure." << std::endl;
    std::cout << "- Deck: The horizontal surface that covers the hull, providing a platform to walk on or store equipment." << std::endl;
    std::cout << "- Superstructure: The upper part of the boat, including cabins, pilot house, and other enclosed areas." << std::endl;
    std::cout << "- Propulsion System: The mechanism that propels the boat, which can be sails, engines, or both." << std::endl;
    std::cout << "- Steering System: Controls the direction of the boat, typically through a rudder or jet system." << std::endl;
    std::cout << "- Electrical System: Provides power for lights, navigation equipment, communication devices, and other electrical components." << std::endl;
    std::cout << "Boats are constructed using various materials, including:" << std::endl;
    std::cout << "- Wood: Traditional boats were often built using wood, such as oak, cedar, or mahogany." << std::endl;
    std::cout << "- Fiberglass: Modern boats commonly utilize fiberglass due to its lightweight and durability." << std::endl;
    std::cout << "- Aluminum: Aluminum boats are lightweight, resistant to corrosion, and suitable for different water conditions." << std::endl;
    std::cout << "- Steel: Larger commercial or military boats may use steel for its strength and robustness." << std::endl;
    std::cout << "Some common uses of boats include:" << std::endl;
    std::cout << "- Recreational Boating: Boats are used for leisure activities like fishing, water sports, and cruising." << std::endl;
    std::cout << "- Commercial Fishing: Fishing boats are specifically designed for capturing fish and other aquatic species." << std::endl;
    std::cout << "- Transportation: Boats serve as a means of transportation for people, goods, and supplies." << std::endl;
    std::cout << "- Water Tourism: Boats offer sightseeing, tours, and transportation services for tourists on the water." << std::endl;
    std::cout << "- Rescue and Emergency Services: Boats are crucial for search and rescue operations during emergencies." << std::endl;
    std::cout << "- Research and Exploration: Boats are used for scientific research, marine biology studies, and exploration of water bodies." << std::endl;
}

//virtual function 1
void BOAT::DISPLAYCOLORS(COLORSTRUCTURE& REF) {
    std::cout << "Color Menu\n"
                 "-----------\n"
                 "1. Red\n"
                 "2. Blue\n"
                 "3. Green\n"
                 "4. Yellow\n"
                 "5. Purple\n"
                 "6. Orange\n"
                 "7. Pink\n"
                 "8. Cyan\n"
                 "9. Magenta\n"
                 "10. Brown\n";

    int colorNumber;
    std::cout << "Please enter the number corresponding to your color choice: ";
    std::cin >> colorNumber;
    std::string colorName = REF.getColor(colorNumber);
    std::cout << "Boat color: " << colorName << std::endl;
}

//virtual function override 2
void BOAT::COST1() {
    std::cout << "The cost of the boat is: " << AVERAGECOST << std::endl;
}

void Lamborghini::COST1() {
    // Implementation of COST
    //return COST;
}

int Lamborghini::GETMPG() const {
    return MPG;
}

//RETURNS THE VALUE
int Lamborghini::GETCOST() const {
    return COST_VALUE;
}

std::string Lamborghini::GETNAME() const {
    return NAME;
}

std::string Lamborghini::GETMAINTENANCE() const {
    std::cout << "The average maintenance for a Lambo is typically an oil change every 500 miles" << std::endl;
    return MAINTENANCE;
}

void Lamborghini::SETMPG(int value) {
   MPG = value;
}

void Lamborghini::SETCOST(int value) {
    COST_VALUE = value;
}

void Lamborghini::SETNAME(const std::string& value) {
    NAME = value;
}

void Lamborghini::SETMAINTENANCE(const std::string& value) {
    MAINTENANCE = value;
}


void Lamborghini::LAMBOMENU(std::string model) {
    if (model == "Huracan") {
        std::cout << "Lamborghini Huracan Details:\n";
        this->SETNAME("Huracan");
        this->SETMPG(14); // Assuming values
        this->SETCOST(250000);
        this->SETMAINTENANCE("High");
        std::cout << "- Displacement: 5.2L V10\n";
        std::cout << "- MPG: " << this->GETMPG() << "\n";
        std::cout << "- Approximate Cost: $" << this->GETCOST() << "\n";
        std::cout << "- Maintenance: " << this->GETMAINTENANCE() << "\n";
    } else if (model == "Aventador") {
        std::cout << "Lamborghini Aventador Details:\n";
        this->SETNAME("Aventador");
        this->SETMPG(15); // Assuming values
        this->SETCOST(417826);
        this->SETMAINTENANCE("Very High");
        std::cout << "- Displacement: 6.5L V12\n";
        std::cout << "- MPG: " << this->GETMPG() << "\n";
        std::cout << "- Approximate Cost: $" << this->GETCOST() << "\n";
        std::cout << "- Maintenance: " << this->GETMAINTENANCE() << "\n";
    } else if (model == "Urus") {
        std::cout << "Lamborghini Urus Details:\n";
        this->SETNAME("Urus");
        this->SETMPG(17); // Assuming values
        this->SETCOST(200000);
        this->SETMAINTENANCE("Medium");
        std::cout << "- Displacement: 4.0L V8 Twin-Turbo\n";
        std::cout << "- MPG: " << this->GETMPG() << "\n";
        std::cout << "- Approximate Cost: $" << this->GETCOST() << "\n";
        std::cout << "- Maintenance: " << this->GETMAINTENANCE() << "\n";
    } else {
        std::cout << "Invalid choice. Please select a valid Lamborghini model.\n";
    }
    std::cout << std::endl;
}

void Lamborghini::LAMBOINFO() {
    std::cout<<"These are the Lambo's you can picked from"<<std::endl; 
    std::cout << "Lamborghini Huracan Details:\n";
    std::cout << "- Displacement: 5.2L V10\n";
    std::cout << "- Approximate Cost: $200,000 - $300,000\n";
    std::cout << "Lamborghini Aventador Details:\n";
    std::cout << "- Displacement: 6.5L V12\n";
    std::cout << "- Approximate Cost: $400,000 - $500,000\n";
    std::cout << "Lamborghini Urus Details:\n";
    std::cout << "- Displacement: 4.0L V8 Twin-Turbo\n";
    std::cout << "- Approximate Cost: $200,000 - $250,000\n";
    return;
}

//color menu logic 
void Lamborghini::DISPLAYCOLORS(COLORSTRUCTURE& REF) {
 int colorNumber;   // Color choice
 std::string chosenColor; //color that corresponds to a given value
    std::cout << "Color Menu\n"
                "-----------\n"
                "1. Red\n"
                "2. Blue\n"
                "3. Green\n"
                "4. Yellow\n"
                "5. Purple\n"
                "6. Orange\n"
                "7. Pink\n"
                "8. Cyan\n"
                "9. Magenta\n"
                "10. Brown\n";
      // Ask the user for the color
   bool validInput = false;
while (!validInput) {
    try {
        std::cout << "Enter the color choice for your Lambo (1-10):" << std::endl;
        std::cin >> colorNumber;

        // Validate color choice
        if (colorNumber >= 1 && colorNumber <= 10) {
            chosenColor = REF.getColor(colorNumber);  // Get the color name from the COLORSTRUCTURE
            std::cout << "You've chosen " << chosenColor << " color for your Lambo." << std::endl;
            validInput = true;
        } else {
            std::cout << "Invalid color choice. Please try again." << std::endl;
        }
    } catch (...) {
        std::cout << "An unknown error occurred. Please try again." << std::endl;
    }
}
}

void Lamborghini::BUY(COLORSTRUCTURE& REF) {
   std::string model;  // Lamborghini model
    int displacement;  // Engine displacement choice
    int colorNumber;   // Color choice
    int CYLINDERS;     // Number of cylinders
    std::string displacementText;  // Engine displacement text
    std::string chosenColor;  // Chosen color text
    //show the lambo menu
    LAMBOINFO(); 
    // Ask the user for the Lamborghini model
    bool validInput = false;
    while (!validInput) {
        try {
    std::cout << "What type of Lambo do you want? (Type 'Huracan', 'Aventador' or 'Urus')" << std::endl;
            std::cin >> model;

            if (model == "Huracan" || model == "Aventador" || model == "Urus") {
                LAMBOMENU(model);  // If the model is valid, call the LAMBOMENU function
                validInput = true;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } catch (...) {
            std::cout << "An unknown error occurred. Please try again." << std::endl;
        }
    }
    // Ask the user for the number of cylinders
    validInput = false;
    while (!validInput) {
        try {
            std::cout << "How many cylinders do you want for your Lamborghini? (4, 6, 8, 12)" << std::endl;
            std::cin >> CYLINDERS;

            Engine<int> lamboEngine;

            if (CYLINDERS == 4 || CYLINDERS == 6 || CYLINDERS == 8 || CYLINDERS == 12) {
                lamboEngine.SETCYLINDERS(CYLINDERS);  // If the choice is valid, set the cylinders
                std::cout << "You've chosen " << CYLINDERS << " cylinders for your Lambo." << std::endl;
                validInput = true;
            } else {
                std::cout << "This value is invalid. Please try again." << std::endl;
            }
        } catch (...) {
            std::cout << "An unknown error occurred. Please try again." << std::endl;
        }
    }

    // Ask the user for the engine displacement
    validInput = false;
while (!validInput) {
    try {
        std::cout << "Enter the displacement choice for your Lambo:" << std::endl;
        std::cout << "1. 5.2L V10" << std::endl;
        std::cout << "2. 6.5L V12" << std::endl;
        std::cout << "3. 4.0L V8" << std::endl;
        std::cin >> displacement;

        // Check for cin failure due to wrong input type
        if (std::cin.fail()) {
            std::cin.clear();  // Clear error state
            std::cin.ignore();  // Ignore wrong input
            throw std::invalid_argument("Invalid input, please enter a number.");
        }

        Engine<std::string> lamboEngineDisplacement;
        // Check for invalid displacement selection
        if (displacement == 1) {
            displacementText = "5.2L V10";
            validInput = true;
        } else if (displacement == 2) {
            displacementText = "6.5L V12";
            validInput = true;
        } else if (displacement == 3) {
            displacementText = "4.0L V8";
            validInput = true;
        } else {
            throw std::invalid_argument("Invalid displacement choice. Please try again.");
        }

        // If validInput is still true at this point, it means the input was successfully processed
        if (validInput) {
            lamboEngineDisplacement.SETDISPLACEMENT(displacementText);
            std::cout << "You've chosen " << lamboEngineDisplacement.GETDISPLACEMENT() << " for your Lambo." << std::endl;
        }
    } 
    catch (std::exception& e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    } 
    catch (...) {
        std::cout << "An unknown error occurred. Please try again." << std::endl;
    }
}
    // Ask the user for the color
 //pick a color 
    DISPLAYCOLORS(REF);
// Print purchase details
PrintPurchaseDetails(model, CYLINDERS, displacementText, chosenColor);
}
void Lamborghini::PrintPurchaseDetails(const std::string& model, int CYLINDERS, const std::string& displacementText, const std::string& chosenColor) {
    std::cout << "\nCongratulations on your new Lamborghini!" << std::endl;
    std::cout << "Here are the details of your purchase: " << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Cylinders: " << CYLINDERS << std::endl;
    std::cout << "Displacement: " << displacementText << std::endl;
    std::cout << "Color: " << chosenColor << std::endl;
    
    double cost = this->GETCOST(); // get the cost of the chosen model
    std::cout << "Cost: $" << cost << std::endl;
}


