//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_TRUCK_H
#define TRAFFIC_TRUCK_H


#include "HorizontalVehicle.h"

class Truck : public HorizontalVehicle {
public:
    Truck(char marking, string colour);

    // properties
    virtual string kind() override;
};


#endif //TRAFFIC_TRUCK_H
