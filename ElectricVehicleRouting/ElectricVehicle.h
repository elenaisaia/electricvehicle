#ifndef ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
#define ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H

#include <vector>
#include "ChargerType.h"

struct SpeedCost {
    unsigned int minSpeed;
    unsigned int maxSpeed;
    unsigned int costPerTimeUnit;
};

class ElectricVehicle {
public:
    ElectricVehicle(unsigned int id, ChargerType chargerType, unsigned int batteryPercentage);

    unsigned int getId() const;

    ChargerType getChargerType() const;

    unsigned int getBatteryPercentage() const;

    const std::vector<SpeedCost> &getCosts() const;

    void setBatteryPercentage(unsigned int batteryPercentage);

    void setCosts(const std::vector<SpeedCost> &costs);

private:
    unsigned int id;
    unsigned int batteryPercentage;
    ChargerType chargerType;
    std::vector<SpeedCost> costs;
};


#endif //ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
