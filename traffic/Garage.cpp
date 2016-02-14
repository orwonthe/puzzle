//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include <iostream>
#include "Garage.h"

using namespace std;

Garage::Garage(int w, int h) : width(w), height(h) {
}

//
// properties
//
VehiclePlacement &Garage::find(char marking) {
    for (VehiclePlacement &placed_vehicle : vehicles) {
        if (placed_vehicle.identity() == marking) {
            return placed_vehicle;
        }
    }
}


bool Garage::have(char marking) {
    for (VehiclePlacement &placed_vehicle : vehicles) {
        if (placed_vehicle.identity() == marking) {
            return true;
        }
    }
    return false;
}

bool Garage::can_place(VehiclePlacement &vehicle) {
    int x_start;
    int y_start;
    int x_limit;
    int y_limit;
    vehicle.range(x_start, y_start, x_limit, y_limit);
    for (int x=x_start; x < x_limit; x++) {
        for (int y=y_start; y<y_limit; y++) {
            if (is_occupied(x,y)) return false;
        }
    }
    return true;
}

string Garage::signature() {
    string result = "";
    vector<vector<char> > puzzle_board = board();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            result.push_back(puzzle_board[y][x]);
        }
        result.push_back(':');
    }
    return result;
}

vector<vector<char>> Garage::board() {
    vector<vector<char> > a_board = blank_board();
    for (VehiclePlacement &placed_vehicle : vehicles) {
        placed_vehicle.mark_board(a_board);
    }
    return a_board;
}

bool Garage::is_occupied(int x, int y) {
    if (x < 0 || y < 0 || x >= width || y >= height) return true;
    for (VehiclePlacement &placed_vehicle : vehicles) {
        if (placed_vehicle.is_occupied(x, y)) return true;
    }
    return false;
}

vector<char> Garage::identities() {
    vector<char> result;
    for (VehiclePlacement &placed_vehicle : vehicles) {
        result.push_back(placed_vehicle.identity());
    }
    return result;
}

bool Garage::victory() {
    int x = 0;
    int y = 0;
    find('r').location(x, y);
    return x == width - 2;
}

//
// actions
//
vector<vector<char>> Garage::blank_board() {
    vector<vector<char>> board;
    for (int y = 0; y < height; ++y) {
        vector<char> row;
        for (int x = 0; x < width; ++x) {
            row.push_back('+');
        }
        board.push_back(row);
    }
    return board;
}

void Garage::addVehicle(Vehicle &vehicle, int x, int y) {
    if (have(vehicle.marking())) {
        throw std::runtime_error("duplicate vehicle");
    }
    VehiclePlacement placed_vehicle(vehicle, x, y);
    if (can_place(placed_vehicle)) {
        vehicles.push_back(placed_vehicle);
    } else {
        throw std::runtime_error("space already occupied");
    }
}

bool Garage::increment(char marking) {
    // For the given vehicle find out what new location must be empty to move in positive direction.
    VehiclePlacement &target = find(marking);
    int x = 0;
    int y = 0;
    target.location_bumped_by_increment(x, y);

    // Check if this location is available. If so, move there, and report success, otherwise report failure.
    if (is_occupied(x, y)) {
        return false;
    } else {
        target.increment();
        return true;
    }
}

bool Garage::decrement(char marking) {
    // For the given vehicle find out what new location must be empty to move in negative direction.
    VehiclePlacement &target = find(marking);
    int x = 0;
    int y = 0;
    target.location_bumped_by_decrement(x, y);

    // Check if this location is available. If so, move there, and report success, otherwise report failure.
    if (is_occupied(x, y)) {
        return false;
    } else {
        target.decrement();
        return true;
    }
}

void Garage::show() {
    vector<vector<char> > puzzle_board = board();
    show_board(puzzle_board);
}

void Garage::show_board(const vector<vector<char>> &board) {
    show_top();
    for (int y = 0; y < height; ++y) {
        cout << '|';
        for (int x = 0; x < width; ++x) {
            cout << board[y][x];
        }
        if (y == 2) {
            cout << '|' << endl;
        } else {
            cout << '|' << endl;

        }
    }
    show_bottom();
}

void Garage::show_top() {
    cout << '+';
    for (int x = 0; x < width ; x++) {
        cout << '-';
    }
    cout << '+' << endl;

}

void Garage::show_bottom() {
    show_top();
}

void Garage::show_key() {
    cout << "Key:" << endl;
    for (VehiclePlacement &placed_vehicle : vehicles) {
        cout << placed_vehicle.key() << endl;
    }
    cout << "+: empty" << endl;
}

















