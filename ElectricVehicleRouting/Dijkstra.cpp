#include <iostream>
#include "Dijkstra.h"

Dijkstra::Dijkstra(const ElectricVehicle &vehicle, const DirectedGraph &graph, unsigned int sourceId, unsigned int destinationId)
        : vehicle(vehicle), graph(graph), sourceId(sourceId), destinationId(destinationId) {
    for (auto vertex : graph.getVertexList()) {
        visited[vertex.first] = false;
    }
}

double Dijkstra::findCost() {
    cost[sourceId] = 0;
    visited[sourceId] = true;
    NextChargingStation source(graph.getVertexById(sourceId), 0, 1000, 1000, 0);
    queue.push(source);

    while (!queue.empty()) {
        ChargingStation current = queue.top().getChargingStation();
        queue.pop();
        visited[current.getId()] = false;
        for(auto arch : graph.getAdjacentStations(current)) {
            ChargingStation next = arch.getChargingStation();
            auto newTime = cost.at(current.getId()) + arch.getTime() + current.getCharhingTime();
            if(cost.find(next.getId()) == cost.end() || cost.at(next.getId()) > newTime) {
                cost[next.getId()] = newTime;
                parinte[next.getId()] = current.getId();
                if(!visited.at(next.getId())) {
                    queue.push(arch);
                    visited[next.getId()] = true;
                }
            }
        }
    }

    parinte[sourceId] = 99999;
    for(auto elem : cost) {
        std::cout << elem.first << ": cost=" << elem.second << " parinte=" << parinte.at(elem.first) << "\n";
    }

    return cost.at(destinationId);
}
