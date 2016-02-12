//
// Copyright 2016 by WillyMillsLLC
//

#ifndef TRAFFIC_VERTICALCAR_H
#define TRAFFIC_VERTICALCAR_H

#include "VerticalVehicle.h"

class VerticalCar : public VerticalVehicle {
public:
    VerticalCar(char marking, string colour);

    // properties.
    virtual string kind() override;
};


#endif //TRAFFIC_VERTICALCAR_H
