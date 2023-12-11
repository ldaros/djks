#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Graph/Graph.h"

TEST_CASE("Graph edges are added and retrieved correctly", "[Graph]") {
    const Graph::Vertex num_vertices = 5;
    Graph g(num_vertices);

    // Adicionando arestas ao grafo
    g.AddEdge(0, 1, 3); // Aresta do vértice 0 para o vértice 1 com peso 3
    g.AddEdge(0, 2, 4); // Aresta do vértice 0 para o vértice 2 com peso 4

    // Obtendo a matriz de adjacências
    const auto &adj_matrix = g.GetAdjacencyMatrix();

    SECTION("Edge weights are correct in the adjacency matrix") {
        REQUIRE(adj_matrix[0][1] == 3); // Verifica o peso da aresta de 0 para 1
        REQUIRE(adj_matrix[0][2] == 4); // Verifica o peso da aresta de 0 para 2
    }

    SECTION("Nonexistent edges have infinite weight") {
        REQUIRE(adj_matrix[1][0] == Graph::kInfinity); // Verifica a ausência de aresta de 1 para 0
        REQUIRE(adj_matrix[2][1] == Graph::kInfinity); // Verifica a ausência de aresta de 2 para 1
    }

    SECTION("Self-edges have zero weight") {
        for (Graph::Vertex v = 0; v < num_vertices; ++v) {
            REQUIRE(adj_matrix[v][v] == 0); // Verifica que cada vértice tem peso zero para si mesmo
        }
    }
}
