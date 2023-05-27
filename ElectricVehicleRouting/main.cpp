#include <iostream>
#include <fstream>
#include "ChargingStation.h"
#include "NextChargingStation.h"
#include "DirectedGraph.h"
#include "Dijkstra.h"

DirectedGraph readSmallGraphFromFile() {
    std::ifstream fin("smallgraph.txt");
    unsigned int v, a;
    fin >> v >> a;

    DirectedGraph graph = DirectedGraph(v, a);

    unsigned int id, time;
    int x, y;
    for(int i = 0; i < v; i++) {
        fin >> id >> x >> y >> time;
        ChargingStation chargingStation(id, x, y, time, Normal);
        graph.addChargingStationToVertexList(chargingStation);
    }

    std::unordered_map<unsigned int, ChargingStation> vertexes = graph.getVertexList();
    unsigned int v1, v2, maxi, avg;
    for(int i = 0; i < a; i++) {
        fin >> v1 >> v2 >> maxi >> avg;
        ChargingStation source = vertexes[v1];
        ChargingStation destination = vertexes[v2];
        NextChargingStation station = NextChargingStation::createFromCoordinates(destination, maxi, avg, source.getX(), source.getY());
        graph.addNextChargingStation(source, station);
    }

    return graph;
}

int main() {
    DirectedGraph graph = readSmallGraphFromFile();

    std::cout << graph.getVertexes() << " " << graph.getArches() << "\n";
    for(auto station : graph.getVertexList()) {
        std::cout << station.first << " " << station.second.getId() << " " << station.second.getX() << " " << station.second.getY() << " " << station.second.getCharhingTime() << "\n";
    }

    for(const auto& arch : graph.getAdjacencyList()) {
        std::cout << "\n" << arch.first.getId() << ":\n";
        for(auto station : arch.second) {
            std::cout << station.getChargingStation().getId() << " " << station.getDistance() << " " << station.getAvgSpeed() << " " << station.getTime() << "\n";
        }
    }

    ElectricVehicle vehicle(1, Normal, 65);
    Dijkstra dijkstra(vehicle, graph, 0, 100);
    std::cout << dijkstra.findCost();
    return 0;
}
