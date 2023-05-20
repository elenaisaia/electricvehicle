cmake_minimum_required(VERSION 3.22)
project(ElectricVehicleRouting)

set(CMAKE_CXX_STANDARD 14)

add_executable(ElectricVehicleRouting main.cpp ChargingStation.cpp ChargingStation.h NextChargingStation.cpp NextChargingStation.h DirectedGraph.cpp DirectedGraph.h)
