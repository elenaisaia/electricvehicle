#include <iostream>
#include "OptimalTimeDijkstra.h"

OptimalTimeDijkstra::OptimalTimeDijkstra(ElectricVehicle &vehicle, DirectedGraphForChargingStations &graph, unsigned int sourceId, unsigned int destinationId)
        : vehicle(vehicle), graph(graph), sourceId(sourceId), destinationId(destinationId) {
    for (auto &vertex : graph.getVertexList()) {
        visited[vertex.first] = false;
    }
}

double OptimalTimeDijkstra::findCost() {
    cost[sourceId] = 0;
    visited[sourceId] = true;
    NextChargingStation source(graph.getVertexById(sourceId), 0, 1000, 0);
    queue.push(source);

    while (!queue.empty()) {
        ChargingStation current = queue.top().getChargingStation();
        queue.pop();
        visited[current.getId()] = false;
        for(auto &arch : graph.getAdjacentStations(current)) {
            ChargingStation next = arch.getChargingStation();


            if(next.getId() == destinationId || next.isCompatibleWith(vehicle)) {
                double vehicleCostPerTimeUnit = vehicle.getCostPerTimeUnit(arch.getAvgSpeed());
                double finalBatteryPercentage;
                if(current.getId() == sourceId) {
                    finalBatteryPercentage = vehicle.getBatteryPercentage();
                }
                else {
                    finalBatteryPercentage = 100;
                }
                finalBatteryPercentage -= vehicleCostPerTimeUnit * arch.getTime();

                if(finalBatteryPercentage >= 20 || finalBatteryPercentage >= 10 && next.getId() != destinationId) {
                    double timeForFullCharge = (100 - finalBatteryPercentage) * std::min(vehicle.getOnePercentChargingTime(),
                                                                                         next.getOnePercentChargingTime());

                    auto newTime = cost.at(current.getId()) + arch.getTime() + timeForFullCharge;
                    if(cost.find(next.getId()) == cost.end() || cost.at(next.getId()) > newTime) {
                        cost[next.getId()] = newTime;
                        parent[next.getId()] = current.getId();
                        if(!visited.at(next.getId())) {
                            queue.push(arch);
                            visited[next.getId()] = true;
                        }
                    }
                }
            }
        }
    }

    parent[sourceId] = 99999;
    for(auto elem : cost) {
        std::cout << elem.first << ": cost=" << elem.second << " parent=" << parent.at(elem.first) << "\n";
    }

    return cost.at(destinationId);
}
