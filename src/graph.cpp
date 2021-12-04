#include "graph.h"

Graph::Graph()
{
    num_nodes_ = 0;
    name_ = "";
}

Graph::Graph(AdjList edges, vector<Node> nodes, string name)
{
    edges_ = edges;
    nodes_ = nodes;
    num_nodes_ = nodes_.size();
    name_ = name;
}

Graph::Graph(string filename, size_t num_nodes)
{
    num_nodes_ = num_nodes;
    createNodeList();
    parseNodes(filename);
    name_ = name;
}

void Graph::Traversal()
{
    DFS dfs(edges_, nodes_);

    ofstream myfile;
    myfile.open (name + "_Traversal.txt");
    myfile << "Path Traversal:" << endl;

    for (auto it = dfs.begin(); it != dfs.end(); ++it) {
        myfile << (*it)->getId() << endl;
    }
    myfile.close();
}

void Graph::PageRank() const
{
}

void Graph::BetweennessCentrality() const
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

unsigned Graph::getConnectedComponents() const {
    return connected_components_;
}
