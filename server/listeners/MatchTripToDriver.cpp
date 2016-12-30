//
// MatchTripToDriver.
//

#include "MatchTripToDriver.h"

/**
 * match trip info to driver.
 */
void MatchTripToDriver::notify() {

    // set the earliest trip info to the Closest Driver.
    while ((!(trips->empty())) && (!(availableDrivers->empty()))) {
        taxiCenter->setDriverToTi(taxiCenter->getUrgentTi());
    }
}