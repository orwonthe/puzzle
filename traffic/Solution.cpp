//
// Created by Willy Mills on 2/5/16.
//

#include "Solution.h"

//
// properties
//
string Solution::get_solution() {
    string result = "";
    char prior_char = '.';
    bool is_ident = true;
    for (char ch  :  solution) {
        // Suppress the marking character if same vehicle is moved multiple times.
        if (is_ident) {
            if (ch != prior_char) {
                result.push_back(ch);
            }
            prior_char = ch;
        } else {
            result.push_back(ch);
        }
        is_ident = !is_ident;
    }
    return result;
}

int Solution::distance() {
    return (int) solution.size() / 2;
}

int Solution::moves() {
    return move_depth;
}

long Solution::distance_travelled() {
    return _distance_travelled;
}

long Solution::total_distance_travelled() {
    return _total_distance_travelled;
}

//
// actions
//
void Solution::reset() {
    _distance_travelled = 0;
    move_depth = 0;
    solution.clear();
}

void Solution::full_reset() {
    reset();
    _total_distance_travelled = 0;
}

void Solution::mark_decrement(char marking) {
    solution.push_back(marking);
    solution.push_back('-');
    count_move();
}

void Solution::mark_increment(char marking) {
    solution.push_back(marking);
    solution.push_back('+');
    count_move();
}

void Solution::unmark() {
    uncount_move();
    solution.pop_back();
    solution.pop_back();
}

void Solution::count_move() {
    change_move(+1);
}

void Solution::uncount_move() {
    change_move(-1);
}

void Solution::change_move(int direction) {
    _distance_travelled++;
    _total_distance_travelled++;
    int  len = (int) solution.size();
    // Moving the same vehicle multiple times in a row counts as single move.
    if (len < 4 || solution[len - 2] != solution[len - 4] || solution[len - 1] != solution[len - 3]) {
        move_depth += direction;
    }
}

