#pragma once

#include "node.h"
#include <vector>
#include <list>
#include <string>

using namespace std;

typedef vector<list<Node>> AdjList;

class Graph {

    public:

        Graph();

        Graph(AdjList edges, vector<Node> nodes_);

        Graph(string filename);

        void DFS() const;

        void PageRank() const;

        void BetweennessCentrality() const;
    
    private:

        AdjList edges_;
        vector<Node> nodes_;

        void parseNodes(string filename);
};
