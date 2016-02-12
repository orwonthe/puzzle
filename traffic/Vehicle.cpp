//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include "Vehicle.h"

Vehicle::Vehicle(char marking, int len, bool vertical, string colour) :
        identity(marking),
        length(len),
        is_vertical(vertical),
        color(colour) { }

char Vehicle::marking() {
    return identity;
}

bool Vehicle::is_vertical_direction() {
    return is_vertical;
}

string Vehicle::name() {
    return color + " " + kind();
}

string Vehicle::key() {
    string s_key(1, marking());
    return s_key + ": " + name();
}
