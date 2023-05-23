#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(unsigned int id, unsigned int batteryPercentage) : id(id), batteryPercentage(
        batteryPercentage) {}

unsigned int ElectricVehicle::getId() const {
    return id;
}

unsigned int ElectricVehicle::getBatteryPercentage() const {
    return batteryPercentage;
}

const std::vector<Cost> &ElectricVehicle::getCosts() const {
    return costs;
}

void ElectricVehicle::setBatteryPercentage(unsigned int batteryPercentage) {
    ElectricVehicle::batteryPercentage = batteryPercentage;
}

void ElectricVehicle::setCosts(const std::vector<Cost> &costs) {
    ElectricVehicle::costs = costs;
}
