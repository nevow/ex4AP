//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TAXICENTER_H
#define EX1_TAXICENTER_H


#include <list>
#include "Driver.h"
#include "../coordinates/Point.h"
#include "Passenger.h"
#include "../listeners/EventListener.h"

using namespace std;

class TaxiCenter {
private:
    list<Driver *> *employees;
    list<Node *> *locations;
    list<Taxi *> *cabs;
    list<TripInfo *> *trips;
    list<Driver *> *availableDrivers;
    list<EventListener *> *listeners;
public:
    TaxiCenter(list<Driver *> *employees, list<Node *> *locations, list<Taxi *> *cabs,
               list<TripInfo *> *trips)
            : employees(employees), locations(locations), cabs(cabs), trips(trips),
              availableDrivers(employees) {}

    TaxiCenter() {
        employees = new list<Driver *>();
        locations = new list<Node *>();
        cabs = new list<Taxi *>();
        trips = new list<TripInfo *>();
        availableDrivers = new list<Driver *>();
        listeners = new list<EventListener *>();
    }

    ~TaxiCenter() {
        // delete the employees list
        while (!employees->empty()) {
            delete (employees->front());
            employees->pop_front();
        }
        delete (employees);

        // delete the employees list
        while (!locations->empty()) {
            delete (locations->front());
            locations->pop_front();
        }
        delete (locations);

        // delete the employees list
        while (!cabs->empty()) {
            delete (cabs->front());
            cabs->pop_front();
        }
        delete (cabs);

        // delete the employees list
        while (!trips->empty()) {
            delete (trips->front());
            trips->pop_front();
        }
        delete (trips);

        // delete the employees list
        while (!availableDrivers->empty()) {
            delete (availableDrivers->front());
            availableDrivers->pop_front();
        }
        delete (availableDrivers);

        // delete the employees list
        while (!listeners->empty()) {
            delete (listeners->front());
            listeners->pop_front();
        }
        delete (listeners);
    }

    list<Driver *> *getEmployees() const;

    list<Driver *> *getAvailableDrivers() const;

    Point *getDriverLocation(int id);

    Taxi *getTaxiByID(int id);

    Driver *getClosestDriver(Point *start);

    void addDriver(Driver *d);

    void addTaxi(Taxi *cab);

    void addTI(TripInfo *ti);

    void setDriverToTi(TripInfo *ti);

    void moveAll();

    void removeListener(EventListener *el);

    //TripInfo *answerCall(Passenger *p);

    //void sendTaxi(Driver *d);
};


#endif //EX1_TAXICENTER_H
