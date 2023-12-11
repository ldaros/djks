#ifndef DJKS_INSTANCE_H
#define DJKS_INSTANCE_H

#include <utility>
#include "Graph/Graph.h"

namespace Problem {

    struct Instance {
        Graph graph;
        Graph::Vertex start;
        Graph::Vertex destination;

        Instance(Graph g, Graph::Vertex s, Graph::Vertex d)
                : graph(std::move(g)), start(s), destination(d) {}
    };
}

#endif //DJKS_INSTANCE_H
