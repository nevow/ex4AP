//
// Created by nevo on 30/12/16.
//

#ifndef EX4AP_MATCHTRIPTODRIVERLISTENER_H
#define EX4AP_MATCHTRIPTODRIVERLISTENER_H
class TaxiCenter;
#include "EventListener.h"
#include "../tripOperations/TaxiCenter.h"
#include <list>

class SetTripListener : public EventListener {
private:
    list<TripInfo *> *trips;
    list<Driver *> *availableDrivers;
    TaxiCenter * taxiCenter;
public:
    SetTripListener(list<TripInfo *> *trip, list<Driver *> *availDrivers, TaxiCenter *tc);

    void notify();

};


#endif //EX4AP_MATCHTRIPTODRIVERLISTENER_H
