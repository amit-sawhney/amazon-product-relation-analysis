#pragma once

#include "dfs.h"
#include "node.h"
#include "linear.hpp"

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
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
     * Method that will run Google's Page Rank Algorithm on its own graph.
     * @return the probabilities of each of the nodes
     * O(n ^ 2) Time. 
     */
    vector<double> PageRank() const;

    /**
     * Method for PageRank but uses a sparse matrix to save space and time.
     */
    vector<double> SparsePageRank() const;

    /**
     * Helper Method for PageRank that will create the Google Page Rank Matrix.
     * The influence of each page is split evenly between the pages it links to. We should divide each row entry by the total column sum.
     * If a node has no outgoing edges, there is an equal probability of going to any other edge then.
     * To arrive at a unique solution we will do "M = 0.85 A + (0.15 / n) One"  --  One is a matrix of size n x n where every entry is 1.
     * O(n ^ 2) Time.
     */
    Matrix createGoogleMatrix() const;

    /** 
     * Helper Method for PageRank but uses a sparse matrix to save space and time.
     */
    SparseMatrix createSparseGoogle() const;

    void BetweennessCentrality() const;

    /** 
     * Method that will return a string of the adjacency list. 
     * O(m) Time.
     */
    string outputEdges() const;
    string outputTraversalOrder() const;

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

    /**
     * Method that will save the probabilities of each Rank into a file.
     * @param probabilities the importance score for each node.
     */
    void savePageRank(const vector<double> &probabilities) const;
};
