//
// not in use yet ..
//

#ifndef EX1_OBSTACLE_H
#define EX1_OBSTACLE_H


#include "Node.h"

class Obstacle : public Node {
private:
    int length;
    int width;

public:
    Obstacle(Point *p, int len, int wid) : Node(p) {
        length = len;
        width = wid;
    }

    int getLength() const;

    int getWidth() const;

    void setLength(int length);

    void setWidth(int width);
};


#endif //EX1_OBSTACLE_H
