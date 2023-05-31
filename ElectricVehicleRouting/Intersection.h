#ifndef ELECTRICVEHICLEROUTING_INTERSECTION_H
#define ELECTRICVEHICLEROUTING_INTERSECTION_H


class Intersection {
public:
    Intersection(unsigned int id, int x, int y);

    Intersection() = default;

    unsigned int getId() const;

    int getX() const;

    int getY() const;

private:
    unsigned int id;
    int x;
    int y;
};


#endif //ELECTRICVEHICLEROUTING_INTERSECTION_H
