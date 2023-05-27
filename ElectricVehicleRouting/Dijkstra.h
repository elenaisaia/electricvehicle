#ifndef ELECTRICVEHICLEROUTING_DIJKSTRA_H
#define ELECTRICVEHICLEROUTING_DIJKSTRA_H


#include <queue>
#include "DirectedGraph.h"
#include "ElectricVehicle.h"

class Dijkstra {
public:
    Dijkstra(const ElectricVehicle &vehicle, const DirectedGraph &graph, unsigned int sourceId, unsigned int destinationId);

    double findCost();

private:
    ElectricVehicle vehicle;
    DirectedGraph graph;
    unsigned int sourceId;
    unsigned int destinationId;
    std::priority_queue<NextChargingStation> queue;
    std::unordered_map<unsigned int, double> cost;
    std::unordered_map<unsigned int, unsigned int> parinte;
    std::unordered_map<unsigned int, bool> visited;
};


#endif //ELECTRICVEHICLEROUTING_DIJKSTRA_H
