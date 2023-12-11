#include "Graph.h"
#include <limits>

const int Graph::kInfinity = std::numeric_limits<int>::max();

Graph::Graph(Graph::Vertex num_vertices) :
        adjacency_matrix_(num_vertices, std::vector<Weight>(num_vertices, kInfinity)) {
    for (Vertex v = 0; v < num_vertices; ++v) {
        adjacency_matrix_[v][v] = 0; // Peso zero para a própria aresta
    }
}

void Graph::AddEdge(Graph::Vertex source, Graph::Vertex target, Graph::Weight weight) {
    adjacency_matrix_[source][target] = weight;
}

const Graph::AdjacencyMatrix &Graph::GetAdjacencyMatrix() const {
    return adjacency_matrix_;
}
