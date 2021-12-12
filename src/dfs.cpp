#include "dfs.h"

DFS::DFS(AdjList &edges, vector<Node> &nodes)
{
    vector<bool> visited;
    visited.resize(nodes.size(), false);

    // Looping through all the nodes while counting connected components
    connected_components_ = 0;
    for (size_t i = 0; i < nodes.size(); i++) {
        if(!visited[i]) {
            DFSHelper(i, visited, edges, nodes);
            connected_components_++;
        }
    }
}

void DFS::DFSHelper(int id, vector<bool> &visited, AdjList &edges, vector<Node> &nodes) {
    stack<int> futureVisits;
    futureVisits.push(id);
    visited[id] = true;

    // Looping until all neighboring nodes of this component have been visited.
    while (!futureVisits.empty()) {
        int top = futureVisits.top();
        futureVisits.pop();    

        traversal_order_.push_back(&nodes[top]);

        for (Node* neighbor : edges[top]) {
            int neighborId = neighbor->getId();
            if (!visited[neighborId]) {
                visited[neighborId] = true;
                futureVisits.push(neighborId);
            }
        }
    }
}

DFS::Iterator::Iterator(unsigned index, vector<Node*> &traversal_order) {
    if (index >= traversal_order_.size()) {
        current_ = NULL;
    } else {
        current_ = traversal_order_[index];
    }
    index_ = index;
    traversal_order_ = traversal_order;
}

DFS::Iterator DFS::begin() {
    return DFS::Iterator(0, traversal_order_);
}

DFS::Iterator DFS::end() {
    return DFS::Iterator(traversal_order_.size(), traversal_order_);
}

Node* DFS::Iterator::operator*() const {
    if (index_ >= traversal_order_.size()) {
        return NULL;
    }
    return traversal_order_[index_];
}

DFS::Iterator DFS::Iterator::operator++() {
    index_ += 1;
    return DFS::Iterator(index_, traversal_order_);
}

bool DFS::Iterator::operator!=(const Iterator &other) {
    return *(*this) != *other;
}

int DFS::getConnectedComponents() {
    return connected_components_;
}
