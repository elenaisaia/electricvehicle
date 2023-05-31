#ifndef ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORINTERSECTIONS_H
#define ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORINTERSECTIONS_H

#include <unordered_map>
#include "ChargingStation.h"
#include "Intersection.h"

struct NextNode {
    double distance, speed;
    unsigned int nextId;

    bool operator<(const NextNode &rhs) const;

    bool operator>(const NextNode &rhs) const;

    bool operator<=(const NextNode &rhs) const;

    bool operator>=(const NextNode &rhs) const;
};

class DirectedGraphForIntersections {
public:
    DirectedGraphForIntersections(unsigned int vertexes);

    unsigned int getVertexes() const;

    unsigned int getArches() const;

    const std::unordered_map<unsigned int, std::vector<NextNode>> &getAdjacencyList() const;

    const std::unordered_map<unsigned int, ChargingStation> &getChargingStationList() const;

    const std::unordered_map<unsigned int, Intersection> &getIntersectionList() const;

    void addChargingStationToChargingStationList(const ChargingStation& chargingStation);

    void addIntersectionToIntersectionList(const Intersection& intersection);

    void addToAdjacencyList(unsigned int sourceId, unsigned int destinationId, double distance, double speed);

    std::vector<NextNode> getAdjacentNodes(unsigned int id);

private:
    unsigned int vertexes;
    unsigned int arches;
    std::unordered_map<unsigned int, std::vector<NextNode> > adjacencyList;
    std::unordered_map<unsigned int, ChargingStation> chargingStationList;
    std::unordered_map<unsigned int, Intersection> intersectionList;
};


#endif //ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORINTERSECTIONS_H
