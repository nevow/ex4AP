//
// SystemOperations.
//

#include "SystemOperations.h"

/**
 * constructor.
 * @param map1 the map to do on it the operations
 * @param obs is a lists of obstacles.
 */
SystemOperations::SystemOperations(Map *map1, list<Node *> *obs) {
    map = map1;
    obstacles = obs;
    tc = new TaxiCenter();
    x = map->getColumns();
    y = map->getRows();
}

/**
 *
 * @return the x of the so
 */
int SystemOperations::getX() const {
    return x;
}

/**
 *
 * @return the y of the so
 */
int SystemOperations::getY() const {
    return y;
}

/**
 * @param d is the Driver to add to the taxi center
 */
void SystemOperations::addDriver(Driver *d) {
    tc->addDriver(d);
}

/**
 * @param cab is the Taxi to add to the taxi center
 */
void SystemOperations::addTaxi(Taxi *cab) {
    tc->addTaxi(cab);

}

/**
 * @param tripInfo is the TripInfo to add to the taxi center
 */
void SystemOperations::addTI(TripInfo *tripInfo) {
    tc->addTI(tripInfo);
}

/**
 * @param id is the id od the driver
 * @return the Point of the driver from the taxiCenter
 */
Point *SystemOperations::getDriverLocation(int id) {
    return tc->getDriverLocation(id);
}

/**
 * move all the taxi by call Taxi Center's "moveAll"
 */
void SystemOperations::moveAll() {
    tc->moveAll();
}

/**
 * Not implement yet.
 * @param p the Passenger that ask for taxi
 */
/*void SystemOperations::connectCall(Passenger *p) {

}*/

/**
 * @param obstacle to add to the obstacles List.
 */
/*void SystemOperations::addObstacle(Node *obstacle) {
    obstacles->push_back(obstacle);
}*/