cmake_minimum_required(VERSION 3.6)
project(ex4AP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/coordinates/Point.cpp src/coordinates/Point.h src/coordinates/Map.cpp
        src/coordinates/Map.h src/managment/BFS.cpp src/managment/BFS.h src/coordinates/Grid.h
        src/coordinates/CoordinatedItem.h src/coordinates/Node.cpp src/coordinates/Node.h
        src/tripOperations/Driver.cpp src/tripOperations/Driver.h src/taxi/Taxi.h
        src/managment/SystemOperations.cpp src/managment/SystemOperations.h src/taxi/LuxuryCab.cpp
        src/taxi/LuxuryCab.h src/coordinates/Obstacle.cpp src/coordinates/Obstacle.h
        src/enum/MartialStatues.h src/enum/CarManufacture.h src/enum/Color.h
        src/tripOperations/Satisfaction.cpp src/tripOperations/Satisfaction.h
        src/listeners/TripEndListener.cpp src/listeners/TripEndListener.h
        src/listeners/EventListener.h src/tripOperations/TripInfo.cpp src/tripOperations/TripInfo.h
        src/tripOperations/TaxiCenter.cpp src/tripOperations/TaxiCenter.h src/managment/MainFlow.cpp
        src/managment/MainFlow.h src/tripOperations/Passenger.cpp src/tripOperations/Passenger.h
        src/taxi/Cab.cpp src/taxi/Cab.h src/enum/MartialStatuesFactory.h src/enum/ColorFactory.h
        src/enum/CarManufactureFactory.h src/managment/ProperInput.cpp src/managment/ProperInput.h
        main.cpp src/server/Client.cpp src/server/Server.cpp src/sockets/Socket.cpp src/sockets/Socket.h src/sockets/Udp.cpp src/sockets/Udp.h)
add_executable(ex4AP ${SOURCE_FILES})