//
// Created by nevo on 01/12/16.
//

#ifndef EX1_DRIVER_H
#define EX1_DRIVER_H


#include "../enum/MartialStatues.h"
#include "TripInfo.h"
#include "Satisfaction.h"
#include "../taxi/Taxi.h"

class Driver {
private:
    int id;
    int age;
    MartialStatues status;
    int experience;
    TripInfo *ti;
    Satisfaction *satisfaction;
    Taxi *cab;
    int vehicleId;

public:
    Driver(int id, int age, const MartialStatues &status, int experience, int vehicle_id);

    Driver(Driver *d);

    ~Driver() {
        delete (satisfaction);
        if (ti) {
            delete (ti);
        }
    }

    int getId() const;

    int getAge() const;

    int getExperience() const;

    TripInfo *getTi();

    int getVehicle_id() const;

    Taxi *getCab() const;

    Satisfaction *getSatisfaction() const;

    const MartialStatues &getStatus() const;

    void setStatus(const MartialStatues &status);

    void setExperience(int experience);

    void setTi(TripInfo *tripinfo);

    void setCab(Taxi *cab);

    void updateSatisfaction(int grade);

    void moveOneStep();

    bool operator==(const Driver &otherDriver) const;

    bool operator!=(const Driver &otherDriver) const;

};


#endif //EX1_DRIVER_H
