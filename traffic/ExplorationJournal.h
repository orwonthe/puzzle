//
// Copyright 2016 by WillyMillsLLC 2/10/16.
//

#ifndef TRAFFIC_EXPLORATIONJOURNAL_H
#define TRAFFIC_EXPLORATIONJOURNAL_H

#include <unordered_map>
#include <string>
using namespace std;


class ExplorationJournal {
protected:
    unordered_map<string, int> explored;
    int max_depth;
public:
    ExplorationJournal();
    void clear();
    bool have_visited(string signature, int metric);

    void insert(string signature, int metric);

    int maximum_depth();
};


#endif //TRAFFIC_EXPLORATIONJOURNAL_H
