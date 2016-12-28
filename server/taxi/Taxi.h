//
// Taxi - abstract class.
//

#ifndef EX1_TAXI_H
#define EX1_TAXI_H

#include "../enum/Color.h"
#include "../enum/CarManufacture.h"
#include "../coordinates/Node.h"
#include <stack>

class Taxi {

private:
    double tariff;
    Color color;
    CarManufacture firm;
    int kmPassed;
    int id;
    Node *location;

public:

    /**
     * constructor.
     * @param color of the taxi
     * @param firm of the taxi
     * @param id of the taxi
     */
    Taxi(const Color &color, const CarManufacture &firm, int id) :
            color(color), firm(firm), id(id), kmPassed(0) {
        Point p(0, 0);
        location = new Node(&p);
    }

    /**
     * destructor.
     */
    ~Taxi() {
        delete (location);
    };

    /**
     * @return the id of the Taxi.
     */
    int getId() const {
        return id;
    }

    /**
     * @return the location of the taxi
     */
    Node *getLocation() const {
        return location;
    }

    /**
     * abstract method.
     * @param t that needed to set
     */
    virtual void setTariff(double t) {
        tariff = t;
    };

    /**
     * abstract method.
     * @param road that need to follow
     */
    virtual void move(stack<CoordinatedItem *> *road) = 0;

    /**
     * @param p the location that the taxi need to get to
     */
    void applyToPoint(Point *p) {
        delete (location->getP());
        location->setP(p);
    }

    /**
     * @param otherTaxi to compare this taxi to
     * @return true if the taxi are the same
     */
    bool operator==(const Taxi &otherTaxi) const {
        return id == otherTaxi.id;
    }

    /**
     * @param otherTaxi to compare this taxi to
     * @return false if the taxi are the same
     */
    bool operator!=(const Taxi &otherTaxi) const {
        return !(otherTaxi == *this);
    }

};


#endif //EX1_TAXI_H
