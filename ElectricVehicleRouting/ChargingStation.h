#ifndef ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
#define ELECTRICVEHICLEROUTING_CHARGINGSTATION_H


class ChargingStation {
public:
    ChargingStation(unsigned int id, unsigned int x, unsigned int y);

    unsigned int getId() const;

    unsigned int getX() const;

    void setX(unsigned int x);

    unsigned int getY() const;

    void setY(unsigned int y);

private:
    unsigned int id;
    unsigned int x;
    unsigned int y;
};


#endif //ELECTRICVEHICLEROUTING_CHARGINGSTATION_H
