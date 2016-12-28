//
// Cab.
// inherit Taxi.

#ifndef EX1_CAB_H
#define EX1_CAB_H


#include "Taxi.h"

class Cab : public Taxi {

public:

    Cab(const Color &color, const CarManufacture &firm, int id) : Taxi(color, firm, id) {}

    void setTariff(double t);

    void move(stack<CoordinatedItem *> *road);
};

#endif //EX1_CAB_H
