cmake_minimum_required(VERSION 3.6)
project(ex4AP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES server/coordinates/Point.cpp server/coordinates/Point.h server/coordinates/Map.cpp
        server/coordinates/Map.h server/managment/BFS.cpp server/managment/BFS.h server/coordinates/Grid.h
        server/coordinates/CoordinatedItem.h server/coordinates/Node.cpp server/coordinates/Node.h
        server/tripOperations/Driver.cpp server/tripOperations/Driver.h server/taxi/Taxi.h
        server/managment/SystemOperations.cpp server/managment/SystemOperations.h server/taxi/LuxuryCab.cpp
        server/taxi/LuxuryCab.h server/coordinates/Obstacle.cpp server/coordinates/Obstacle.h
        server/enum/MartialStatues.h server/enum/CarManufacture.h server/enum/Color.h
        server/tripOperations/Satisfaction.cpp server/tripOperations/Satisfaction.h
        server/listeners/TripEndListener.cpp server/listeners/TripEndListener.h
        server/listeners/EventListener.h server/tripOperations/TripInfo.cpp server/tripOperations/TripInfo.h
        server/tripOperations/TaxiCenter.cpp server/tripOperations/TaxiCenter.h server/managment/MainFlow.cpp
        server/managment/MainFlow.h server/tripOperations/Passenger.cpp server/tripOperations/Passenger.h
        server/taxi/Cab.cpp server/taxi/Cab.h server/enum/MartialStatuesFactory.h server/enum/ColorFactory.h
        server/enum/CarManufactureFactory.h server/managment/ProperInput.cpp server/managment/ProperInput.h
        server/main.cpp client/Client.cpp server/Server.cpp
        server/sockets/Socket.cpp server/sockets/Socket.h server/sockets/Udp.cpp server/sockets/Udp.h)

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

add_executable(ex4AP ${SOURCE_FILES})

target_link_libraries(main ${Boost_LIBRARIES})