//
// Copyright 2016 by WillyMillsLLC
//

#include "VehiclePlacement.h"

VehiclePlacement::VehiclePlacement(Vehicle &a_vehicle, int x_position, int y_position) :
        vehicle(a_vehicle),
        x(x_position),
        y(y_position) { }

VehiclePlacement &VehiclePlacement::operator=(const VehiclePlacement &other) {
    vehicle = other.vehicle;
    x = other.x;
    y = other.y;
}

//
// properties
//
char VehiclePlacement::identity() {
    return vehicle.marking();
}

string VehiclePlacement::key() {
    return vehicle.key();
}

void VehiclePlacement::location(int &x_position, int &y_position) {
    x_position = x;
    y_position = y;
}

bool VehiclePlacement::is_occupied(int x_position, int y_position) {
    return vehicle.is_occupied(x_position - x, y_position - y);
}

void VehiclePlacement::location_bumped_by_decrement(int &x_position, int &y_position) {
    vehicle.location_bumped_by_decrement(x_position, y_position);
    x_position += x;
    y_position += y;
}

void VehiclePlacement::location_bumped_by_increment(int &x_position, int &y_position) {
    vehicle.location_bumped_by_increment(x_position, y_position);
    x_position += x;
    y_position += y;
}

void VehiclePlacement::range(int &x_start, int &y_start, int &x_limit, int &y_limit) {
    x_start = x;
    y_start = y;
    vehicle.range(x_limit, y_limit);
    x_limit += x;
    y_limit += y;
}


//
// actions
//

void VehiclePlacement::decrement() {
    if (vehicle.is_vertical_direction()) {
        y--;
    } else {
        x--;
    }
}
void VehiclePlacement::increment() {
    if (vehicle.is_vertical_direction()) {
        y++;
    } else {
        x++;
    }
}

void VehiclePlacement::mark_board(vector<vector<char> > &board) {
    vehicle.mark_board(board, x, y);
}




