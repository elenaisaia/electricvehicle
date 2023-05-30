#ifndef ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_CHARGINGSTATION_H


#include <cstddef>
#include <vector>
#include <algorithm>
#include "ChargerType.h"

class ChargingStation {
public:
    ChargingStation(unsigned int id, int x, int y, double onePercentChargingTime);

    ChargingStation() = default;

    unsigned int getId() const;

    int getX() const;

    int getY() const;

    double getOnePercentCharhingTime() const;

    bool hasChargerType(ChargerType chargerType);

    void addChargerType(ChargerType chargerType);

    bool operator==(const ChargingStation &rhs) const;

    bool operator!=(const ChargingStation &rhs) const;

private:
    unsigned int id;
    int x;
    int y;
    double onePercentCharhingTime;
    std::vector<ChargerType> chargerTypes;
};


#endif //ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
