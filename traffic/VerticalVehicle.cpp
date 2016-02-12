//
// Copyright 2016 by WillyMillsLLC
//

#include "VerticalVehicle.h"

VerticalVehicle::VerticalVehicle(char marking, int len, string colour) : Vehicle(marking, len, true, colour){
}

void VerticalVehicle::mark_board(vector<vector<char> > &board, int x, int y) {
    for (int i = 0; i < length; ++i) {
        board[y + i][x] = identity;
    }
}

bool VerticalVehicle::is_occupied(int x, int y) {
    return x == 0 && y >= 0 && y < length;
}

void VerticalVehicle::location_bumped_by_increment(int &x_position, int &y_position) {
    x_position = 0;
    y_position = length;
}

void VerticalVehicle::location_bumped_by_decrement(int &x_position, int &y_position) {
    x_position = 0;
    y_position = -1;
}
