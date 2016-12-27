//
// CoordinatedItem.
// abstract class.
//

#ifndef EX1_COORDINATEDITEM_H
#define EX1_COORDINATEDITEM_H


class CoordinatedItem {
private:
    int distance;
    CoordinatedItem *parent;

public:

    /**
     * distructor
     */
    virtual ~CoordinatedItem() {
        parent = NULL;
    };

    /**
     * @return the CoordinatedItem's parent
     */
    CoordinatedItem *getParent() {
        return parent;
    }

    /**
     * @return the distance value
     */
    int getDistance() {
        return distance;
    }

    /**
     * @param d the distance value to set
     */
    void setDistance(int d) {
        distance = d;
    }

    /**
     * @param c the CoordinatedItem's parent to set
     */
    void setParent(CoordinatedItem *c) {
        parent = c;
    }

    /**
     * abstract method.
     * @return an array of int that represent the coordinate, depend the grid dimensions
     */
    virtual int **getCoordinates() = 0;

    /**
     * abstract method, needed after use in getCoordinates method.
     * @param coords to delete.
     */
    virtual void deleteCoords(int **coords) = 0;

};


#endif //EX1_COORDINATEDITEM_H
