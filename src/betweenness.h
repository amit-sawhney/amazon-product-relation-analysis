#pragma once

#include <map>
#include "node.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>

using namespace std;

typedef vector<list<Node *>> AdjList;

class Betweenness
{
public:
    Betweenness();
    Betweenness(vector<Node> *nodes, AdjList *adjacency);

    // Edit nodes to add betweenness centrality values
    void calculateBetweenness();

private:
    stack<Node *> node_stack_;
    map<Node *, list<Node *>> predecessors_;
    map<Node *, double> sigma_;
    map<Node *, double> betweenness_;
    vector<Node> *nodes_;
    AdjList *adjacency_;

    void accumulateNodes(Node *node);
    void shortestPathCalculation(Node *node);
};