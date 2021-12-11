#pragma once

#include "dfs.h"
#include "node.h"
#include "pagerank.h"
#include "linear.hpp"

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

using namespace std;

typedef vector<list<Node*>> AdjList;
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
     * O(n ^ 2) Time.
     */
    void RunPageRank();

    static bool compareProbabilities(const Node node1, const Node node2);

    void BetweennessCentrality() const;

    /** 
     * Method that will return a string of the adjacency list. 
     * O(m) Time.
     */
    string outputEdges() const;

    AdjList getEdges() const;

    unsigned getConnectedComponents() const;

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
