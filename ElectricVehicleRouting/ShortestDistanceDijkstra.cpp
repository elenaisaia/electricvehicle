#include "ShortestDistanceDijkstra.h"

ShortestDistanceDijkstra::ShortestDistanceDijkstra(DirectedGraphForIntersections &graph) : graph(graph) {}

std::unordered_map<unsigned int, double> ShortestDistanceDijkstra::findDistances(unsigned int sourceId) {
    distances.empty();
    visited.empty();
    queue.empty();

    distances[sourceId] = 0;
    visited[sourceId] = true;
    NextNode source{0, 0, sourceId};
    queue.push(source);

    while (!queue.empty()) {
        unsigned int current = queue.top().nextId;
        queue.pop();
        visited[current] = false;
        for(auto &arch : graph.getAdjacentNodes(current)) {
            if(distances.find(arch.nextId) == distances.end() || distances[arch.nextId] > distances[current] + arch.distance) {
                distances[arch.nextId] = distances[current] + arch.distance;
                if(!visited.at(arch.nextId)) {
                    queue.push(arch);
                    visited[arch.nextId] = true;
                }
            }
        }
    }

    return distances;
}
