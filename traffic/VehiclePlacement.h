//
// Copyright 2016 by WillyMillsLLC
//

#ifndef TRAFFIC_CARPLACEMENT_H
#define TRAFFIC_CARPLACEMENT_H


#include <vector>
#include "Vehicle.h"

class VehiclePlacement {
protected:
    Vehicle &vehicle;
    int x;
    int y;
public:
    VehiclePlacement &operator=(const VehiclePlacement &other);
    VehiclePlacement(Vehicle &a_vehicle, int x_position, int y_position);

    // Properties
    char identity();
    string key();
    void location(int &x, int &y);
    bool is_occupied(int x, int y);
    void location_bumped_by_decrement(int &x_position, int &y_position);
    void location_bumped_by_increment(int &x_position, int &y_position);
    void range(int &x_start, int &y_start, int &x_limit, int &y_limit);

    // actions
    void decrement();
    void increment();
    void mark_board(vector<vector<char> > &board);
};


#endif //TRAFFIC_CARPLACEMENT_H
