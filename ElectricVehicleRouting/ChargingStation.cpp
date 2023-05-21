#include "ChargingStation.h"

ChargingStation::ChargingStation(unsigned int id, int x, int y,unsigned int chargingTime) : id(id), x(x), y(y), charhingTime(chargingTime) {}

unsigned int ChargingStation::getId() const {
    return id;
}

int ChargingStation::getX() const {
    return x;
}

void ChargingStation::setX(int x) {
    ChargingStation::x = x;
}

int ChargingStation::getY() const {
    return y;
}

void ChargingStation::setY(int y) {
    ChargingStation::y = y;
}

unsigned int ChargingStation::getCharhingTime() const {
    return charhingTime;
}

void ChargingStation::setCharhingTime(unsigned int charhingTime) {
    ChargingStation::charhingTime = charhingTime;
}

bool ChargingStation::operator==(const ChargingStation &rhs) const {
    return id == rhs.id;
}

bool ChargingStation::operator!=(const ChargingStation &rhs) const {
    return !(rhs == *this);
}
