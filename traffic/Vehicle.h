//
// Copyright 2016 by WillyMillsLLC
//

#ifndef TRAFFIC_VEHICLE_H
#define TRAFFIC_VEHICLE_H


#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    bool is_vertical;
    int length;
    char identity;
    string color;
public:
    Vehicle(char marking, int len, bool vertical, string colour);

    // properties
    char marking();
    virtual string kind() = 0;
    string key();
    virtual string name();
    bool is_vertical_direction();
    virtual bool is_occupied(int x, int y) = 0;
    virtual void location_bumped_by_increment(int &x_position, int &y_position) = 0;
    virtual void location_bumped_by_decrement(int &x_position, int &y_position) = 0;
    virtual void range(int &x, int&y) = 0;

    // actions
    virtual void mark_board(vector<vector<char> > &board, int x, int y) = 0;
};


#endif //TRAFFIC_VEHICLE_H
