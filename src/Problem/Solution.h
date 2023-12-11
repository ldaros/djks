#ifndef DJKS_SOLUTION_H
#define DJKS_SOLUTION_H

#include <vector>
#include "Graph/Graph.h"

namespace Problem {

    struct Solution {
        std::vector<Graph::Vertex> path;
        Graph::Weight total_weight;

        Solution(const std::vector<Graph::Vertex> &p, Graph::Weight w)
                : path(p), total_weight(w) {}
    };
}

#endif //DJKS_SOLUTION_H
