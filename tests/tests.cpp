#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../catch/catch.hpp"
#include "../src/graph.h"
#include "../src/linear.hpp"
#include "../src/node.h"

using namespace std;
typedef tuple<unsigned, double> entry;

// Beginning of Parsing the Graph Tests
TEST_CASE("Parse Nodes - Connected Directed Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 2 -> 5\n|5|\n|6|\n");
}

TEST_CASE("Parse Nodes - Don't Read Complete File", "[sprint=0]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 4, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1\n|1| -> 3\n|2| -> 0\n|3| -> 1\n");
}

TEST_CASE("Parse Nodes - Connected Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n");
}

TEST_CASE("Parse Nodes - Multiple Components Directed Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 4\n|1| -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 5\n|5|\n|6|\n|7| -> 8\n|8| -> 9\n|9| -> 10\n|10|\n|11|\n");
}

TEST_CASE("Parse Nodes - Multiple Components Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12, "");
  string adjacencyList = g.outputEdges();
  REQUIRE(adjacencyList == "|0| -> 1 -> 2 -> 4\n|1| -> 0 -> 3 -> 6\n|2| -> 0 -> 5\n|3| -> 1\n|4| -> 0 -> 5\n|5| -> 2 -> 4\n|6| -> 1\n|7| -> 8\n|8| -> 7 -> 9\n|9| -> 8 -> 10\n|10| -> 9\n|11|\n");
}

// Beginning of Counting the Number of Connected Components Tests
TEST_CASE("Number of Connected Components - Connected Directed Graph", "[sprint=1]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "");
  g.Traversal();
  remove("_Traversal.txt");
  REQUIRE(1 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Connected Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7, "");
  g.Traversal();
  remove("_Traversal.txt");
  REQUIRE(1 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Multiple Components Directed Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "");
  g.Traversal();
  remove("_Traversal.txt");
  REQUIRE(4 == g.getConnectedComponents());
}

TEST_CASE("Number of Connected Components - Multiple Components Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12, "");
  g.Traversal();
  remove("_Traversal.txt");
  REQUIRE(3 == g.getConnectedComponents());
}

// Beginning of Comparing DFS Traversal Order
string readFile(string filename)
{
  ifstream data(filename);
  string line, output;

  if (data.is_open())
  {
    while (getline(data, line))
    {
      output += line + "\n";
    }
  }
  return output;
}

TEST_CASE("DFS Traversal - Connected Directed Graph", "[sprint=1]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 7 nodes with 1 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n" == readFile("Test_Traversal.txt"));
  remove("Test_Traversal.txt");
}

TEST_CASE("DFS Traversals - Connected Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 7 nodes with 1 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n" == readFile("Test_Traversal.txt"));
  remove("Test_Traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Directed Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 12 nodes with 4 Connected Component(s):\n0\n4\n5\n1\n6\n3\n2\n7\n8\n9\n10\n11\n" == readFile("Test_Traversal.txt"));
  remove("Test_Traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Undirected Graph", "[sprint=0]")
{
  Graph g("tests/dummy_data/ComponentsUndirectedGraph.txt", 12, "Test");
  g.Traversal();
  REQUIRE("Path Traversal for 12 nodes with 3 Connected Component(s):\n0\n4\n5\n2\n1\n6\n3\n7\n8\n9\n10\n11\n" == readFile("Test_Traversal.txt"));
  remove("Test_Traversal.txt");
}

// Beginning of Testing Google Page Rank
TEST_CASE("Create Google Page Rank Matrix", "[sprint=1]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");

  vector<vector<double>> expected{{0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.4464285714, 0.0214285714, 0.0214285714, 0.8714285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.0214285714, 0.4464285714, 0.0214285714, 0.4464285714, 0.1428571429, 0.1428571429},
                                  {0.0214285714, 0.4464285714, 0.0214285714, 0.0214285714, 0.0214285714, 0.1428571429, 0.1428571429}};

  // Testing Condensed Matrix
  vector<vector<double>> actual = g.createGoogleMatrix();
  for (size_t i = 0; i < 7; i++)
  {
    for (size_t j = 0; j < 7; j++)
    {
      REQUIRE(expected[i][j] == Approx(actual[i][j]));
    }
  }

  // Testing Sparse Matrix
  vector<list<tuple<unsigned, double>>> sparse = g.createSparseGoogle();
  for (size_t i = 0; i < sparse.size(); i++)
  {
    for (auto tup : sparse[i])
    {
      REQUIRE(expected[i][get<0>(tup)] == Approx(get<1>(tup)));
    }
  }
  remove("Test_Traversal.txt");
}

TEST_CASE("Matrix Vector Multiplication", "[sprint=1]")
{
  vector<vector<double>> matrix{{1.0, 2, 1}, {1.0, 0, 0}, {3, 2.0, 2}};
  vector<double> vec{1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1, 6} == Linear::getMatrixVectorProduct(matrix, vec));
}

TEST_CASE("Sparse Matrix Vector Multiplication", "[sprint=1]")
{
  vector<list<tuple<unsigned, double>>> s_matrix{{entry(0, 1), entry(1, 2), entry(2, 1)},
                                                 {entry(0, 1)},
                                                 {entry(0, 3), entry(1, 2), entry(2, 2)}};
  vector<double> vec{1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1, 6} == Linear::getSparseProduct(s_matrix, vec, 0));
}

TEST_CASE("Sparse Matrix Vector Multiplication with NonZero Sparse Values", "[sprint=1]")
{
  vector<list<tuple<unsigned, double>>> s_matrix{{entry(0, 1), entry(1, 2), entry(2, 1)},
                                                 {entry(0, 1)},
                                                 {entry(0, 3), entry(1, 2), entry(2, 2)}};
  vector<double> vec{1.0, 0.5, 1};
  REQUIRE(vector<double>{3, 1.75, 6} == Linear::getSparseProduct(s_matrix, vec, 0.5));
}

TEST_CASE("2-Norm of Vector", "[sprint=1]")
{
  vector<double> vec{1.0, 0.5, 2};
  REQUIRE(5.25 == Linear::getNorm(vec));
}

// Test Page Rank Works Collectively
TEST_CASE("Page Rank - Connected Graph - Condensed", "[sprint=1]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  vector<double> expected{0.1011466592, 0.2355230408, 0.1011466592, 0.1584395494, 0.1011466592, 0.1441578829, 0.1584395494};
  vector<double> actual = g.PageRank();

  for (size_t i = 0; i < expected.size(); i++)
  {
    REQUIRE(expected[i] == Approx(actual[i]));
  }

  remove("Test_Traversal.txt");
  remove("Test_PageRank.txt");
}

TEST_CASE("Page Rank - Connected Graph - Sparse", "[sprint=1]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  vector<double> expected{0.1011466592, 0.2355230408, 0.1011466592, 0.1584395494, 0.1011466592, 0.1441578829, 0.1584395494};
  vector<double> sparse = g.SparsePageRank();

  for (size_t i = 0; i < expected.size(); i++)
  {
    REQUIRE(expected[i] == Approx(sparse[i]));
  }

  remove("Test_Traversal.txt");
  remove("Test_PageRank.txt");
}

TEST_CASE("Page Rank - Multiple Components Graph - Condensed", "[sprint=1]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  vector<double> expected{0.0557929519, 0.1503073339, 0.0391460521, 0.1031448773, 0.0628697171, 0.1092659075, 0.1031448773, 0.0391460521, 0.0724398517, 0.1007469124, 0.1248494149, 0.0391460521};
  vector<double> actual = g.PageRank();

  for (size_t i = 0; i < expected.size(); i++)
  {
    REQUIRE(expected[i] == Approx(actual[i]));
  }
  remove("Test_Traversal.txt");
  remove("Test_PageRank.txt");
}

TEST_CASE("Page Rank - Multiple Components Graph - Sparse", "[sprint=1]")
{
  Graph g("tests/dummy_data/ComponentsDirectedGraph.txt", 12, "Test");
  vector<double> expected{0.0557929519, 0.1503073339, 0.0391460521, 0.1031448773, 0.0628697171, 0.1092659075, 0.1031448773, 0.0391460521, 0.0724398517, 0.1007469124, 0.1248494149, 0.0391460521};
  vector<double> sparse = g.SparsePageRank();

  for (size_t i = 0; i < expected.size(); i++)
  {
    REQUIRE(expected[i] == Approx(sparse[i]));
  }
  remove("Test_Traversal.txt");
  remove("Test_PageRank.txt");
}

TEST_CASE("Betweenness Centrality", "[dumbo]")
{
  Graph g("tests/dummy_data/ConnectedDirectedGraph.txt", 7, "Test");
  // vector<double> expected{0.1011466592, 0.2355230408, 0.1011466592, 0.1584395494, 0.1011466592, 0.1441578829, 0.1584395494};
  g.BetweennessCentrality();
}