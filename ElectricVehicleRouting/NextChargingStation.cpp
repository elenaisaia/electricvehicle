//
// Created by elena on 18-May-23.
//

#include <cmath>
#include "NextChargingStation.h"

NextChargingStation::NextChargingStation(ChargingStation chargingStation, unsigned int maxSpeed,
                                         unsigned int avgSpeed, int x, int y) : chargingStation(chargingStation), maxSpeed(maxSpeed),
                                                                  avgSpeed(avgSpeed) {
    this->distance = euclidean_distance(x, y, chargingStation.getX(), chargingStation.getY()) * fRand(1, sqrt(2));
    this->time = this->distance / this->avgSpeed;
}

double NextChargingStation::euclidean_distance(int x, int y, unsigned int x1, unsigned int y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

double NextChargingStation::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool NextChargingStation::operator<(const NextChargingStation &rhs) const {
    if (chargingStation.getCharhingTime() + time < rhs.chargingStation.getCharhingTime() + rhs.getTime())
        return true;
    if (rhs.chargingStation.getCharhingTime() + rhs.getTime() < chargingStation.getCharhingTime() + time )
        return false;
    if (time < rhs.getTime())
        return true;
    if (rhs.getTime() < time)
        return false;
    if (chargingStation.getCharhingTime() < rhs.chargingStation.getCharhingTime())
        return true;
    if (rhs.chargingStation.getCharhingTime() < chargingStation.getCharhingTime())
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

unsigned int NextChargingStation::getTime() const {
    return time;
}

NextChargingStation::NextChargingStation(ChargingStation chargingStation, double distance, unsigned int maxSpeed,
                                         unsigned int avgSpeed, unsigned int time) : chargingStation(chargingStation),
                                                                                     distance(distance),
                                                                                     maxSpeed(maxSpeed),
                                                                                     avgSpeed(avgSpeed), time(time) {}
