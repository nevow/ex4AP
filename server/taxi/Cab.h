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

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<Taxi>(*this);
    }
};

#endif //EX1_CAB_H
