#include "graph.h"

Graph::Graph() {

}

Graph::Graph(AdjList edges, vector<Node> nodes) {
    edges_ = edges;
    nodes_ = nodes;
}

Graph::Graph(string filename) {
    parseNodes(filename);
}

void Graph::BetweennessCentrality() const {

}

void Graph::DFS() const {

}

void Graph::PageRank() const {

}

void Graph::parseNodes(string filename) {
    
}