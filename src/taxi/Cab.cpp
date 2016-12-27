//
// Cab.
// inherit Taxi.

#include "Cab.h"

/**
 * @param t is the tariff of the taxi
 */
void Cab::setTariff(double t) {
    Taxi::setTariff(t);
}

/**
 * @param road to move the cab according to
 */
void Cab::move(stack<CoordinatedItem *> *road) {
    if (!road->empty()) {
        CoordinatedItem *item = road->top();
        road->pop();
        int **coords = item->getCoordinates();
        delete (item);
        Point p(*(coords[0]), *(coords[1]));
        applyToPoint(&p);
        p.deleteCoords(coords);
    }
}
