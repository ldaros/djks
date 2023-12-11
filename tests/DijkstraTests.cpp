#include "catch.hpp"
#include "Graph/Graph.h"
#include "Problem/Instance.h"
#include "Problem/Solution.h"
#include "Solver/Dijkstra.h"

TEST_CASE("Dijkstra algorithm finds the shortest path correctly", "[Dijkstra]") {
    // Configuração do grafo
    Graph g(5); // Grafo com 5 vértices
    g.AddEdge(0, 1, 10);
    g.AddEdge(0, 3, 4);
    g.AddEdge(1, 2, 1);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 4, 2);
    g.AddEdge(3, 1, 3);
    g.AddEdge(3, 2, 1);
    g.AddEdge(3, 4, 6);
    g.AddEdge(4, 0, 7);
    g.AddEdge(4, 2, 6);

    // Configuração da instância do problema
    Problem::Instance instance(g, 0, 4); // De vértice 0 para vértice 4

    // Resolvendo o problema
    Problem::Solution solution = Dijkstra::Solve(instance);

    SECTION("The total weight of the shortest path is correct") {
        REQUIRE(solution.total_weight == 7); // Peso total esperado do caminho mais curto
    }

    SECTION("The path of the shortest path is correct") {
        std::vector<Graph::Vertex> expected_path = {0, 3, 2, 4};
        REQUIRE(solution.path == expected_path); // Caminho esperado
    }
}
