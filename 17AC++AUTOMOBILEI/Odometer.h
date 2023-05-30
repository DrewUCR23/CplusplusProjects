#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer {
public:
    Odometer(FuelGauge &gauge);

    void KNOWCARMILES();
    void REPORTCARMILES();
    void INCREMENTCARMILES();
    void DECREASECARMILES(int decrease);
    void carStatus(int USERINPUT);

private:
    int CARMILES;
    int NEWCARMILES;
    bool CARON;
    FuelGauge &fuelGauge;
};

#endif /* ODOMETER_H */

