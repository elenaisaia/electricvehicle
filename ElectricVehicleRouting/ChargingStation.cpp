#include "ChargingStation.h"

ChargingStation::ChargingStation(unsigned int id, int x, int y, double chargingTime, ChargerType chargerType) : id(id), x(x), y(y), charhingTime(chargingTime), chargerType(chargerType) {}

unsigned int ChargingStation::getId() const {
    return id;
}

int ChargingStation::getX() const {
    return x;
}

int ChargingStation::getY() const {
    return y;
}

double ChargingStation::getCharhingTime() const {
    return charhingTime;
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
