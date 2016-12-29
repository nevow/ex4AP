//
// MainFlow.
//

#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H

#include <list>

#include "SystemOperations.h"

class MainFlow {
private:
    int clock = 0;
    SystemOperations *so;

public:
    MainFlow();

    ~MainFlow() {
        delete so;
    }

    void input(int ip);
};


#endif //EX1_MAINFLOW_H
