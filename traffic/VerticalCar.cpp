//
// Copyright 2016 by WillyMillsLLC
//

#include "VerticalCar.h"

VerticalCar::VerticalCar(char marking, string colour) : VerticalVehicle(marking, 2, colour) {

}

string VerticalCar::kind() {
    return "car";
}
