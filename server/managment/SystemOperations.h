//
// Created by nevo on 01/12/16.
//

#ifndef EX1_SYSTEMOPERATIONS_H
#define EX1_SYSTEMOPERATIONS_H

#include <list>
#include "../coordinates/Node.h"
#include "../tripOperations/TaxiCenter.h"
#include "../coordinates/Map.h"
#include "../listeners/EventListener.h"

using namespace std;

class SystemOperations {
private:
    int x;
    int y;
    list<Node *> *obstacles;
    TaxiCenter *tc;
    Map *map;

public:
    SystemOperations(Map *map1, list<Node *> *obs);

    ~SystemOperations() {
        delete (map);
        delete (tc);
        while (!obstacles->empty()) {
            delete (obstacles->front());
            obstacles->pop_front();
        }
        delete (obstacles);
    }

    int getX() const;

    int getY() const;

    void addDriver(Driver *d);

    void addTaxi(Taxi *cab);

    void addTI(TripInfo *tripInfo);

    Point *getDriverLocation(int id);

    void moveAll();

    //void addObstacle(Node *obstacle);

    //void connectCall(Passenger *p);
};


#endif //EX1_SYSTEMOPERATIONS_H
