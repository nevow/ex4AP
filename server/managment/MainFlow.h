//
// MainFlow.
//

#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H

#include <list>

#include "SystemOperations.h"
#include "boost/serialization/export.hpp"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"
#include "ProperInput.h"
#include "../sockets/Udp.h"


BOOST_CLASS_EXPORT_GUID(Cab, "Cab")
BOOST_CLASS_EXPORT_GUID(LuxuryCab, "LuxuryCab")

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
