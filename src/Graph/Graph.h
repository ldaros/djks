#ifndef DJKS_GRAPH_H
#define DJKS_GRAPH_H

#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    using Vertex = int;
    using Weight = int;
    using AdjacencyMatrix = std::vector<std::vector<Weight>>;
    const static Weight kInfinity;

    explicit Graph(Vertex num_vertices);

    // Adiciona uma aresta direcionada ao grafo.
    void AddEdge(Vertex source, Vertex target, Weight weight);

    // Obtém a matriz de adjacências.
    const AdjacencyMatrix &GetAdjacencyMatrix() const;

private:
    AdjacencyMatrix adjacency_matrix_;
};

#endif //DJKS_GRAPH_H
