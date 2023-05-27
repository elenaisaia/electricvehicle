#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(unsigned int id, ChargerType chargerType, unsigned int batteryPercentage) : id(id), chargerType(chargerType), batteryPercentage(batteryPercentage) {}

unsigned int ElectricVehicle::getId() const {
    return id;
}

ChargerType ElectricVehicle::getChargerType() const {
    return chargerType;
}

unsigned int ElectricVehicle::getBatteryPercentage() const {
    return batteryPercentage;
}

const std::vector<SpeedCost> &ElectricVehicle::getCosts() const {
    return costs;
}

void ElectricVehicle::setBatteryPercentage(unsigned int batteryPercentage) {
    ElectricVehicle::batteryPercentage = batteryPercentage;
}

void ElectricVehicle::setCosts(const std::vector<SpeedCost> &costs) {
    ElectricVehicle::costs = costs;
}
