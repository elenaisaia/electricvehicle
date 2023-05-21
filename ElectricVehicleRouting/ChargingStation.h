#ifndef ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_CHARGINGSTATION_H


#include <cstddef>

class ChargingStation {
public:
    ChargingStation(unsigned int id, int x, int y, unsigned int chargingTime);

    ChargingStation() = default;

    unsigned int getId() const;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    unsigned int getCharhingTime() const;

    void setCharhingTime(unsigned int charhingTime);

    bool operator==(const ChargingStation &rhs) const;

    bool operator!=(const ChargingStation &rhs) const;

private:
    unsigned int id;
    int x;
    int y;
    unsigned int charhingTime;
};


#endif //ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
