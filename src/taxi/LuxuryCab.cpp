//
// LuxuryCab.
// inherit Taxi.

#include "LuxuryCab.h"

/**
 * LuxuryCab move twice faster that cab.
 * @param road to move the cab according to
 */
void LuxuryCab::move(stack<CoordinatedItem *> *road) {
    if (!road->empty()) {
        CoordinatedItem *item = road->top();
        road->pop();
        // if we didn't got to the end of the road - move to the next CoordinatedItem
        if (!road->empty()) {
            delete (item);
            item = road->top();
            road->pop();
        }
        int **coords = item->getCoordinates();
        delete (item);
        Point p(*(coords[0]), *(coords[1]));
        applyToPoint(&p);
        p.deleteCoords(coords);
    }
}

/**
 * @param t is the tariff of the LuxuryCab
 */
void LuxuryCab::setTariff(double t) {
    Taxi::setTariff(t * 2);
}