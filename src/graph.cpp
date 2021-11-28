#include "graph.h"

#define NUM_NODES 262111

using namespace std;

Graph::Graph()
{
}

Graph::Graph(AdjList edges, vector<Node> nodes)
{
    edges_ = edges;
    nodes_ = nodes;
}

Graph::Graph(string filename)
{
    parseNodes(filename);
}

void Graph::BetweennessCentrality() const
{
}

void Graph::DFS() const
{
    connectedComponents = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        if(!visited_[i]) {
            dfsHelper(i);
            connectedComponents++;
        }
    }
}

void Graph::dfsHelper(int id) {
    stack<int> stack;

    while (!stack.empty()) {
        int top = stack.top();
        top.pop();    
        visited_[id] = true;

        for (auto neighbor : edges_[id]) {
            int neighborId = neighbor.getId();
            if (!visited[neighborId]) {
                stack.push(neightborId);
            }
        }
    }
}


void Graph::PageRank() const
{
}

void Graph::parseNodes(string filename)
{
    edges_.resize(NUM_NODES);

    ifstream data(filename);
    string edge;
    istringstream edgeStream;
    int from, to;
    if (data.is_open())
    {
        while (getline(data, edge))
        {
            if (edge[0] != '#')
            {
                edgeStream.str(edge);
                edgeStream >> from;
                edgeStream >> to;

                edges_[from].push_back(Node(to));
            }
        }
    }
}