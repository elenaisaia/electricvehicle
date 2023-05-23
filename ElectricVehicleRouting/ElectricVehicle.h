#ifndef ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
#define ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H

#include <vector>

struct Cost {
    unsigned int minSpeed;
    unsigned int maxSpeed;
    unsigned int costPerTimeUnit;
};

class ElectricVehicle {
public:
    ElectricVehicle(unsigned int id, unsigned int batteryPercentage);

    unsigned int getId() const;

    unsigned int getBatteryPercentage() const;

    const std::vector<Cost> &getCosts() const;

    void setBatteryPercentage(unsigned int batteryPercentage);

    void setCosts(const std::vector<Cost> &costs);

private:
    unsigned int id;
    unsigned int batteryPercentage;
    std::vector<Cost> costs;
};


#endif //ELECTRICVEHICLEROUTING_ELECTRICVEHICLE_H
