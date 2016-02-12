//
// Copyright 2016 by WillyMillsLLC 2/10/16.
//

#include "ExplorationJournal.h"

ExplorationJournal::ExplorationJournal() {
    max_depth = 0;
}


void ExplorationJournal::clear() {
    explored.clear();
    max_depth = 0;
}

bool ExplorationJournal::have_visited(string signature, int metric) {
    return explored.count(signature) && explored[signature] <= metric;
}

void ExplorationJournal::insert(string signature, int metric) {
    explored[signature] = metric;
    if (metric > max_depth) {
        max_depth = metric;
    }
}

int ExplorationJournal::maximum_depth() {
    return max_depth;
}
