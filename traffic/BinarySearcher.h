//
// Copyright 2016 by WillyMillsLLC 2/11/16.
//

#ifndef TRAFFIC_BINARYSEARCHER_H
#define TRAFFIC_BINARYSEARCHER_H


class BinarySearcher {
protected:
    int low_limit;
    int high_limit;
    int highest_failure;
    int lowest_success;
public:
    BinarySearcher(int low, int high);

    // properties
    int next_guess();
    bool still_looking();
    bool found_the_best_solution();
    bool reached_failure_limit();

    // actions
    bool report(int guess, bool success);
    void report_failure(int guess);
    void report_success(int guess);
};


#endif //TRAFFIC_BINARYSEARCHER_H
