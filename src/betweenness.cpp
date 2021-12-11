#include "betweenness.h"

// Betweenness::Betweenness() {}

Betweenness::Betweenness(const vector<Node>& nodes, const AdjList& adjacency) {
    nodes_ = nodes;
    adjacency_ = adjacency;
}

map<Node*, double> calculateBetweenness() {
    return betweenness_values_;
}

void accumulateNodes(Node* node) {
    map<Node*, double> delta = {};

    while (!node_stack_.empty()) {
        Node* next_node = node_stack_.top();
        node_stack_.pop();

        double coeff = (1 + delta[next_node]) / sigma[next_node];
        for(auto vertex: predecessors_) {
            delta[next_node] = delta[next_node] + sigma_[vertex] * coeff;
        }

        if (next_node != node) {
            betweenness_values_[next_node] = betweenness_values_[next_node] + delta[next_node];
        }
    }
}

void shortestPathCaculation(Node* node) {

}
