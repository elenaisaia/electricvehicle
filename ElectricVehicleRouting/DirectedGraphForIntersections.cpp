#include "DirectedGraphForIntersections.h"

DirectedGraphForIntersections::DirectedGraphForIntersections(unsigned int vertexes) : vertexes(vertexes) {}

unsigned int DirectedGraphForIntersections::getVertexes() const {
    return vertexes;
}

unsigned int DirectedGraphForIntersections::getArches() const {
    return arches;
}

const std::unordered_map<unsigned int, std::vector<NextNode>> &DirectedGraphForIntersections::getAdjacencyList() const {
    return adjacencyList;
}

const std::unordered_map<unsigned int, ChargingStation> &DirectedGraphForIntersections::getChargingStationList() const {
    return chargingStationList;
}

const std::unordered_map<unsigned int, Intersection> &DirectedGraphForIntersections::getIntersectionList() const {
    return intersectionList;
}

void DirectedGraphForIntersections::addChargingStationToChargingStationList(const ChargingStation& chargingStation) {
    chargingStationList[chargingStation.getId()] = chargingStation;
}

void DirectedGraphForIntersections::addIntersectionToIntersectionList(const Intersection& intersection) {
    intersectionList[intersection.getId()] = intersection;
}

void
DirectedGraphForIntersections::addToAdjacencyList(unsigned int sourceId, unsigned int destinationId, double distance,
                                                  double speed) {
    adjacencyList[sourceId].push_back(NextNode{distance, speed, destinationId});
}

std::vector<NextNode> DirectedGraphForIntersections::getAdjacentNodes(unsigned int id) {
    return adjacencyList[id];
}

bool NextNode::operator<(const NextNode &rhs) const {
    if (distance < rhs.distance)
        return true;
    if (rhs.distance < distance)
        return false;
    if (speed > rhs.speed)
        return true;
    if (rhs.speed > speed)
        return false;
    return nextId < rhs.nextId;
}

bool NextNode::operator>(const NextNode &rhs) const {
    return rhs < *this;
}

bool NextNode::operator<=(const NextNode &rhs) const {
    return !(rhs < *this);
}

bool NextNode::operator>=(const NextNode &rhs) const {
    return !(*this < rhs);
}
