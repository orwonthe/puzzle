//
// Copyright 2016 WillyMillsLLC 2/11/16.
//

#include "BinarySearcher.h"

BinarySearcher::BinarySearcher(int low, int high) : low_limit(low), high_limit(high) {
    highest_failure = -1;
    lowest_success = high_limit + 1;
}

//
// properties
//
int BinarySearcher::next_guess() {
    if (lowest_success <= high_limit) {
        return (lowest_success + highest_failure) / 2;
    } else {
        int delta = highest_failure - low_limit;
        if (delta < 0) {
            delta = 0;
        } else if (delta == 0) {
            delta = 1;
        } else {
            delta *= 2;
        }
        int result = low_limit + delta;
        if (result > high_limit) {
            result = high_limit;
        }
        return result;
    }
}

bool BinarySearcher::still_looking() {
    return !found_the_best_solution() && !reached_failure_limit();
}

bool BinarySearcher::found_the_best_solution() {
    return lowest_success - highest_failure == 1;
}

bool BinarySearcher::reached_failure_limit() {
    return highest_failure >= high_limit;
}

//
// actions
//
bool BinarySearcher::report(int guess, bool success) {
    if (success) {
        report_success(guess);
    } else {
        report_failure(guess);
    }
    return success;
}

void BinarySearcher::report_failure(int guess) {
    if (guess > highest_failure) {
        highest_failure = guess;
    }
}

void BinarySearcher::report_success(int guess) {
    if (guess < lowest_success) {
        lowest_success = guess;
    }
}
