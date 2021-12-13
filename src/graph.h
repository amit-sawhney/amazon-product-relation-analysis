#pragma once

#include "dfs.h"
#include "node.h"
#include "pagerank.h"
#include "linear.hpp"
#include "betweenness.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<list<Node *>> AdjList;
typedef vector<vector<double>> Matrix;
typedef vector<list<tuple<unsigned, double>>> SparseMatrix;

class Graph
{

public:
    Graph();

    Graph(AdjList edges, vector<Node> nodes, string name);

    Graph(string filename, size_t num_nodes, string name);

    /**
     * Method that will run a DFS Traversal on the graph and count the number of connected components.
     * O(n + m) Time.
     * Possibly Output Path/Create Iterator.
     */
    void Traversal();

    /**
     * Method that will run Google's Page Rank Algorithm on its own graph, saving it to a deliverable.
     * Worst Case - O(n ^ 2) Time. 
     * Best Case - O(E) Time.
     */
    void RunPageRank();

    // Helper Method to Sort the Nodes by Page Rank Probability Scores
    static bool compareProbabilities(const Node node1, const Node node2);

    // Helper Method to Sort the Nodes by Betweenness Score
    static bool compareBetweenness(const Node node1, const Node node2);

    /**
     * Method that will create a Betweenness Object and the calculate the betweenness score for each of the node objects. 
     * @return map from the node pointer to its betweenness score.
     * O(VE) Time
     */
    map<Node*, double> BetweennessCentrality() const;

    /**
     * Method that will output the traversal order, PageRank Importance Score, and the Betweenness Value in One File.
     */
    void saveAnalysis();

    /**
     * Method that will return a string of the adjacency list.
     * O(m) Time.
     */
    string outputEdges() const;

    AdjList getEdges() const;

private:
    unsigned num_nodes_;
    unsigned connected_components_;

    AdjList edges_;
    vector<Node> nodes_;
    string name_;

    /**
     * Helper Method that creates a node for every vertex in the graph, and puts the node into the vector nodes_.
     * O(n) Time.
     */
    void createNodeList();

    /**
     * Method that takes in a file and populates the adjacency list edges_.
     * O(m) Time.
     * @param filename is the file with all the edges.
     */
    void parseNodes(string filename);
};
