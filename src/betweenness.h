#pragma once

#include <map>
#include "node.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

typedef vector<list<Node *>> AdjList;

class Betweenness
{
public:
    /**
     * @brief Construct a new Betweenness object using vector of nodes and adjacency list.
     * 
     * @param nodes 
     * @param adjacency 
     */
    Betweenness(const vector<Node> &nodes, const AdjList &adjacency);

    /**
     * @brief Calculates betweenness centrality for given nodes and adjacency list.
     * 
     * @return map<Node *, double> 
     */
    map<Node *, double> calculateBetweenness();

private:
    stack<Node *> node_stack_;
    map<Node *, vector<Node *>> predecessors_;
    map<Node *, double> sigma_;
    map<Node *, double> betweenness_values_;
    vector<Node> nodes_;
    AdjList adjacency_;

    /**
     * @brief Helper method to calculate accumulated scores for betweenness centrality.
     * 
     * @param node Node for which betweenness centrality is being calculated.
     */
    void accumulateNodes(Node *node);

    /**
     * @brief Calculates shortest path between node given to all other nodes.
     * 
     * @param node Node from which distances are calculated and stored in member variables.
     */
    void shortestPathCalculation(Node *node);
};