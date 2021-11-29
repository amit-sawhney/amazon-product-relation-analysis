#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../catch/catch.hpp"
#include "../src/graph.h"
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
