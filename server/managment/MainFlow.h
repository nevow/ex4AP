//
// MainFlow.
//

#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H

#include <list>

#include "SystemOperations.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"
#include "ProperInput.h"
#include "../sockets/Udp.h"
#include "../taxi/Cab.h"
#include "../taxi/LuxuryCab.h"

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
