#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <string> 

class FuelGauge {
public:
    void knowGas();
    void checkGas();
    void incrementGas(int GASQUANTITY,int GASTYPE);
    void decrementGas();
    int getFuel();
    void checkFullTankCost();
    FuelGauge();
   
private:
    int fuel;
    int fuel2;
    std::string otherthing;
};
#endif /* FuelGauge.h */
