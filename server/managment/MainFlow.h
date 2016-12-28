//
// MainFlow.
//

#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H

#include <list>

#include "SystemOperations.h"

class MainFlow {
private:
    SystemOperations *so;

public:
    MainFlow();

    ~MainFlow() {
        delete so;
    }

    void input();
};


#endif //EX1_MAINFLOW_H
