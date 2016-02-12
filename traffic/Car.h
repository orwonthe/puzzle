//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_CAR_H
#define TRAFFIC_CAR_H


#include "HorizontalVehicle.h"

class Car : public HorizontalVehicle {
public:
    Car(char marking, string colour);

    virtual string kind() override;
};


#endif //TRAFFIC_CAR_H
