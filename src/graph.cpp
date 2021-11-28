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
}

void Graph::PageRank() const
{
}

void Graph::createNodeList() 
{
    nodes_.resize(NUM_NODES, NULL);
    for (size_t i = 0; i < NUM_NODES; i++) {
        nodes_[0] = Node(i);
    }
}

void Graph::parseNodes(string filename)
{
    createNodeList();
    edges_.resize(NUM_NODES);

    ifstream data(filename);
    string edge;
    istringstream edgeStream;

    int from, to;
    if (data.is_open())
    {
        while (getline(data, edge))
        {
            if (edge[0] != '#') // Ignore Comments from input file
            {
                edgeStream.str(edge);
                edgeStream >> from;
                edgeStream >> to;

                edges_[from].push_back(&nodes_[to]);
            }
        }
    }
}