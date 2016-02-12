//
// Copyright 2016 by WillyMillsLLC
//

#ifndef TRAFFIC_VERTICALVEHICLE_H
#define TRAFFIC_VERTICALVEHICLE_H

#include "Vehicle.h"

class VerticalVehicle : public Vehicle {
public:
    VerticalVehicle(char marking, int len, string colour);

    // properties
    virtual bool is_occupied(int x, int y);

    // actions
    virtual void location_bumped_by_decrement(int &x_position, int &y_position);
    virtual void location_bumped_by_increment(int &x_position, int &y_position);
    virtual void mark_board(vector<vector<char> > &board, int x, int y);
};


#endif //TRAFFIC_VERTICALVEHICLE_H
