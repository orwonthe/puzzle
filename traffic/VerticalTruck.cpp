//
// Copyright 2016 by WillyMillsLLC
//

#include "VerticalTruck.h"

VerticalTruck::VerticalTruck(char marking, string colour) : VerticalVehicle(marking, 3, colour) {

}

string VerticalTruck::kind() {
    return "truck";
}
