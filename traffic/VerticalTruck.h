//
// Copyright 2016 by WillyMillsLLC
//

#ifndef TRAFFIC_VERTICALTRUCK_H
#define TRAFFIC_VERTICALTRUCK_H


#include "VerticalVehicle.h"

class VerticalTruck : public VerticalVehicle {
public:
    VerticalTruck(char marking, string colour);

    // properties
    virtual string kind() override;
};


#endif //TRAFFIC_VERTICALTRUCK_H
