#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../catch/catch.hpp"
#include "../src/graph.h"
#include "../src/linear.hpp"
#include "../src/node.h"
#include "../src/pagerank.h"

using namespace std;
typedef tuple<unsigned, double> entry;

// Beginning of Parsing the Graph Tests
TEST_CASE("Parse Nodes - Connected Directed Graph", "[parse]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 2 -> 5\n|5|\n|6|\n");
}

TEST_CASE("Parse Nodes - Don't Read Complete File", "[parse]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 4, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1\n|1| -> 3\n|2| -> 0\n|3| -> 1\n");
}

TEST_CASE("Parse Nodes - Connected Undirected Graph", "[parse]") {
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n");
}

TEST_CASE("Parse Nodes - Multiple Components Directed Graph", "[parse]") {
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 5\n|5|\n|6|\n|7| -> 8\n|8| -> 9\n|9| -> 10\n|10|\n|11|\n");
}

TEST_CASE("Parse Nodes - Multiple Components Undirected Graph", "[parse]") {
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n|7| -> 8\n|8| -> 7 -> 9\n|9| -> 8 -> 10\n|10| -> 9\n|11|\n");
}

// Beginning of Comparing DFS Traversal Order
string readFile(string filename)
{
    ifstream data("deliverables/" + filename);
    string line, output;

    if (data.is_open()) {
        while (getline(data, line))
        {
          output += line + "\n";
        }
    } 
  return output;
}

TEST_CASE("DFS Traversal - Connected Directed Graph", "[dfs]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 7 nodes with 1 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n" == readFile("Test_Traversal.txt"));
  remove("deliverables/Test_Traversal.txt");
}

TEST_CASE("DFS Traversal - Connected Undirected Graph", "[dfs]") {
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 7 nodes with 1 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n" == readFile("Test_Traversal.txt"));
  remove("deliverables/Test_Traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Directed Graph", "[dfs]") {
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 12 nodes with 4 Connected Component(s):\n0\n4\n5\n1\n6\n3\n2\n7\n8\n9\n10\n11\n" == readFile("Test_Traversal.txt"));
  remove("deliverables/Test_Traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Undirected Graph", "[dfs]") {
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 12 nodes with 3 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n7\n8\n9\n10\n11\n" == readFile("Test_Traversal.txt"));
  remove("deliverables/Test_Traversal.txt");
}

// Beginning of Testing Google Page Rank
TEST_CASE("Create Google Page Rank Matrix", "[pagerank]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  PageRank pg = PageRank(g.getEdges());

  vector<vector<double>> expected{{0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.4464285714, 0.0214285714, 0.0214285714, 0.8714285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429}};

  // Testing Condensed Matrix
  vector<vector<double>> actual = pg.createGoogleMatrix();
  for (size_t i = 0; i < 7; i++) {
    for (size_t j = 0; j < 7; j++) {
      REQUIRE(expected[i][j] == Approx(actual[i][j]));
    }
  }

  // Testing Sparse Matrix
  vector<list<tuple<unsigned, double>>> sparse = pg.createSparseGoogle();
  for (size_t i = 0; i < sparse.size(); i++) {
    for (auto tup : sparse[i]) {
      REQUIRE(expected[i][get<0>(tup)] == Approx(get<1>(tup)));
    }
  }
  remove("deliverables/Test_Traversal.txt");
}

TEST_CASE("Matrix Vector Multiplication", "[pagerank]") {
  vector<vector<double>> matrix { {1.0, 2, 1}, {1.0, 0, 0}, {3, 2.0, 2} };
  vector<double> vec {1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1, 6} == Linear::getMatrixVectorProduct(matrix, vec));
}

TEST_CASE("Sparse Matrix Vector Multiplication", "[pagerank]") {
  vector<list<tuple<unsigned, double>>> s_matrix { {entry(0, 1), entry(1, 2), entry(2, 1)}, 
                                                  {entry(0, 1)}, 
                                                  {entry(0, 3), entry(1, 2), entry(2, 2)}};
  vector<double> vec {1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1, 6} == Linear::getSparseProduct(s_matrix, vec, 0));
}

TEST_CASE("Sparse Matrix Vector Multiplication with NonZero Sparse Values", "[pagerank]") {
  vector<list<tuple<unsigned, double>>> s_matrix { {entry(0, 1), entry(1, 2), entry(2, 1)}, 
                                                  {entry(0, 1)}, 
                                                  {entry(0, 3), entry(1, 2), entry(2, 2)}};
  vector<double> vec {1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1.75, 6} == Linear::getSparseProduct(s_matrix, vec, 0.5));
}

TEST_CASE("2-Norm of Vector", "[pagerank]") {
  vector<double> vec {1.0, 0.5, 2};
  REQUIRE(5.25 == Linear::getNorm(vec));
}

// Test Page Rank Works Collectively
TEST_CASE("Page Rank - Connected Graph", "[pagerank]") {
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  PageRank pg = PageRank(g.getEdges());

  vector<double> expected {0.1011466592, 0.2355230408, 0.1011466592, 0.1584395494, 0.1011466592, 0.1441578829, 0.1584395494};
  vector<double> probabilities = pg.createProbabilities();

  for (size_t i = 0; i < expected.size(); i++) {
      REQUIRE(expected[i] == Approx(probabilities[i]));
  }

  remove("deliverables/Test_Traversal.txt");
  remove("deliverables/Test_PageRank.txt");
}

TEST_CASE("Page Rank - Multiple Components Graph", "[pagerank]") {
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  PageRank pg = PageRank(g.getEdges());

  vector<double> expected {0.0557929519, 0.1503073339, 0.0391460521, 0.1031448773, 0.0628697171, 0.1092659075, 0.1031448773, 0.0391460521, 0.0724398517, 0.1007469124, 0.1248494149, 0.0391460521 };
  vector<double> probabilities = pg.createProbabilities();

  for (size_t i = 0; i < expected.size(); i++) {
      REQUIRE(expected[i] == Approx(probabilities[i]));
  }

  remove("deliverables/Test_Traversal.txt");
  remove("deliverables/Test_PageRank.txt");
}

TEST_CASE("Betweenness Centrality - Directed One Component", "[betweenness]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  vector<double> expected({7.0, 7.0, 4.0, 0.0, 2.0, 0.0, 0.0});
  auto output = g.BetweennessCentrality();
  for (auto num : output) {
    REQUIRE(expected[num.first -> getId()] == num.second);
  }
}

TEST_CASE("Betweenness Centrality - Directed Multiple Components Graph", "[betweenness]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  vector<double> expected({4, 5, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0});
  auto output = g.BetweennessCentrality();
  for (auto num : output) {
    REQUIRE(expected[num.first -> getId()] == num.second);
  }

}