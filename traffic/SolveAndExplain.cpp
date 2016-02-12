//
// Created by willy on 2/11/16.
//

#include "SolveAndExplain.h"

SolveAndExplain::SolveAndExplain(int puzzle_number, int verbosity) :
        puzzle(rush_hour.create_puzzle(puzzle_number)),
        solver(puzzle, verbosity),
        _puzzle_number(puzzle_number) {
}

//
// properties
//
double SolveAndExplain::seconds_to_solve() {
    return double(stop_time - start_time) / (double) CLOCKS_PER_SEC;
}

//
// actions
//
void SolveAndExplain::go() {
    cout << "Puzzle Number " << _puzzle_number << endl;
    show_key();
    show_puzzle("Starting Point:");
    solve_it();
    describe_result();
    show_puzzle("Ending Point:");
}

void SolveAndExplain::show_key() {
    puzzle.show_key();
    cout << endl;
}

void SolveAndExplain::show_puzzle(string label) {
    cout << label << endl;
    puzzle.show();
    cout << endl;
}

void SolveAndExplain::solve_it() {
    start_time = clock();
    was_solved = solver.solve_it();
    if(was_solved) {
        puzzle = solver.get_best_garage();
    }
    stop_time = clock();
}

void SolveAndExplain::describe_result() {
    if (was_solved) {
        describe_success();
    } else {
        describe_failure();
    }
    cout << "Travelled " << solver.total_distance_travelled() << " total steps." << endl;
    cout << "Travelled " << solver.distance_travelled() << " steps in final round." << endl;
    cout << "Time spent was " << seconds_to_solve() << " seconds." << endl;
    cout << endl;
};

void SolveAndExplain::describe_success() {
    cout << solver.distance() << " step solution is " << solver.get_best_solution() << endl;
    cout << solver.moves() << " moves" << endl;
}

void SolveAndExplain::describe_failure() {
    if (solver.all_moves_exhausted()) {
        cout << "Gave up, all moves exhausted." << endl;
    } else {
        cout << "Gave up, reached the depth limit." << endl;
    }
}


