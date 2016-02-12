//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_GARAGE_H
#define TRAFFIC_GARAGE_H


#include <vector>
#include <string>
#include "VehiclePlacement.h"

using namespace std;

class Garage {
protected:
    // properties
    vector<VehiclePlacement> vehicles;
    int width;
    int height;
    VehiclePlacement &find(char marking);

    // actions
    vector<vector<char>> blank_board();
    void show_top();
    void show_bottom();

public:
    Garage(int w = 6, int h = 6);

    // properties
    string signature();
    vector<vector<char>> board();
    bool is_occupied(int x, int y);
    vector<char> identities();
    bool victory();

    // actions
    void addVehicle(Vehicle &vehicle, int x, int y);
    bool decrement(char marking);
    bool increment(char marking);
    void show();
    void show_board(const vector<vector<char>> &board);
    void show_key();
};


#endif //TRAFFIC_GARAGE_H
