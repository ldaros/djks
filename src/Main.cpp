#include <iostream>
#include <chrono>

#include "Graph/Graph.h"
#include "Solver/Dijkstra.h"
#include "Problem/Instance.h"

int main() {
    // Inicializando o grafo
    Graph graph(5);
    graph.AddEdge(0, 1, 1);
    graph.AddEdge(0, 2, 2);
    graph.AddEdge(1, 2, 3);
    graph.AddEdge(1, 3, 4);
    graph.AddEdge(2, 3, 5);
    graph.AddEdge(2, 4, 6);
    graph.AddEdge(3, 4, 7);

    // Inicializando a instância
    Problem::Instance instance(graph, 0, 4);

    // Resolvendo a instância
    auto start = std::chrono::high_resolution_clock::now();
    auto solution = Dijkstra::Solve(instance);
    auto end = std::chrono::high_resolution_clock::now();

    // Imprimindo a solução
    std::cout << "Caminho: ";
    for (const auto &vertex: solution.path) {
        std::cout << vertex << (vertex == solution.path.back() ? "" : " -> ");
    }
    std::cout << "\nDistância: " << solution.total_weight << "\n";

    // Imprimindo o tempo de execução
    std::cout << "Tempo de execução: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
              << " ns\n";


    return EXIT_SUCCESS;
}
