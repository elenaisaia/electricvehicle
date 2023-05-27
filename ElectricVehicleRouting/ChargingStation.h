#ifndef ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_CHARGINGSTATION_H


#include <cstddef>
#include "ChargerType.h"

class ChargingStation {
public:
    ChargingStation(unsigned int id, int x, int y, double chargingTime, ChargerType chargerType);

    ChargingStation() = default;

    unsigned int getId() const;

    int getX() const;

    int getY() const;

    double getCharhingTime() const;

    ChargerType getChargerType() const;

    bool operator==(const ChargingStation &rhs) const;

    bool operator!=(const ChargingStation &rhs) const;

private:
    unsigned int id;
    int x;
    int y;
    double charhingTime;
    ChargerType chargerType;
};


#endif //ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
