#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

template <typename T>
class Engine {
private:
    T cylinders;
    T displacement;
public:

    Engine() : cylinders(T()), displacement(T()) {}

    // Parameterized constructor
    Engine(T cylinders, T displacement) : cylinders(cylinders), displacement(displacement) {}

    //ACCESSOR 
//template class functions that will be used for the engine type}

    T GETCYLINDERS() const {
        return cylinders;
    }

    T GETDISPLACEMENT() const {
        return displacement;
    }

    //MUTATOR 

    void SETCYLINDERS(T CYLINDERS) {
        this->cylinders = CYLINDERS;
    }

    void SETDISPLACEMENT(T DISPLACEMENT) {
        this->displacement = DISPLACEMENT;
    }

    //function method that can turn the car on

    void START() {
        std::string answer;
        std::cout<<"Would you like to start the engine (YES) or (NO)?"<<std::endl;
        std::cin>>answer;
        if (answer == "YES") {
            std::cout << "Engine started." << std::endl;
        } else {
            std::cout << "Engine not started." << std::endl;
        }
    }
};

   // Class Door
class Door {
private:
    std::string doorStatus; 
public:
    Door() : doorStatus("closed") {}

    std::string GETDOORSTATUS() const { return this->doorStatus; }
    void SETDOORSTATUS(std::string status) { this->doorStatus = status; }

    void OPEN() {
        this->doorStatus = "open";
        std::cout << "Door is now open." << std::endl;
    }
};

//third component for the CC
class Wheel {
private: 
    std::string direction;
public:
    Wheel() : direction("straight") {}

    std::string GETDIRECTION() const { return this->direction; }
    void SETDIRECTION(std::string direction) { this->direction = direction; }

    void ROTATE() {
        std::cout<<"What way do you want to rotate the wheel? (Left-Right)"<<std::endl;
        std::cin >> this->direction;
        std::cout << "Wheel is now pointing " << this->direction << "." << std::endl;
    }
};


struct COLORSTRUCTURE {
    std::map<int, std::string> COLORMAP{
        {1, "Red"},
        {2, "Blue"},
        {3, "Green"},
        {4, "Yellow"},
        {5, "Purple"},
        {6, "Orange"},
        {7, "Pink"},
        {8, "Cyan"},
        {9, "Magenta"},
        {10, "Brown"}
    };

    std::string getColor(int number) {
        auto it = COLORMAP.find(number);
        if (it != COLORMAP.end()) {
            return it->second;
        } else {
            return "Unknown";
        }
    }
};

extern COLORSTRUCTURE COLORS; 
class Transportation {
private:
    //movement value to be inherited
    int MOVEMENT;
    //GASREQUIREMENT that will be inherited
    int GASREQUIREMENT;
public:
    Transportation() : MOVEMENT(0), GASREQUIREMENT(0) {}
    Transportation(const Transportation& orig) : MOVEMENT(orig.MOVEMENT), GASREQUIREMENT(orig.GASREQUIREMENT) {}
    virtual ~Transportation() {}

    //accessor
    int GETMOVEMENT() const;
    int GETGASREQUIREMENT() const;

    //mutator
    void SETMOVEMENT(int value);
    void SETGASREQUIREMENT(int value);

    //virtual functions here 
    virtual void DISPLAYCOLORS(COLORSTRUCTURE& REF);
    virtual void COST1();

    // Overloaded operators
    //friend std::ostream& operator<<(std::ostream &os, const Transportation &t);
    friend std::istream& operator>>(std::istream &is, Transportation &t);
    //definition for outputting the qualities of the overload operator 

    friend std::ostream& operator<<(std::ostream &os, const Transportation &t);
};
    // CHILD CLASS 1
    class CAR : public Transportation {
    private:
        //composition class goes here 
        Door DOOR;
        Engine<int> ENGINE;  // Specify a type for the template
        Wheel WHEEL;
        int MPG, NUMBEROFWINDOWS,NEWCOST;

    public:
        
       void setDoor(const Door& door);  
    Door getDoor() const;

    // For Engine
    void setEngine(const Engine<int>& engine);
    Engine<int> getEngine() const;

    // For Wheel
    void setWheel(const Wheel& wheel);
    Wheel getWheel() const;
        void CARINFO(); 
        //accessor
        int GETMPG() const;
        int GETNUMBEROFWINDOWS() const;
        int GETCOST() const; 
        //mutator
        void SETMPG(int value);
       void SETNUMBEROFWINDOWS(int value); 
        //override for the virtual class 
        void DISPLAYCOLORS(COLORSTRUCTURE& REF) override;
        void SETCOST (int value); 
        void COST1() override;
         // Overloaded operators
            friend std::ostream& operator<<(std::ostream &os, const CAR &c);
            friend std::istream& operator>>(std::istream &is, CAR &c);
    };
// CHILD CLASS 2
class BOAT : public Transportation {
private:
      int SPEED, AVERAGECOST, FUELEFFICIENCY, NUMBEROFPROPELLERS;  // Added FUELEFFICIENCY and NUMBEROFPROPELLERS
    std::string TYPICALMAINTENANCE;

public:
    
    //general function that gives info on boat
    void BOATINFO(); 
    //accessor
    int GETSPEED() const;
    int GETAVERAGECOST() const; 
    int GETPROPELLERS() const; 
    int GETFUELEFFICIENCY() const; 
    std::string GETTYPICALMAINTENANCE() const; 

    //mutator
    void SETSPEED(int value); 
    void SETAVERAGECOST(int value); 
    void SETPROPELLERS(int value); 
    void SETFUELEFFICIENCY(int value); 
    void SETTYPICALMAINTENANCE(const std::string& value);
        
    //override virtual functions goes here 
    void DISPLAYCOLORS(COLORSTRUCTURE& REF);
    void COST1 () override;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream &os, const BOAT &c);
    friend std::istream& operator>>(std::istream &is, BOAT &c);
};

class Lamborghini : public CAR {
private:
    int  MPG, COST_VALUE;  
    std::string NAME;
    std::string MAINTENANCE ;  

public:
    // ACCESSOR 
    int GETMPG() const;
    int GETCOST() const;
    std::string GETNAME() const;
    std::string GETMAINTENANCE() const;

    //mutator
    void SETMPG(int value);
    void SETCOST(int value);
    void SETNAME(const std::string& value);
    void SETMAINTENANCE(const std::string& value);

    //overriding of the virtual function 
    void DISPLAYCOLORS(COLORSTRUCTURE& REF) override;
    void COST1 () override;
    //few extra methods 
    void LAMBOINFO();
    void LAMBOMENU(std::string model);
    void BUY(COLORSTRUCTURE& REF); 
void PrintPurchaseDetails(const std::string& model, int CYLINDERS, const std::string& displacementText, const std::string& chosenColor);

};

#endif /* TRANSPORTATION_H */