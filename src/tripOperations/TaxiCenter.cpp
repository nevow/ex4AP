//
// TaxiCenter.
//

#include "TaxiCenter.h"
#include "../listeners/TripEndListener.h"

/**
 *
 * @return the working drivers list.
 */
list<Driver *> *TaxiCenter::getEmployees() const {
    return employees;
}

/**
 * @return get the available drivers list.
 */
list<Driver *> *TaxiCenter::getAvailableDrivers() const {
    return availableDrivers;
}

/**
 *
 * @param id of the driver
 * @return the location of the driver with the id
 */
Point *TaxiCenter::getDriverLocation(int id) {
    if (!employees->empty()) {
        for (std::list<Driver *>::const_iterator iterator = employees->begin(), end = employees->end();
             iterator != end; ++iterator) {
            if ((*iterator)->getId() == id) {
                return (*iterator)->getCab()->getLocation()->getP();
            }
        }
    }
    if (!availableDrivers->empty()) {
        for (std::list<Driver *>::const_iterator iterator = availableDrivers->begin(),
                     end = availableDrivers->end(); iterator != end; ++iterator) {
            if ((*iterator)->getId() == id) {
                return (*iterator)->getCab()->getLocation()->getP();
            }
        }
    }
    return NULL;
}

/**
 * @param id of the taxi
 * @return the location of the driver with the id
 */
Taxi *TaxiCenter::getTaxiByID(int id) {
    for (std::list<Taxi *>::const_iterator iterator = cabs->begin(),
                 end = cabs->end(); iterator != end; ++iterator) {
        if ((*iterator)->getId() == id) {
            return *iterator;
        }
    }
    return NULL;
}

/**
 *
 * @param start point of the trip
 * @return the closest driver to that point, remove from the list
 */
Driver *TaxiCenter::getClosestDriver(Point *start) {
    std::list<Driver *> temp;
    while (!availableDrivers->empty()) {
        Driver *d = availableDrivers->front();
        availableDrivers->pop_front();
        if (*(d->getCab()->getLocation()->getP()) == *start) {
            while (!temp.empty()) {
                availableDrivers->push_front((temp.front()));
                temp.pop_front();
            }
            return d;
        } else {
            temp.push_front(d);
        }
    }
    return NULL;
}

/**
 * @param d driver to add to the employees list.s
 */
void TaxiCenter::addDriver(Driver *d) {
    d->setCab(getTaxiByID(d->getVehicle_id()));
    availableDrivers->push_back(d);
    listeners->push_back(new TripEndListener(d, this));
}

/**
 * @param cab to add to the cabs list.
 */
void TaxiCenter::addTaxi(Taxi *cab) {
    cabs->push_back(cab);
}

/**
 * @param ti to add to the trips list.
 */
void TaxiCenter::addTI(TripInfo *ti) {
    // if there is available driver match them
    if (!availableDrivers->empty()) {
        setDriverToTi(ti);     // get available driver, assign him with the trip info.
    } else {
        trips->push_back(ti);
    }
}


/**
 * @param ti trip info to assign to the driver.
 * @return the driver after the set of the trip info.
 */
void TaxiCenter::setDriverToTi(TripInfo *ti) {
    // get the closest available driver, assign him with the trip info.
    Driver *d = getClosestDriver(ti->getStart());
    d->setTi(ti);
    employees->push_back(d);
}

/**
 * iterate over all the drivers and tell them to move.
 */
void TaxiCenter::moveAll() {
    // iterate over all drivers tell them to move.
    for (std::list<Driver *>::const_iterator iterator = employees->begin(),
                 end = employees->end(); iterator != end; ++iterator) {
        (*iterator)->moveOneStep();
    }
    // copy all listeners to a temp list
    std::list<EventListener *> temp;
    for (std::list<EventListener *>::const_iterator iterator = listeners->begin(),
                 end = listeners->end(); iterator != end; ++iterator) {
        temp.push_back(*iterator);
    }
    // tell all listener to notify.
    for (std::list<EventListener *>::const_iterator iterator = temp.begin(),
                 end = temp.end(); iterator != end; ++iterator) {
        (*iterator)->notify();
    }
}

/**
 *
 * @param el is event listener to remove from the list;
 */
void TaxiCenter::removeListener(EventListener *el) {
    // create temp list
    std::list<EventListener *> temp;
    while (!listeners->empty()) {
        // take the listener out
        EventListener *e = listeners->front();
        listeners->pop_front();
        // if this is the listener to delete
        if (e == el) {
            // push all the listeners in the temp list to the original
            while (!temp.empty()) {
                listeners->push_front((temp.front()));
                temp.pop_front();
            }
            return;
            // push the listener from the original list to the temp list
        } else {
            temp.push_front(e);
        }
    }
}


/**
 * not used in this assigment yet.
 * to be continued
 * @param p
 * @return
 */
/*TripInfo *TaxiCenter::answerCall(Passenger *p) {
    return NULL;
}*/


/**
 * @param d is the driver to assign the taxi too and to send on his way.
 *//*
void TaxiCenter::sendTaxi(Driver *d) {
    int cabId = d->getVehicle_id();
    // iterate over all the cabs, search for the right id.
    for (Taxi *t : *cabs) {
        if (t->getId() == cabId) {
            d->setCab(t);
            return;
        }
    }
}*/


