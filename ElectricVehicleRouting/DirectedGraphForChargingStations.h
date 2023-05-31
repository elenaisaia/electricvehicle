#ifndef ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORCHARGINGSTATIONS_H
#define ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORCHARGINGSTATIONS_H

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

class DirectedGraphForChargingStations {
public:
    DirectedGraphForChargingStations(unsigned int vertexes, unsigned int arches);

    unsigned int getVertexes() const;

    unsigned int getArches() const;

    const std::unordered_map<unsigned int, ChargingStation> &getVertexList() const;

    void addChargingStationToVertexList(ChargingStation chargingStation);

    std::unordered_map<ChargingStation, std::vector<NextChargingStation>> getAdjacencyList() const;

    void addNextChargingStation(const ChargingStation& chargingStation, const NextChargingStation& nextChargingStation);

    std::vector<NextChargingStation> getAdjacentStations(ChargingStation chargingStation);

    DirectedGraphForChargingStations getTransposedGraph();

    ChargingStation getVertexById(unsigned int id);

private:
    unsigned int vertexes;
    unsigned int arches;
    std::unordered_map<ChargingStation, std::vector<NextChargingStation> > adjacencyList;
    std::unordered_map<unsigned int, ChargingStation> vertexList;
};


#endif //ELECTRICVEHICLEROUTING_DIRECTEDGRAPHFORCHARGINGSTATIONS_H
