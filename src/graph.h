#pragma once

#include "node.h"
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<list<Node*>> AdjList;

class Graph
{

public:
    Graph();

    Graph(AdjList edges, vector<Node> nodes);

    Graph(string filename);

    void DFS() const;

    void PageRank() const;

    void BetweennessCentrality() const;

private:
    AdjList edges_;
    vector<Node> nodes_;

    // Helper Method that creates a node for every vertex in the graph, and puts the node into the vector nodes_.
    void createNodeList();

    /**
     * Method that takes in a file and populates the adjacency list edges_.
     * @param filename is the file with all the edges.
     */
    void parseNodes(string filename);
};
