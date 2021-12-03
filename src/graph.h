#pragma once

#include "node.h"
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

typedef vector<list<Node*>> AdjList;

class Graph
{

public:
    Graph();

    Graph(AdjList edges, vector<Node> nodes);

    Graph(string filename, size_t num_nodes);

    /**
     * Method that will run a DFS Traversal on the graph and count the number of connected components.
     * O(n + m) Time.
     */
    void DFS();

    void PageRank() const;

    void BetweennessCentrality() const;

    /** 
     * Method that will return a string of the adjacency list. 
     * O(m) Time.
     */
    string outputEdges() const;

    unsigned getConnectedComponents() const;

private:
    unsigned num_nodes_;
    unsigned connected_components_;

    AdjList edges_;
    vector<Node> nodes_;

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
     * Helper Method for DFS Traversal that visits the neighboring edges of the specified id.
     * O(n + m) Time.
     */
    void DFSHelper(int id, vector<bool> &visited);
};
