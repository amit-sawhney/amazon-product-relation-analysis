#include "dfs.h"


// DFS::DFS(AdjList &edges, vector<Node> &nodes)
DFS::DFS()
{
    // vector<bool> visited;
    // visited.resize(nodes.size(), false);

    // connected_components_ = 0;
    // for (size_t i = 0; i < nodes.size(); i++) {
    //     if(!visited[i]) {
    //         DFSHelper(i, visited, edges, nodes);
    //         connected_components_++;
    //     }
    // }
    // cout << "Number of Components: " << connected_components_ << endl;
}

void DFS::DFSHelper(int id, vector<bool> &visited, const AdjList &edges, const vector<Node> &nodes) {
    stack<int> futureVisits;
    futureVisits.push(id);
    visited[id] = true;

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

// string DFS::outputTraversalOrder() const {
//     string output;

//     for (auto node: traversal_order_) {
//         output += to_string(node -> getId()) + '\n'; 
//     }
//     return output;
// }

// DFS::Iterator::Iterator(unsigned index) {
//     if (index >= traversal_order_.size()) {
//         current_ = NULL;
//     } else {
//         current_ = traversal_order[index];
//     }
//     index_ = index;
// }

// DFS::Iterator DFS::begin() {
//     return Iterator(0);
// }

// DFS::Iterator DFS::end() {
//     return Iterator(traversal_order.size());
// }

// Node* DFS::Iterator::operator*() {
//     return traversal_order[index];
// }

// void DFS::Iterator::operator++() {
//     return Iterator(index + 1);
// }

// bool DFS::operator!=(const Iterator &other) {
//     return this.index == other.index;
// }