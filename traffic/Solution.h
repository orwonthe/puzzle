//
// Created by Willy Mills
//

#ifndef TRAFFIC_SOLUTION_H
#define TRAFFIC_SOLUTION_H

#include <vector>
#include <string>

using namespace std;

class Solution {
protected:
    vector<char> solution;
    int move_depth = 0;
    long _distance_travelled = 0;
    long _total_distance_travelled = 0;

    // actions
    void count_move();
    void uncount_move();
    void change_move(int direction);

public:
    // properties
    string get_solution();
    int distance();
    int moves();
    long distance_travelled();
    long total_distance_travelled();

    // actions
    void reset();
    void full_reset();
    void mark_decrement(char marking);
    void mark_increment(char marking);
    void unmark();
};


#endif //TRAFFIC_SOLUTION_H
