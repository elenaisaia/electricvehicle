//
// Created by elena on 18-May-23.
//

#include <cmath>
#include "NextChargingStation.h"

NextChargingStation::NextChargingStation(ChargingStation chargingStation, double distance, unsigned int maxSpeed,
                                         unsigned int avgSpeed, double time) : chargingStation(chargingStation),
                                                                                     distance(distance),
                                                                                     maxSpeed(maxSpeed),
                                                                                     avgSpeed(avgSpeed), time(time) {}

NextChargingStation NextChargingStation::createFromCoordinates(ChargingStation chargingStation, unsigned int maxSpeed, unsigned int avgSpeed, int x, int y) {
    double distance = euclidean_distance(x, y, chargingStation.getX(), chargingStation.getY()) * fRand(1, sqrt(2));
    double time = distance / avgSpeed;
    return NextChargingStation{chargingStation, distance, maxSpeed, avgSpeed, time};
}

double NextChargingStation::euclidean_distance(int x, int y, unsigned int x1, unsigned int y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

double NextChargingStation::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool NextChargingStation::operator<(const NextChargingStation &rhs) const {
    if (chargingStation.getOnePercentCharhingTime() + time < rhs.chargingStation.getOnePercentCharhingTime() + rhs.getTime())
        return true;
    if (rhs.chargingStation.getOnePercentCharhingTime() + rhs.getTime() < chargingStation.getOnePercentCharhingTime() + time )
        return false;
    if (time < rhs.getTime())
        return true;
    if (rhs.getTime() < time)
        return false;
    if (chargingStation.getOnePercentCharhingTime() < rhs.chargingStation.getOnePercentCharhingTime())
        return true;
    if (rhs.chargingStation.getOnePercentCharhingTime() < chargingStation.getOnePercentCharhingTime())
        return false;
    return distance < rhs.getDistance();
}

bool NextChargingStation::operator>(const NextChargingStation &rhs) const {
    return rhs < *this;
}

bool NextChargingStation::operator<=(const NextChargingStation &rhs) const {
    return !(rhs < *this);
}

bool NextChargingStation::operator>=(const NextChargingStation &rhs) const {
    return !(*this < rhs);
}

ChargingStation NextChargingStation::getChargingStation() const {
    return chargingStation;
}

double NextChargingStation::getDistance() const {
    return distance;
}

unsigned int NextChargingStation::getMaxSpeed() const {
    return maxSpeed;
}

unsigned int NextChargingStation::getAvgSpeed() const {
    return avgSpeed;
}

double NextChargingStation::getTime() const {
    return time;
}
