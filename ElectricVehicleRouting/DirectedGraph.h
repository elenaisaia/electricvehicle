#ifndef ELECTRICVEHICLEROUTING_DIRECTEDGRAPH_H
#define ELECTRICVEHICLEROUTING_DIRECTEDGRAPH_H

#include <vector>
#include <unordered_map>
#include "NextChargingStation.h"


namespace std {
    template<>
    struct hash<ChargingStation> {
        auto operator()(const ChargingStation &chargingStation) const -> size_t {
            return hash<unsigned int>()(chargingStation.getId());
        }
    };
}

class DirectedGraph {
public:
    DirectedGraph(int vertexes, int arches);

    int getVertexes() const;

    int getArches() const;

    std::unordered_map<ChargingStation, std::vector<NextChargingStation>> getAdjacencyList() const;

    void addNextChargingStation(ChargingStation chargingStation, NextChargingStation nextChargingStation);

    std::vector<NextChargingStation> getAdjacentStations(ChargingStation chargingStation);

    DirectedGraph getTransposedGraph();

private:
    int vertexes;
    int arches;
    std::unordered_map<ChargingStation, std::vector<NextChargingStation> > adjacencyList;
};


#endif //ELECTRICVEHICLEROUTING_DIRECTEDGRAPH_H
