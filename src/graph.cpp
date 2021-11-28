#include "graph.h"

Graph::Graph()
{
    num_nodes_ = 0;
}

Graph::Graph(AdjList edges, vector<Node> nodes)
{
    edges_ = edges;
    nodes_ = nodes;
    num_nodes_ = nodes_.size();
}

Graph::Graph(string filename, size_t num_nodes)
{
    num_nodes_ = num_nodes;
    createNodeList();
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
    nodes_.resize(num_nodes_, NULL);
    for (size_t i = 0; i < num_nodes_; i++) {
        nodes_[0] = Node(i);
    }
}

void Graph::parseNodes(string filename)
{
    edges_.resize(num_nodes_);

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