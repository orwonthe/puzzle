//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include <iostream>
#include "PuzzleSolver.h"

PuzzleSolver::PuzzleSolver(Garage &a_garage, int verbose, int high_limit) :
        current_garage(a_garage), starting_garage(a_garage), verbosity(verbose), searcher(0, high_limit) {
    vehicle_codes = current_garage.identities();
}

//
// properties
//

bool PuzzleSolver::all_moves_exhausted() {
    return exhausted;
}

Garage &PuzzleSolver::get_best_garage() {
    return best_garage;
}

string PuzzleSolver::get_best_solution() {
    return best_solution.get_solution();
}

long PuzzleSolver::distance() {
    return best_solution.distance();
}

long PuzzleSolver::moves() {
    return best_solution.moves();
}

long PuzzleSolver::distance_travelled() {
    return solution.distance_travelled();
}

long PuzzleSolver::total_distance_travelled() {
    return solution.total_distance_travelled();
}

//
// actions
//
bool PuzzleSolver::solve_it() {
    full_reset();
    if (current_garage.victory()) {
        return true;
    }
    while (searcher.still_looking()) {
        search_limit = searcher.next_guess();
        show_depth();
        reset();
        arrangement_is_novel(); // marks starting arrangement as known.
        if (searcher.report(search_limit, solve_it_with_depth_limit())) {
            // Preserve current result in case we never find a better one.
            best_solution = solution;
            best_garage = current_garage;
        }
    }
    if (searcher.found_the_best_solution()) {
        return true;
    } else if (searcher.reached_failure_limit()) {
        limited = true;
    } else {
        exhausted = true;
    }
    return false;
}

bool PuzzleSolver::solve_it_with_depth_limit() {
    // Check if already solved.
    if (current_garage.victory()) {
        return true;
    }

    // End recursion if we have reached the current limit.
    if (solution.distance() > search_limit) return false;

    show_status();

    // Try moving each vehicle in each of the two directions, recursing from the new position.
    for (char ch : vehicle_codes) {
        if (increment(ch)) {
            if (solve_it_with_depth_limit()) return true;
            undo_increment(ch);
        }
        if (decrement(ch)) {
            if (solve_it_with_depth_limit()) return true;
            undo_decrement(ch);
        }
    }
    return false;
}

bool PuzzleSolver::increment(char ch) {
    // Check if it is possible to move the vehicle in the positive direction.
    if (current_garage.increment(ch)) {
        solution.mark_increment(ch);
        // It is possible, but have we been here before this quickly?
        if (arrangement_is_novel()) {
            // Novel arrangement. Mark it down in the solution and report successful progress
            return true;
        } else {
            // This arrangement has already been explored.
            // Put the vehicle back where it was and report no progress.
            undo_increment(ch);
        }
    }
    return false;
}

bool PuzzleSolver::decrement(char ch) {
    // Check if it is possible to move the vehicle in the negative direction.
    if (current_garage.decrement(ch)) {
        solution.mark_decrement(ch);
        // It is possible, but have we been here before this quickly?
        if (arrangement_is_novel()) {
            // Novel arrangement. Mark it down in the solution and report successful progress
            return true;
        } else {
            // This arrangement has already been explored.
            // Put the vehicle back where it was and report no progress.
            undo_decrement(ch);
        }
    }
    return false;
}

void PuzzleSolver::undo_increment(char ch) {
    solution.unmark();
    current_garage.decrement(ch);
}

void PuzzleSolver::undo_decrement(char ch) {
    solution.unmark();
    current_garage.increment(ch);
}

bool PuzzleSolver::arrangement_is_novel() {
    // Arrangement is novel if this is the shortest path to the arrangement we have found so far.

    // get a signature as a key to the visitation table.
    string signature = current_garage.signature();

    // Get the measure of how far we travelled to get to this arrangement.
    int metric = solution.distance();

    if (explored.have_visited(signature, metric)) {
        return false;
    } else {
        explored.insert(signature, metric);
        return true;
    }
}

void PuzzleSolver::full_reset() {
    solution.full_reset();
    reset();
}

void PuzzleSolver::reset() {
    current_garage = starting_garage;
    solution.reset();
    explored.clear();
}

void PuzzleSolver::show_depth() {
    if (verbosity) {
        cout << "depth=" << search_limit << endl;
    }
}

void PuzzleSolver::show_status() {
    if (verbosity > 1) {
        cout << "[" << current_garage.signature() << "] = " << solution.get_solution() << endl;
    }
}


