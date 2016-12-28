//
// Created by nevo on 01/12/16.
//

#ifndef EX1_PASSENGER_H
#define EX1_PASSENGER_H


#include "../coordinates/Point.h"

class Passenger {
private:
    Point* start;
    Point* destination;

public:
    Passenger(Point *start, Point *destination);

    int generateSatisfaction();
};


#endif //EX1_PASSENGER_H
