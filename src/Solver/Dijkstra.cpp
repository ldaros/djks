#include <vector>
#include <queue>
#include <unordered_map>
#include "Dijkstra.h"
#include "Graph/Graph.h"
#include "Problem/Instance.h"
#include "Problem/Solution.h"

Problem::Solution Dijkstra::Solve(const Problem::Instance &instance) {
    const auto &graph = instance.graph;
    DistanceMap distances;
    PredecessorMap predecessors;
    Heap min_heap;

    const auto &adj_matrix = graph.GetAdjacencyMatrix();
    Graph::Vertex num_vertices = adj_matrix.size();

    // Inicializando as estruturas
    for (Graph::Vertex v = 0; v < num_vertices; ++v) {
        distances[v] = Graph::kInfinity;
    }
    distances[instance.start] = 0;
    min_heap.push({0, instance.start});

    // Algoritmo de Dijkstra
    while (!min_heap.empty()) {
        auto [dist, vertex] = min_heap.top();
        min_heap.pop();

        if (dist > distances[vertex]) continue;

        for (Graph::Vertex v = 0; v < num_vertices; ++v) {
            if (adj_matrix[vertex][v] != Graph::kInfinity) {
                Graph::Weight new_dist = dist + adj_matrix[vertex][v];
                if (new_dist < distances[v]) {
                    distances[v] = new_dist;
                    predecessors[v] = vertex;
                    min_heap.push({new_dist, v});
                }
            }
        }
    }

    // Reconstruindo o caminho
    return BuildSolution(instance.start, instance.destination, distances, predecessors);
}

Problem::Solution Dijkstra::BuildSolution(Graph::Vertex start, Graph::Vertex destination,
                                          const DistanceMap &distances,
                                          const PredecessorMap &predecessors) {
    std::vector<Graph::Vertex> path;
    for (Graph::Vertex v = destination; v != start; v = predecessors.at(v)) {
        path.push_back(v);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return Problem::Solution(path, distances.at(destination));
}
