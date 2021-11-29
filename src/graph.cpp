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

void Graph::DFS()
{
    vector<bool> visited;
    visited.resize(num_nodes_, false);

    connected_components_ = 0;
    for (size_t i = 0; i < num_nodes_; i++) {
        if(!visited[i]) {
            DFSHelper(i, visited);
            connected_components_++;
        }
    }
    cout << "Number of Components: " << connected_components_ << endl;
}

void Graph::DFSHelper(int id, vector<bool> &visited) {
    stack<int> futureVisits;
    futureVisits.push(id);

    while (!futureVisits.empty()) {
        int top = futureVisits.top();
        futureVisits.pop();    
        visited[top] = true;

        for (auto neighbor : edges_[top]) {
            int neighborId = neighbor->getId();
            if (!visited[neighborId]) {
                futureVisits.push(neighborId);
            }
        }
    }
}


void Graph::PageRank() const
{
}

void Graph::createNodeList() 
{
    nodes_.resize(num_nodes_, NULL);
    for (size_t i = 0; i < num_nodes_; i++) {
        nodes_[i] = Node(i);
    }
}

void Graph::parseNodes(string filename)
{
    edges_.resize(num_nodes_);

    ifstream data(filename);
    string edge;

    int from, to;
    if (data.is_open())
    {
        while (getline(data, edge))
        {
            if (edge[0] != '#') // Ignore Comments from input file
            {
                istringstream edgeStream;
                edgeStream.str(edge);
                edgeStream >> from;
                edgeStream >> to;

                edges_[from].push_back(&nodes_[to]);
            }
        }
    }
}

string Graph::outputEdges() const 
{
    string output;
    for (size_t i = 0; i < num_nodes_; i++) {
        output += '|' + to_string(i) + '|';
        for (auto node : edges_[i]) {
            output += " -> " + to_string(node->getId());
        }
        output += '\n';
    }
    return output;
}