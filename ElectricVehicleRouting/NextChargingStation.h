#ifndef ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H


#include "ChargingStation.h"

class NextChargingStation {
public:
    NextChargingStation(ChargingStation chargingStation, unsigned int maxSpeed, unsigned int avgSpeed, int x, int y);

    NextChargingStation(ChargingStation chargingStation, double distance, unsigned int maxSpeed, unsigned int avgSpeed,
                        unsigned int time);

    bool operator<(const NextChargingStation &rhs) const;

    bool operator>(const NextChargingStation &rhs) const;

    bool operator<=(const NextChargingStation &rhs) const;

    bool operator>=(const NextChargingStation &rhs) const;

    ChargingStation getChargingStation() const;

    double getDistance() const;

    unsigned int getMaxSpeed() const;

    unsigned int getAvgSpeed() const;

    unsigned int getTime() const;

private:
    ChargingStation chargingStation;
    double distance;
    unsigned int maxSpeed;
    unsigned int avgSpeed;
    unsigned int time;

    static double euclidean_distance(int x, int y, unsigned int x1, unsigned int y1);
    static double fRand(double fMin, double fMax);
};


#endif //ELECTRICVEHICLEROUTING_NEXTCHARGINGSTATION_H
