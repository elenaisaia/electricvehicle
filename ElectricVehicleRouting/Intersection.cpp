#include "Intersection.h"

Intersection::Intersection(unsigned int id, int x, int y) : id(id), x(x), y(y) {}

unsigned int Intersection::getId() const {
    return id;
}

int Intersection::getX() const {
    return x;
}

int Intersection::getY() const {
    return y;
}
