#include "DirectedGraphForIntersections.h"
#include <fstream>
#include <cmath>

DirectedGraphForIntersections::DirectedGraphForIntersections(double maxDistance, unsigned int vertexes) : vertexes(vertexes), maxDistance(maxDistance) {}

unsigned int DirectedGraphForIntersections::getVertexes() const {
    return vertexes;
}

unsigned int DirectedGraphForIntersections::getArches() const {
    return arches;
}

const std::unordered_map<unsigned int, std::vector<NextNode>> &DirectedGraphForIntersections::getAdjacencyList() const {
    return adjacencyList;
}

const std::unordered_map<unsigned int, ChargingStation> &DirectedGraphForIntersections::getChargingStationList() const {
    return chargingStationList;
}

const std::unordered_map<unsigned int, Intersection> &DirectedGraphForIntersections::getIntersectionList() const {
    return intersectionList;
}

void DirectedGraphForIntersections::addChargingStationToChargingStationList(const ChargingStation& chargingStation) {
    chargingStationList[chargingStation.getId()] = chargingStation;
}

void DirectedGraphForIntersections::addIntersectionToIntersectionList(const Intersection& intersection) {
    intersectionList[intersection.getId()] = intersection;
}

void DirectedGraphForIntersections::addToAdjacencyList(unsigned int sourceId, unsigned int destinationId, double distance,
                                                  unsigned int speed) {
    adjacencyList[sourceId].push_back(NextNode{distance, speed, destinationId});
}

std::vector<NextNode> DirectedGraphForIntersections::getAdjacentNodes(unsigned int id) {
    return adjacencyList[id];
}

Intersection DirectedGraphForIntersections::getIntersectionById(unsigned int id) {
    return intersectionList[id];
}

ChargingStation DirectedGraphForIntersections::getChargingStationById(unsigned int id) {
    return chargingStationList[id];
}

bool DirectedGraphForIntersections::containsChargingStation(unsigned int id) {
    if(chargingStationList.find(id) == chargingStationList.end())
        return false;
    return true;
}

double DirectedGraphForIntersections::getMaxDistance() const {
    return maxDistance;
}

DirectedGraphForIntersections DirectedGraphForIntersections::generateGraph(unsigned int noOfChargingStations,
                                                                           unsigned int noOfIntersections,
                                                                           double maxDistance,
                                                                           const std::string& fileName) {
    DirectedGraphForIntersections g(maxDistance, noOfChargingStations + noOfIntersections);

    for(unsigned int i = 0; i < noOfChargingStations; i++) {
        g.addChargingStationToChargingStationList(ChargingStation(i, iRand(-250, 250), iRand(-250, 250), iRand(3, 10)));
    }

    for(unsigned int i = noOfChargingStations; i < noOfIntersections + noOfChargingStations; i++) {
        g.addIntersectionToIntersectionList(Intersection(i, iRand(-250, 250), iRand(-250, 250)));
    }

    for(unsigned int i = 0; i < noOfChargingStations; i++) {
        for(unsigned int j = 0; j < noOfChargingStations; j++) {
            if(i != j) {
                double distance = euclidean_distance(chargingStationList[i].getX(), chargingStationList[i].getY(),
                                                     chargingStationList[j].getX(), chargingStationList[j].getY()) *
                                  fRand(1, sqrt(2));
                if (distance > 0 && distance < maxDistance &&
                    iRand(0, 99) < 20) { //adding an arch with a 20% probability
                    incrementArches();
                    unsigned int speed = iRand(30, 131);
                    speed -= speed % 10;
                    g.addToAdjacencyList(i, j, distance, speed);
                }
            }
        }

        for(unsigned int j = noOfChargingStations; j < noOfIntersections + noOfChargingStations; j++) {
            double distance = euclidean_distance(chargingStationList[i].getX(), chargingStationList[i].getY(),
                                                 intersectionList[j].getX(), intersectionList[j].getY()) *
                              fRand(1, sqrt(2));
            if (distance > 0 && distance < maxDistance && iRand(0, 99) < 20) { //adding an arch with a 20% probability
                incrementArches();
                unsigned int speed = iRand(30, 131);
                speed -= speed % 10;
                g.addToAdjacencyList(i, j, distance, speed);
            }
        }
    }

    for(unsigned int i = noOfChargingStations; i < noOfIntersections + noOfChargingStations; i++) {
        for(unsigned int j = 0; j < noOfChargingStations; j++) {
            double distance = euclidean_distance(intersectionList[i].getX(), intersectionList[i].getY(),
                                                 chargingStationList[j].getX(), chargingStationList[j].getY()) *
                              fRand(1, sqrt(2));
            if (distance > 0 && distance < maxDistance && iRand(0, 99) < 20) { //adding an arch with a 20% probability
                incrementArches();
                unsigned int speed = iRand(30, 131);
                speed -= speed % 10;
                g.addToAdjacencyList(i, j, distance, speed);
            }
        }

        for(unsigned int j = noOfChargingStations; j < noOfIntersections + noOfChargingStations; j++) {
            if(i != j) {
                double distance = euclidean_distance(intersectionList[i].getX(), intersectionList[i].getY(),
                                                     intersectionList[j].getX(), intersectionList[j].getY()) *
                                  fRand(1, sqrt(2));
                if (distance > 0 && distance < maxDistance &&
                    iRand(0, 99) < 20) { //adding an arch with a 20% probability
                    incrementArches();
                    unsigned int speed = iRand(30, 131);
                    speed -= speed % 10;
                    g.addToAdjacencyList(i, j, distance, speed);
                }
            }
        }
    }

    g.writeGraphToFile(fileName);
    return g;
}

DirectedGraphForIntersections DirectedGraphForIntersections::readGraphFromFile(const std::string& fileName) {
    std::ifstream fin(fileName);

    unsigned int noOfChargingStations, noOfIntersections, noOfArches;
    double maxDistance;
    fin >> noOfChargingStations >> noOfIntersections >> noOfArches >> maxDistance;

    DirectedGraphForIntersections g(maxDistance, noOfIntersections + noOfChargingStations);
    g.setArches(noOfArches);

    for(int i = 0; i < noOfChargingStations; i++) {
        unsigned int id, noOfChargingTypes;
        int x, y;
        double onePercentChargingTime;
        fin >> id >> x >> y >> onePercentChargingTime >> noOfChargingTypes;

        ChargingStation chargingStation(id, x, y, onePercentChargingTime);

        for(int j = 0; j < noOfChargingTypes; j++) {
            std::string type;
            fin >> type;
            if(type == "Normal") {
                chargingStation.addChargerType(Normal);
            }
            else if (type == "Fast") {
                chargingStation.addChargerType(Fast);
            }
            else if (type == "Slow") {
                chargingStation.addChargerType(Slow);
            }
        }

        g.addChargingStationToChargingStationList(chargingStation);
    }

    for(int i = 0; i < noOfIntersections; i++) {
        unsigned int id;
        int x, y;
        fin >> id >> x >> y;

        g.addIntersectionToIntersectionList(Intersection(id, x, y));
    }

    for(int i = 0; i < noOfArches; i++) {
        unsigned int sourceId, destinationId, speed;
        double distance;
        fin >> sourceId >> destinationId >> distance >> speed;

        g.addToAdjacencyList(sourceId, destinationId, distance, speed);
    }

    return g;
}

void DirectedGraphForIntersections::writeGraphToFile(const std::string& fileName) const {
    std::ofstream fout(fileName);

    fout << chargingStationList.size() << " " << intersectionList.size() << " " << arches << " " << maxDistance << "\n";

    for(auto& chargingStation : chargingStationList) {
        auto& types = chargingStation.second.getChargerTypes();
        fout << chargingStation.first << " " << chargingStation.second.getX() << " " << chargingStation.second.getY()
             << " " << chargingStation.second.getOnePercentChargingTime() << types.size() << "\n";
        for(auto type : types) {
            fout << type << "\n";
        }
    }

    for(auto& intersection : intersectionList) {
        fout << intersection.first << " " << intersection.second.getX() << " " << intersection.second.getY() << "\n";
    }

    for(auto& arch : adjacencyList) {
        for(auto& next : arch.second) {
            fout << arch.first << " " << next.nextId << " " << next.distance << " " << next.speed;
        }
    }
}

double DirectedGraphForIntersections::euclidean_distance(int x, int y, unsigned int x1, unsigned int y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

double DirectedGraphForIntersections::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int DirectedGraphForIntersections::iRand(int iMin, int iMax) {
    int i = (int)rand() / RAND_MAX;
    return iMin + i * (iMax - iMin);
}

void DirectedGraphForIntersections::setArches(unsigned int arches) {
    DirectedGraphForIntersections::arches = arches;
}

void DirectedGraphForIntersections::incrementArches() {
    arches++;
}

bool NextNode::operator<(const NextNode &rhs) const {
    if (distance < rhs.distance)
        return true;
    if (rhs.distance < distance)
        return false;
    if (speed > rhs.speed)
        return true;
    if (rhs.speed > speed)
        return false;
    return nextId < rhs.nextId;
}

bool NextNode::operator>(const NextNode &rhs) const {
    return rhs < *this;
}

bool NextNode::operator<=(const NextNode &rhs) const {
    return !(rhs < *this);
}

bool NextNode::operator>=(const NextNode &rhs) const {
    return !(*this < rhs);
}
