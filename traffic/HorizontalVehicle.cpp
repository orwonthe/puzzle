//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include "HorizontalVehicle.h"

HorizontalVehicle::HorizontalVehicle(char marking, int len, string colour) : Vehicle(marking, len, false, colour) {
}

//
// properties
//
bool HorizontalVehicle::is_occupied(int x, int y) {
    return y == 0 && x >= 0 && x < length;
}

void HorizontalVehicle::location_bumped_by_increment(int &x_position, int &y_position) {
    x_position = length;
    y_position = 0;
}

void HorizontalVehicle::location_bumped_by_decrement(int &x_position, int &y_position) {
    x_position = -1;
    y_position = 0;
}


void HorizontalVehicle::range(int &x, int &y) {
    x = length;
    y = 1;
}

//
// actions
//
void HorizontalVehicle::mark_board(vector<vector<char> > &board, int x, int y) {
    for (int i = 0; i < length; ++i) {
        board[y][x + i] = identity;
    }
}

