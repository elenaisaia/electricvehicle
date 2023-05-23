#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(unsigned int vertexes, unsigned int arches) : vertexes(vertexes), arches(arches) {}

unsigned int DirectedGraph::getVertexes() const {
    return vertexes;
}

unsigned int DirectedGraph::getArches() const {
    return arches;
}

const std::unordered_map<unsigned int, ChargingStation> &DirectedGraph::getVertexList() const {
    return vertexList;
}

void DirectedGraph::addChargingStationToVertexList(ChargingStation chargingStation) {
    vertexList[chargingStation.getId()] = chargingStation;
}

std::unordered_map<ChargingStation, std::vector<NextChargingStation>> DirectedGraph::getAdjacencyList() const {
    return adjacencyList;
}

void DirectedGraph::addNextChargingStation(const ChargingStation& chargingStation, const NextChargingStation& nextChargingStation) {
    adjacencyList[chargingStation].emplace_back(nextChargingStation);
}

std::vector<NextChargingStation> DirectedGraph::getAdjacentStations(ChargingStation chargingStation) {
//    return adjacencyList.at(chargingStation);
    return adjacencyList[chargingStation];
}

DirectedGraph DirectedGraph::getTransposedGraph() {
    DirectedGraph transposedGraph = DirectedGraph(vertexes, arches);
    for(const auto& key_values : adjacencyList) {
        ChargingStation key = key_values.first;
        std::vector<NextChargingStation> values = key_values.second;
        for(NextChargingStation station : values) {
            ChargingStation chargingStation = station.getChargingStation();
            NextChargingStation nextChargingStation = NextChargingStation(key, station.getDistance(), station.getMaxSpeed(), station.getAvgSpeed(), station.getTime());
            transposedGraph.addNextChargingStation(chargingStation, nextChargingStation);
        }
    }
    return transposedGraph;
}
