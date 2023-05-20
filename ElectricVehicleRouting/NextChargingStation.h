#ifndef ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H


#include "ChargingStation.h"

class NextChargingStation {
public:
    NextChargingStation(ChargingStation &chargingStation, unsigned int maxSpeed, unsigned int avgSpeed, int x, int y);

private:
    ChargingStation &chargingStation;
    double distance;
    unsigned int maxSpeed;
    unsigned int avgSpeed;
    unsigned int time;

    static double euclidean_distance(int x, int y, unsigned int x1, unsigned int y1);
};


#endif //ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H
