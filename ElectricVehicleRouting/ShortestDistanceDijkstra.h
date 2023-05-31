#ifndef ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H
#define ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H

#include <queue>
#include "DirectedGraphForIntersections.h"

class ShortestDistanceDijkstra {
public:
    ShortestDistanceDijkstra(DirectedGraphForIntersections &graph);

    std::unordered_map<unsigned int, double> findDistances(unsigned int sourceId);

private:
    DirectedGraphForIntersections &graph;
    std::priority_queue<NextNode> queue;
    std::unordered_map<unsigned int, double> distances;
    std::unordered_map<unsigned int, bool> visited;
};


#endif //ELECTRICVEHICLEROUTING_SHORTESTDISTANCEDIJKSTRA_H
