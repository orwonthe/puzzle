//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_PUZZLESOLVER_H
#define TRAFFIC_PUZZLESOLVER_H

#include <string>

#include "Garage.h"
#include "Solution.h"
#include "ExplorationJournal.h"
#include "BinarySearcher.h"

using namespace std;

class PuzzleSolver {
protected:
    // tools
    BinarySearcher searcher;
    Garage starting_garage;
    Garage current_garage;
    Garage best_garage;
    Solution solution;
    Solution best_solution;
    ExplorationJournal explored;
    vector<char> vehicle_codes;

    // properties
    int verbosity = 0;
    int search_limit;
    bool exhausted = false;
    bool limited = false;

    // actions
    bool solve_it_with_depth_limit();
    bool decrement(char ch);
    bool increment(char ch);
    void undo_decrement(char ch);
    void undo_increment(char ch);
    bool arrangement_is_novel();
    void show_status();
    void reset();
    void full_reset();
    void show_depth();

public:
    PuzzleSolver(Garage &a_garage, int verbose = 0, int high_limit=512);

    // properties
    bool all_moves_exhausted();
    Garage& get_best_garage();
    string get_best_solution();
    long distance();
    long moves();
    long distance_travelled();
    long total_distance_travelled();

    // actions
    bool solve_it();
};


#endif //TRAFFIC_PUZZLESOLVER_H
