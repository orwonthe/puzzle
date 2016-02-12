//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include "Truck.h"

Truck::Truck(char marking, string colour) : HorizontalVehicle(marking, 3, colour) {

}

string Truck::kind() {
    return "truck";
}
