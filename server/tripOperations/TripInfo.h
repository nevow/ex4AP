//
// TripInfo.
//

#ifndef EX1_TRIPINFO_H
#define EX1_TRIPINFO_H


#include <stack>
#include <list>
#include "../coordinates/Point.h"
#include "Passenger.h"
#include <boost/serialization/list.hpp>
#include <boost/serialization/stack.hpp>


class TripInfo {

private:
    int rideId;
    int currentDistance;
    Point *start;
    Point *destination;
    int amountOfPassengers;
    list<Passenger *> *passengers;
    stack<CoordinatedItem *> *road;
    double tariff;

public:
    TripInfo() {};

    TripInfo(int rideId, Point *start, Point *destination, int amountOfPassengers, double tariff);

    ~TripInfo() {
        if (passengers) {
            while (!passengers->empty()) {
                delete (passengers->front());
                passengers->pop_front();
            }
            delete (passengers);
        }
        while (!road->empty()) {
            delete (road->top());
            road->pop();
        }
        delete road;
        delete start;
        delete destination;
    }

    double getTariff() const;

    bool checkEnd(Point *location);

    stack<CoordinatedItem *> *getRoad();

    int getAmountOfPassengers() const;

    list<Passenger *> *getPassengers() const;

    Point *getStart() const;

    bool operator==(const TripInfo &ti) const;

    bool operator!=(const TripInfo &ti) const;

    friend class boost::serialization::access;

    template<class Archive>
    void save(Archive &ar, const unsigned int version) const {
        ar & rideId;
        ar & currentDistance;
        ar & start;
        ar & destination;
        ar & amountOfPassengers;
        ar & passengers;
        std::stack<CoordinatedItem *> temp;
        int size = 0;
        while (!road->empty()) {
            temp.push((road->top()));
        }
        ar & road;
        ar & tariff;
    }

    template<class Archive>
    void load(Archive &ar, const unsigned int version) {
        ar & rideId;
        ar & currentDistance;
        ar & start;
        ar & destination;
        ar & amountOfPassengers;
        ar & passengers;
        ar & road;
        ar & tariff;
    }

    BOOST_SERIALIZATION_SPLIT_MEMBER()
    /*template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & rideId;
        ar & currentDistance;
        ar & start;
        ar & destination;
        ar & amountOfPassengers;
        ar & passengers;
        //ar & road;
        ar & tariff;
    }*/
};

#endif //EX1_TRIPINFO_H

