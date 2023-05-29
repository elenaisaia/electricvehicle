#include "ChargingStation.h"

ChargingStation::ChargingStation(unsigned int id, int x, int y, double onePercentChargingTime, ChargerType chargerType) : id(id), x(x), y(y), onePercentCharhingTime(onePercentChargingTime), chargerType(chargerType) {}

unsigned int ChargingStation::getId() const {
    return id;
}

int ChargingStation::getX() const {
    return x;
}

int ChargingStation::getY() const {
    return y;
}

double ChargingStation::getOnePercentCharhingTime() const {
    return onePercentCharhingTime;
}

ChargerType ChargingStation::getChargerType() const {
    return chargerType;
}

bool ChargingStation::operator==(const ChargingStation &rhs) const {
    return id == rhs.id;
}

bool ChargingStation::operator!=(const ChargingStation &rhs) const {
    return !(rhs == *this);
}
