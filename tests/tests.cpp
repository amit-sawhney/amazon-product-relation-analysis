#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../catch/catch.hpp"
#include "../src/graph.h"
#include "../src/node.h"

using namespace std;

TEST_CASE("The Makefile executes properly", "[compilation-check]") {
  REQUIRE(true);
}

TEST_CASE("Parse Nodes - Connected Directed Graph", "[sprint=1]") {
  cout << "HERE" << endl;
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7);
  cout << "HERE2" << endl;
  REQUIRE(true);
}