#include <iostream>
#include <fstream>
#include "ChargingStation.h"
#include "NextChargingStation.h"
#include "DirectedGraphForChargingStations.h"
#include "OptimalTimeDijkstra.h"

DirectedGraphForChargingStations readSmallGraphFromFile() {
    std::ifstream fin("smallgraph.txt");
    unsigned int v, a;
    fin >> v >> a;

    DirectedGraphForChargingStations graph = DirectedGraphForChargingStations(v, a);

    unsigned int id, time;
    int x, y, nr;
    for(int i = 0; i < v; i++) {
        fin >> id >> x >> y >> time >> nr;
        ChargingStation chargingStation(id, x, y, time);
        std::string type;
        for(int j = 0; j < nr; j++) {
            fin >> type;
            if(type == "Normal")
                chargingStation.addChargerType(Normal);
            else if(type == "Fast")
                chargingStation.addChargerType(Fast);
            else if(type == "Slow")
                chargingStation.addChargerType(Slow);
        }
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
    ElectricVehicle vehicle(49, Normal, 75, 0.06);
    vehicle.addCost(0, 30, 20);
    vehicle.addCost(31, 60, 15);
    vehicle.addCost(61, 80, 20);
    vehicle.addCost(81, 100, 35);
    vehicle.addCost(101, 130, 50);

    DirectedGraphForChargingStations graph = readSmallGraphFromFile();

    std::cout << graph.getVertexes() << " " << graph.getArches() << "\n";
    for(auto &station : graph.getVertexList()) {
        std::cout << station.first << " " << station.second.getId() << " " << station.second.getX() << " " << station.second.getY() << " " << station.second.getOnePercentChargingTime() << "\n";
    }

    for(const auto& arch : graph.getAdjacencyList()) {
        std::cout << "\n" << arch.first.getId() << ":\n";
        for(auto &station : arch.second) {
            std::cout << station.getChargingStation().getId() << " " << station.getDistance() << " " << station.getAvgSpeed() << " " << station.getTime() << "\n";
        }
    }
    std::cout << "\n";

    OptimalTimeDijkstra dijkstra(vehicle, graph, 0, 100);
    std::cout << dijkstra.findCost();
    return 0;
}
