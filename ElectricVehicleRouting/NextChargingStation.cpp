//
// Created by elena on 18-May-23.
//

#include <cmath>
#include "NextChargingStation.h"

NextChargingStation::NextChargingStation(ChargingStation &chargingStation, unsigned int maxSpeed,
                                         unsigned int avgSpeed, int x, int y) : chargingStation(chargingStation), maxSpeed(maxSpeed),
                                                                  avgSpeed(avgSpeed) {
    this->distance = euclidean_distance(x, y, chargingStation.getX(), chargingStation.getY());
    this->time = this->distance / this->avgSpeed;
}

double NextChargingStation::euclidean_distance(int x, int y, unsigned int x1, unsigned int y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
