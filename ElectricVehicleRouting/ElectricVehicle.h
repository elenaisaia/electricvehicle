#ifndef ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
#define ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H

#include <vector>
#include "ChargerType.h"

struct SpeedCost {
    unsigned int minSpeed;
    unsigned int maxSpeed;
    double costPerTimeUnit;
};

class ElectricVehicle {
public:
    ElectricVehicle(unsigned int id, ChargerType chargerType, unsigned int batteryPercentage, double onePercentChargingTime);

    unsigned int getId() const;

    ChargerType getChargerType() const;

    unsigned int getBatteryPercentage() const;

    double getOnePercentChargingTime() const;

    const std::vector<SpeedCost> &getCosts() const;

    void setBatteryPercentage(unsigned int batteryPercentage);

    void addCost(unsigned int minSpeed, unsigned int maxSpeed, double costPerTimeUnit);

    double getCostPerTimeUnit(unsigned int speed);

private:
    unsigned int id;
    unsigned int batteryPercentage;
    double onePercentChargingTime;
    ChargerType chargerType;
    std::vector<SpeedCost> costs;
};


#endif //ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
