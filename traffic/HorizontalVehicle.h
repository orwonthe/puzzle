//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_HORIZONTALVEHICLE_H
#define TRAFFIC_HORIZONTALVEHICLE_H

#include "Vehicle.h"

class HorizontalVehicle : public Vehicle {
public:
    HorizontalVehicle(char marking, int len, string colour);

    // properties
    virtual bool is_occupied(int x, int y);
    virtual void location_bumped_by_increment(int &x_position, int &y_position);
    virtual void location_bumped_by_decrement(int &x_position, int &y_position);

    // actions
    virtual void mark_board(vector<vector<char> > &board, int x, int y);
};


#endif //TRAFFIC_HORIZONTALVEHICLE_H
