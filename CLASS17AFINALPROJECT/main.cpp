/* 
Drew Gonzales
 5/29/2023
 * Professor Paul Conrad
 CIS-17A
 * Objective: The objective of this project will be to demonstrate all aspects of understanding of the object oriented programming paradigm. 
 * These aspects are inclusive of, hiding-data-encapsulation, relationships between classes-composition and inheritance along with polyomorphisms and the use of virtual functions. *
Other topics in the course that were discussed to be demonstrated are: reading/writing binary files, operator overloading, and working with exceptions (throwing exceptions inside of classes when an invalid data value is encountered and having the said thrown exceptions be caught inside a try/catch block that is located in the main test driver program). */

#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include "Transportation.h"
#include <exception>

// Function to demonstrate reading/writing binary files
template<typename T>
void BINARYRECEIPT(T& obj) {
    std::ofstream out("TRANSPORTATION.bin", std::ios::binary);
    out.write(reinterpret_cast<char*> (&obj), sizeof (obj));
    out.close();
    T new_obj;
    std::ifstream in("TRANSPORTATION.bin", std::ios::binary);
    in.read(reinterpret_cast<char*> (&new_obj), sizeof (new_obj));
    in.close();

    std::cout << new_obj;
}
//Here we can read the relevant data from the text file next 
// Here we can read the relevant data from the text file next// Here we can read the relevant data from the text file next

void TEXTFILE(int CHOICE, const std::string& CARFILE, const std::string& BOATFILENAME) {
    std::string line;
    std::ifstream inFile;

    try {  // try-catch block #1
        if (CHOICE == 8) {
            inFile.open(CARFILE); // Open the CARFILE for reading
            if (!inFile) {
                std::cout << "Failed to open file: " << CARFILE << std::endl; // Error message if file opening failed
                return;
            }
        } else if (CHOICE == 6) {
            inFile.open(BOATFILENAME); // Open the BOATFILENAME for reading
            if (!inFile) {
                std::cout << "Failed to open file: " << BOATFILENAME << std::endl; // Error message if file opening failed
                return;
            }
        } else {
            std::cout << "This is an invalid choice, please try again." << std::endl; // Error message for invalid CHOICE
            return;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred when trying to open the file: " << e.what() << std::endl; // Catch and display exceptions derived from std::exception
    }

    try {  // try-catch block #2
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl; // Print the read data
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred when trying to read from the file: " << e.what() << std::endl; // Catch and display exceptions derived from std::exception
    }

    try {  // try-catch block #3
        inFile.close(); // Close the file after reading
    } catch (const std::exception& e) {
        std::cout << "Exception occurred when trying to close the file: " << e.what() << std::endl; // Catch and display exceptions derived from std::exception
    }
}

// Overload for Transportation
std::ostream& operator<<(std::ostream &os, const Transportation &t){
    os << "Movement: " << t.GETMOVEMENT() << ", Gas Requirement: " << t.GETGASREQUIREMENT() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Transportation &t){
    int movement, gasReq;
    is >> movement >> gasReq;
    t.SETMOVEMENT(movement);
    t.SETGASREQUIREMENT(gasReq);
    return is;
}
// Overload for Car
std::ostream& operator<<(std::ostream &os, const CAR &c){
    os << "MPG: " << c.GETMPG() << ", Cost: " << c.GETCOST() << ", Number of Windows: " << c.GETNUMBEROFWINDOWS() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, CAR &c){
    int mpg, cost, windows;
    is >> mpg >> cost >> windows;
    c.SETMPG(mpg);
    c.SETCOST(cost);
    c.SETNUMBEROFWINDOWS(windows);
    return is;
}
// Overload for BOAT
std::ostream& operator<<(std::ostream &os, const BOAT &b){
    os << "Fuel Efficiency: " << b.GETFUELEFFICIENCY() << ", Number of Propellers: " << b.GETPROPELLERS() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, BOAT &b){
    int efficiency, propellers;
    is >> efficiency >> propellers;
    b.SETFUELEFFICIENCY(efficiency);
    b.SETPROPELLERS(propellers);
    return is;
}

// Overload for Lamborghini
std::ostream& operator<<(std::ostream &os, const Lamborghini &l){
    os << "MPG: " << l.GETMPG() << ", Cost: " << l.GETCOST() << ", Name: " << l.GETNAME() << ", Maintenance: " << l.GETMAINTENANCE() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Lamborghini &l){
    int mpg, cost;
    std::string name, maintenance;
    is >> mpg >> cost >> name >> maintenance;
    l.SETMPG(mpg);
    l.SETCOST(cost);
    l.SETNAME(name);
    l.SETMAINTENANCE(maintenance);
    return is;
}

int main() {
    int CHOICE, VEHICLE_TYPE;
    // Class object instantiations
    BOAT boat;
    CAR car;
    Lamborghini lambo;
    Transportation transp;
    //an instance of the structure 
    COLORSTRUCTURE COLORS; 
    std::string CARFILENAME = "CARFILE.txt", BOATFILENAME = "BOATFILE.txt";

    std::cout << "Welcome to DREW'S TRANSPORTATION PROGRAM!" << std::endl;
    std::cout << "Here you can find out basic information about all different types of transportation" << std::endl;
    std::cout << "Use the program below to learn more and above all.. Have fun!" << std::endl;
    try {
        do {
            std::cout << "\nVehicle Type:\n";
            std::cout << "1. General Transportation\n";
            std::cout << "2. Cars\n";
            std::cout << "3. Boats\n";
            std::cout << "4. Lamborghini\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> VEHICLE_TYPE;

            switch (VEHICLE_TYPE) {
                case 1:
                    do   {
                    try {
                        std::cout << "\nTransportation Menu:\n";
                        std::cout << "1. Get basic information About Transportation\n";
                        std::cout << "2. Get the Movement in Transportation\n";
                        std::cout << "3. Get the Gas Requirement in Transportation\n";
                        std::cout << "4. Set the Movement in Transportation\n";
                        std::cout << "5. Set the Gas Requirement in Transportation\n";
                        std::cout<<"0. Enter zero to go back to the main menu\n"; 
                        std::cin >> CHOICE;
                    } catch (std::exception& e) {
                        std::cerr << "Caught exception in Transportation Menu: " << e.what() << '\n';
                    }
                    switch (CHOICE) {
                        case 1:
                            std::cout << "Basic info about transportation" << std::endl;
                            std::cout << transp << std::endl;
                            break;
                        case 2:
                            std::cout << "Movement: " << transp.GETMOVEMENT() << std::endl;
                            break;
                        case 3:
                            std::cout << "Gas Requirement: " << transp.GETGASREQUIREMENT() << std::endl;
                            break;
                        case 4:
                            std::cout << "Enter the new movement for Transportation: ";
                            int newMovement;
                            std::cin >> newMovement;
                            transp.SETMOVEMENT(newMovement);
                            break;
                        case 5:
                            std::cout << "Enter the new Gas Requirement for Transportation: ";
                            int newGas;
                            std::cin >> newGas;
                            transp.SETGASREQUIREMENT(newGas);
                            break;
                        case 6: 
                             std::cout << "Input transportation details: (movement gasRequirement)\n";
                            std::cin >> transp;
                            break; 
                        default:
                            std::cout << "Invalid choice. Please choose again.\n";
                    }
                 } while(CHOICE !=0);
                    break;
                case 2:
                    //start of the second do while loop 
                     do    {
                         try {
                        std::cout << "\nCars Menu:\n";
                        std::cout << "1. Get basic information About Cars\n";
                        std::cout << "2. Get the MPG of Cars\n";
                        std::cout << "3. Get the Number of Windows in a Car\n";
                        std::cout << "4. Set the MPG in a Car\n";
                        std::cout << "5. Set the Number of Windows in a Car\n";
                        std::cout << "6. Input all the details of the car using the overload operator\n";
                        std::cout << "7. Output all the details of the car using the overload operator\n";
                        std::cout << "8. See a text file on all the classification of cars\n";
                        std::cout << "9. To pick a theoretical color for the car and output it\n";
                        std::cout << "10. You will get and set what you think a car costs(accessor getter)\n";
                        std::cout << "11. Call the inherited virtual function for override cost\n"; 
                        std::cout << "12. (Composition class) Get door status\n";
                        std::cout << "13. (Composition class) Open the door\n";
                        std::cout << "14. (Composition class) Get engine info\n";
                        std::cout << "15. (Composition class) Start the engine\n";
                        std::cout << "16. (Composition class) Get wheel status\n";
                        std::cout << "17. (Composition) Rotate the wheel\n";
                        std::cout << "0. Return to main menu\n";
                        std::cin >> CHOICE;
                    } catch (const std::exception& e) {
                        std::cerr << "Caught exception in Cars Menu: " << e.what() << '\n';
                    }
                try { // 2nd try-catch block
                    switch (CHOICE) {
                        case 1:
                            // 3rd try-catch block
                            try {
                                car.CARINFO();
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting car info: " << e.what() << '\n';
                            }
                            break;
                        case 2:
                            // 4th try-catch block
                            try {
                                std::cout << "MPG: " << car.GETMPG() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting MPG: " << e.what() << '\n';
                            }
                            break;
                        case 3:
                            // 5th try-catch block
                            try {
                                std::cout << "Number of Windows: " << car.GETNUMBEROFWINDOWS() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting number of windows: " << e.what() << '\n';
                            }
                            break;
                        case 4:
                            std::cout << "Enter the new MPG for Car: ";
                            int newMPG;
                            // 6th try-catch block
                            try {
                                std::cin >> newMPG;
                                car.SETMPG(newMPG);
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while setting new MPG: " << e.what() << '\n';
                            }
                            break;
                        case 5:
                            std::cout << "Enter the new number of windows for Car: ";
                            int newWindows;
                            // 7th try-catch block
                            try {
                                std::cin >> newWindows;
                                car.SETNUMBEROFWINDOWS(newWindows);
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while setting new number of windows: " << e.what() << '\n';
                            }
                            break;
                        case 6:
                            // 8th try-catch block
                            try {
                                std::cout << "Enter car details (MPG, cost, number of windows):\n";
                                std::cin >> car;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while entering car details: " << e.what() << '\n';
                            }
                            break;
                        case 7:
                            // 9th try-catch block
                            try {
                                std::cout << "Car details:\n";
                                std::cout << car << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while outputting car details: " << e.what() << '\n';
                            }
                            break;
                        case 8:
                            // 10th try-catch block
                            try {
                                TEXTFILE(CHOICE, CARFILENAME, "");
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while handling text file: " << e.what() << '\n';
                            }
                            break;
                        case 9: 
                            // 11th try-catch block
                            try {
                                car.DISPLAYCOLORS(COLORS);
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while displaying colors: " << e.what() << '\n';
                            }
                            break;
                        case 10:
                            int NEWCOST; 
                            std::cout<<"Enter what you think the car could cost(using a setter method)"<<std::endl;
                            // 12th try-catch block
                            try {
                                std::cin>>NEWCOST;
                                car.SETCOST(NEWCOST);
                                std::cout<<"This is the cost you have assigned(getter(accessor)"<<car.GETCOST()<<std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while setting/getting cost: " << e.what() << '\n';
                            }
                            break; 
                        case 11:
                            // 13th try-catch block
                            try {
                                car.COST1();
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting cost 1: " << e.what() << '\n';
                            }
                            break;
                        case 12:
                            // 14th try-catch block
                            try {
                                std::cout << "Door status: " << car.getDoor().GETDOORSTATUS() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting door status: " << e.what() << '\n';
                            }
                            break;
                        case 13:
                            // 15th try-catch block
                            try {
                                car.getDoor().OPEN();
                                std::cout << "Door opened.\n";
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while opening door: " << e.what() << '\n';
                            }
                            break;
                        case 14:
                            // 16th try-catch block
                            try {
                                std::cout << "Engine info: " << "Cylinders: " << car.getEngine().GETCYLINDERS() 
                                          << ", Displacement: " << car.getEngine().GETDISPLACEMENT() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting engine info: " << e.what() << '\n';
                            }
                            break;
                        case 15:
                            // 17th try-catch block
                            try {
                                car.getEngine().START();
                                std::cout << "Engine started.\n";
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while starting engine: " << e.what() << '\n';
                            }
                            break;
                        case 16:
                            // 18th try-catch block
                            try {
                                std::cout << "Wheel status: " << car.getWheel().GETDIRECTION() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while getting wheel status: " << e.what() << '\n';
                            }
                            break;
                        case 17:
                            // 19th try-catch block
                            try {
                                car.getWheel().ROTATE();
                                std::cout << "Wheel rotated.\n";
                            } catch (const std::exception& e) {
                                std::cerr << "Caught exception while rotating wheel: " << e.what() << '\n';
                            }
                            break;
                        default:
                            std::cout << "Invalid choice. Please choose again.\n";
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Caught exception in Cars Menu: " << e.what() << '\n';
                }

                  }  while(CHOICE !=0); // end of the given do while loop
                    break;
                case 3:
                    // start of the do while loop
                    do   {
                    try {
                        std::cout << "\nBoats Menu:\n";
                        std::cout << "1. Get basic information About Boats\n";
                        std::cout << "2. Get the Fuel Efficiency of a Boat\n";
                        std::cout << "3. Get the Number of Propellers in a Boat\n";
                        std::cout << "4. Set the Fuel Efficiency in a Boat\n";
                        std::cout << "5. Set the Number of Propellers in a Boat\n";
                        std::cout << "6. See a text file on all the classification of boats\n";
                        std::cout<<"7. See the Average Cost for a Boat"<<std::endl; 
                        std::cout<<"8. Pick a value for the color of the boat and display it"<<std::endl; 
                        std::cout<<"9. Output the cost value virtual function 2 inherited override"<<std::endl; 
                        std::cout<<"0. To return to the main menu"<<std::endl; 
                        std::cin >> CHOICE;
                    } catch (const std::exception& e) {
                        std::cerr << "Caught exception in Boats Menu: " << e.what() << '\n';
                    }
                    switch (CHOICE) {
                        case 1:
                            //outputs basic information about the boat
                            boat.BOATINFO(); 
                            std::cout << boat << std::endl;
                            break;
                        case 2:
                            std::cout << "Fuel Efficiency: " << boat.GETFUELEFFICIENCY() << std::endl;
                            break;
                        case 3:
                            std::cout << "Number of Propellers: " << boat.GETPROPELLERS() << std::endl;
                            break;
                        case 4:
                            std::cout << "Enter the new fuel efficiency for Boat: ";
                            int newEfficiency;
                            std::cin >> newEfficiency;
                            boat.SETFUELEFFICIENCY(newEfficiency);
                            break;
                        case 5:
                            std::cout << "Enter the new number of propellers for Boat: ";
                            int newPropellers;
                            std::cin >> newPropellers;
                            boat.SETPROPELLERS(newPropellers);
                            break;
                        case 6:
                            TEXTFILE(CHOICE, "", BOATFILENAME);
                            break;
                        case 7:
                            std::cout<<"This is the average cost range of a cost"<<boat.GETAVERAGECOST()<<std::endl; 
                        case 8:  
                            //output the general logic for picking a color and outputting it accordingly
                            boat.DISPLAYCOLORS(COLORS); 
                            break;
                        case 9:
                            boat.COST1(); 
                            break; 
                        default:
                            std::cout << "Invalid choice. Please choose again.\n";
                    }
                  }  while(CHOICE !=0); // end of do while loop 
                    break;
                 case 4:
                    do {
                        try {
                            std::cout << "\nLamborghini Menu:\n";
                            std::cout << "1. Get basic information About Lamborghini\n";
                            std::cout << "2. Get the MPG of a Lamborghini\n";
                            std::cout << "3. Set the MPG of the Lambo accordingly\n";
                            std::cout << "4. Set the new name for the lambo\n";
                            std::cout << "5. Get the Name of a Lamborghini\n";
                            std::cout <<"6. If you want to buy the lambo\n";
                            std::cout<<"7. Set the values of the Lambo Object\n";
                            std::cout<<"8. Output the values with the overload operator\n"; 
                            std::cout << "0. Return to main menu\n";
                            std::cin >> CHOICE;
                        } catch (const std::exception& e) {
                            std::cerr << "Caught exception in Lamborghini Menu: " << e.what() << '\n';
                            break;
                        }
                         std::string NEWNAME;
                        switch (CHOICE) {
                            case 1:
                                //outputs general information about the type oof lambos
                                lambo.LAMBOINFO();
                                break;
                                
                            case 2:
                                //GETS THE MPG VALUES OF THE LAMBO YOU ASSIGNED
                                std::cout<<"This outputs the getter values of what you assigned for the lambo"<<std::endl;
                               std::cout << "MPG: " << lambo.GETMPG() << std::endl;
                                break;
                            case 3:
                                int NEWGAS;
                             std::cout<<"Enter a new gas requirement for the Lambo"<<std::endl;
                              std::cin >> NEWGAS;
                                lambo.SETMPG(NEWGAS); 
                                break;
                            case 4:
                             std::cout<<"Enter a new name value for the Lambo"<<std::endl;
                            std::cin >> NEWNAME;
                                lambo.SETNAME(NEWNAME);
                                break;
                            case 5:
                                std::cout<<"This is the new name you assigned:"<<lambo.GETNAME()<<std::endl; 
                                break;
                            case 6:
                                //buys an actual lambo possibly
                                lambo.BUY(COLORS); 
                                break;                                         
                            case 7:
                                 std::cout << "Enter lambo details (MPG, cost, number of windows using overload >>):\n";
                              std::cin >> lambo;
                                break; 
                            case 8:
                      std::cout<<"This now outputs the value of the lambo accordingly as an object(overload << operator"<<std::endl; 
                      std::cout<<lambo<<std::endl; 
                                break; 
                            
                            default:
                                if (CHOICE != 0) std::cout << "Invalid choice. Please choose again.\n";
                        }
                    } while (CHOICE != 0);
                    break;
                case 0:
                    std::cout << "Exiting... Thanks for using DREW'S TRANSPORTATION PROGRAM!";
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again.\n";
            }
        } while (VEHICLE_TYPE != 0);
    } catch (std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Caught unexpected exception\n";
    }
    return 0;
}


