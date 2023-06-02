#include "ShortestDistanceDijkstra.h"

ShortestDistanceDijkstra::ShortestDistanceDijkstra(DirectedGraphForIntersections &graph) : graph(graph) {}

void ShortestDistanceDijkstra::findDistances(unsigned int sourceId) {
    cost.empty();
    visited.empty();
    queue.empty();

    cost[sourceId].distance = 0;
    visited[sourceId] = true;
    NextNode source{0, 0, sourceId};
    queue.push(source);

    while (!queue.empty()) {
        unsigned int current = queue.top().nextId;
        queue.pop();
        visited[current] = false;
        for(auto &arch : graph.getAdjacentNodes(current)) {
            if(cost.find(arch.nextId) == cost.end() || cost[arch.nextId].distance > cost[current].distance + arch.distance) {
                cost[arch.nextId].distance = cost[current].distance + arch.distance;
                if(!visited.at(arch.nextId)) {
                    queue.push(arch);
                    visited[arch.nextId] = true;
                }
            }
        }
    }
}

std::vector<NextChargingStation> ShortestDistanceDijkstra::getNextChargingStationsForChargingStation(unsigned int id) {
    findDistances(id);

    std::vector<NextChargingStation> nextStations;

    for(auto &pair : cost) {
        if(graph.containsChargingStation(id)) {
            if(pair.second.distance <= graph.getMaxDistance()) {
                nextStations.emplace_back(graph.getChargingStationById(id), pair.second.distance, pair.second.speed,
                                          pair.second.distance / pair.second.speed);
            }
        }
    }

    return nextStations;
}
