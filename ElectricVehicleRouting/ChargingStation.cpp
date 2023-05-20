#include "ChargingStation.h"

ChargingStation::ChargingStation(unsigned int id, unsigned int x, unsigned int y) : id(id), x(x), y(y) {}

unsigned int ChargingStation::getId() const {
    return id;
}

unsigned int ChargingStation::getX() const {
    return x;
}

void ChargingStation::setX(unsigned int x) {
    ChargingStation::x = x;
}

unsigned int ChargingStation::getY() const {
    return y;
}

void ChargingStation::setY(unsigned int y) {
    ChargingStation::y = y;
}
