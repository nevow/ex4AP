//
// MatchTripToDriver.
//

#ifndef EX4AP_AVAILABLEDRIVER_H
#define EX4AP_AVAILABLEDRIVER_H


#include "EventListener.h"
#include "../tripOperations/Driver.h"
#include "../tripOperations/TaxiCenter.h"

class MatchTripToDriver : public EventListener {
    TaxiCenter *taxiCenter;
    list<TripInfo *> *trips;
    list<Driver *> *availableDrivers;
public:
    MatchTripToDriver(list<TripInfo *> *trip, list<Driver *> *availDrivers, TaxiCenter *tc) :
            trips(trip), availableDrivers(availDrivers), taxiCenter(tc) {}

    void notify();

};


#endif //EX4AP_AVAILABLEDRIVER_H
