//
// Copyright 2016 by WillyMillsLLC
//

#include "Car.h"

Car::Car(char marking, string colour) : HorizontalVehicle(marking, 2, colour) {

}

string Car::kind() {
    return "car";
}
