#ifndef DJKS_DIJKSTRA_H
#define DJKS_DIJKSTRA_H

#include <queue>
#include <unordered_map>
#include <algorithm>
#include "Graph/Graph.h"
#include "Problem/Instance.h"
#include "Problem/Solution.h"

class Dijkstra {
public:
    // Mapeia cada vértice a sua distância mais curta conhecida do vértice de origem.
    using DistanceMap = std::unordered_map<Graph::Vertex, Graph::Weight>;

    // Mapeia cada vértice ao seu predecessor no caminho mais curto do vértice de origem.
    using PredecessorMap = std::unordered_map<Graph::Vertex, Graph::Vertex>;

    // Uma fila de prioridade que armazena pares de peso e vértice, usada para determinar o próximo vértice a ser processado.
    // O peso é a chave para a prioridade, com os menores pesos tendo a maior prioridade.
    using Heap = std::priority_queue<std::pair<Graph::Weight, Graph::Vertex>,
            std::vector<std::pair<Graph::Weight, Graph::Vertex>>,
            std::greater<>>;

    // Resolve a instância do problema usando o algoritmo de Dijkstra.
    static Problem::Solution Solve(const Problem::Instance &instance);

private:
    static Problem::Solution BuildSolution(Graph::Vertex start, Graph::Vertex destination,
                                           const DistanceMap &distances,
                                           const PredecessorMap &predecessors);
};


#endif //DJKS_DIJKSTRA_H
