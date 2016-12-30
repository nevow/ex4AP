//
// Created by nevo on 30/12/16.
//

#include "SetTripListener.h"


SetTripListener::SetTripListener(
        std::list<TripInfo *> *trip, std::list<Driver *> *availDrivers,
        TaxiCenter *tc) : trips(trip), availableDrivers(availDrivers), taxiCenter(tc) {};


void SetTripListener::notify() {
    // set the earliest trip info to the Closest Driver.
    while ((!(trips->empty())) && (!(availableDrivers->empty()))) {
        taxiCenter->setDriverToTi(taxiCenter->getUrgentTi());
    }
};
