#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../catch/catch.hpp"
#include "../src/graph.h"
#include "../src/linear.hpp"
#include "../src/node.h"

using namespace std;

TEST_CASE("The Makefile executes properly", "[compilation-check]") {
  REQUIRE(true);
}

// Beginning of Parsing the Graph Tests
TEST_CASE("Parse Nodes - Connected Directed Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7);
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 2 -> 5\n|5|\n|6|\n");
}

TEST_CASE("Parse Nodes - Connected Undirected Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7);
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n");
}

TEST_CASE("Parse Nodes - Multiple Components Directed Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12);
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 5\n|5|\n|6|\n|7| -> 8\n|8| -> 9\n|9| -> 10\n|10|\n|11|\n");
}

TEST_CASE("Parse Nodes - Multiple Components Undirected Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12);
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n|7| -> 8\n|8| -> 7 -> 9\n|9| -> 8 -> 10\n|10| -> 9\n|11|\n");
}

// Beginning of Counting the Number of Connected Components Tests
TEST_CASE("Number of Connected Components - Connected Directed Graph", "[sprint=1]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7);
  g.DFS();
  REQUIRE(1 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Connected Undirected Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7);
  g.DFS();
  REQUIRE(1 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Multiple Components Directed Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12);
  g.DFS();
  REQUIRE(4 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Multiple Components Undirected Graph", "[sprint=0]") {
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12);
  g.DFS();
  REQUIRE(3 == g.getConnectedComponents());
}

// Beginning of Testing Google Page Rank
TEST_CASE("Google Page Rank Matrix", "[sprint=1]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7);

  vector<vector<double>> expected {{0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.4464285714, 0.0214285714, 0.0214285714, 0.8714285714, 0.0214285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429 }, 
                                   { 0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429 }};
  vector<vector<double>> actual = g.createGoogleMatrix();

  for (size_t i = 0; i < 7; i++) {
    for (size_t j = 0; j < 7; j++) {
      REQUIRE(expected[i][j] == Approx(actual[i][j]));
    }
  }
}

TEST_CASE("Matrix Vector Multiplication", "[sprint=1]") {
  vector<vector<double>> matrix { {1.0, 2, 1}, {1.0, 0, 0}, {3, 2.0, 2} };
  vector<double> vec {1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1, 6} == Linear::getMatrixVectorProduct(matrix, vec));
}

TEST_CASE("2-Norm of Vector", "[sprint=1]") {
  vector<double> vec {1.0, 0.5, 2};
  REQUIRE(5.25 == Linear::getNorm(vec));
}

// Test Page Rank Works
// Test Page Rank Works from different starting vectors?