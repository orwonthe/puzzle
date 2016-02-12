//
// Created by willy on 2/11/16.
//

#ifndef TRAFFIC_SOLVEANDEXPLAIN_H
#define TRAFFIC_SOLVEANDEXPLAIN_H

#include <iostream>
#include "RushHour.h"
#include "PuzzleSolver.h"


class SolveAndExplain {
protected:
    // Properties
    int _puzzle_number;
    RushHour rush_hour;
    Garage puzzle;
    PuzzleSolver solver;
    clock_t start_time;
    clock_t stop_time;
    bool was_solved;
    double seconds_to_solve();

    // actions
    void solve_it() ;
    void describe_success();
    void describe_failure();
    void describe_result();
    void show_key();
    void show_puzzle(string label);

public:
    SolveAndExplain(int puzzle_number, int verbosity=0);

    // actions
    void go();
};


#endif //TRAFFIC_SOLVEANDEXPLAIN_H
