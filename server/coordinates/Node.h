//
// Node.
// inherit CoordinatedItem, has a point.
//

#ifndef EX1_NODE_H
#define EX1_NODE_H

#include "Point.h"

class Node : public CoordinatedItem {
private:
    Point *p;

public:
    Node() {};

    Node(Point *point) : p(new Point(point->getX(), point->getY())) {
        setDistance(-1);
    }

    ~Node() {
        delete (p);
    }

    Point *getP();

    void setP(Point *p);

    void deleteCoords(int **coords);

    int **getCoordinates();

    bool operator==(const Node &otherNode) const;

    bool operator!=(const Node &rhs) const;

};

#endif //EX1_NODE_H
