//
// Point.
// has x and y as coordinates.
//


#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <iostream>
#include "CoordinatedItem.h"

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point() {}

    Point(int x, int y) : x(x), y(y) {};

    ~Point() {}

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    void deleteCoords(int **coords);

    friend ostream &operator<<(ostream &output, const Point &p);

    friend istream &operator>>(istream &input, Point &p);

    bool operator==(const Point &otherP) const;

    bool operator!=(const Point &rhs) const;

};


#endif //EX1_POINT_H
