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

void Graph::parseNodes(string filename)
{
    edges_.resize(NUM_NODES);

    ifstream data(filename);
    string edge;
    istringstream edgeStream;
    int from, to;
    if (data.is_open())
    {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
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