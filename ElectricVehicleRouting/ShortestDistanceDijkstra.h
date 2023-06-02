#ifndef ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H
#define ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H

#include <queue>
#include "DirectedGraphForIntersections.h"
#include "NextChargingStation.h"

class ShortestDistanceDijkstra {
public:
    ShortestDistanceDijkstra(DirectedGraphForIntersections &graph);

    std::vector<NextChargingStation> getNextChargingStationsForChargingStation(unsigned int id);

private:
    DirectedGraphForIntersections &graph;
    std::priority_queue<NextNode> queue;
    std::unordered_map<unsigned int, NextNode> cost;
    std::unordered_map<unsigned int, bool> visited;

    void findDistances(unsigned int sourceId);
};


#endif //ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H
