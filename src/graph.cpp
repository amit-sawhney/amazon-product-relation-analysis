#include "graph.h"

#define kDAMPENING 0.85
#define KMAXITERATIONS 10
#define kTOLERANCE 0.00001

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

Graph::Graph(string filename, size_t num_nodes, string name)
{
    // Make sure num_nodes isn't zero.
    num_nodes_ = num_nodes;
    createNodeList();
    parseNodes(filename);
    name_ = name;
}

void Graph::Traversal()
{
    DFS dfs(edges_, nodes_);
    connected_components_ = dfs.getConnectedComponents();

    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_Traversal.txt");
    myfile << "Path Traversal for " << to_string(num_nodes_) << " nodes with " 
            << to_string(connected_components_) << " Connected Component(s):" << endl;

    for (auto it = dfs.begin(); it != dfs.end(); ++it) {
        myfile << (*it)->getId() << endl;
    }
    myfile.close();
}

void Graph::RunPageRank() const 
{
    PageRank pagerank = PageRank(edges_);
    vector<double> probabilities = pagerank.createSparseProbabilities();

    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_PageRank.txt");
    myfile << "Importance Score for " << to_string(num_nodes_) << " nodes:" << endl;

    for (unsigned i = 0; i < probabilities.size(); i++) {
        myfile << "Node " << to_string(i) << " -> " << probabilities[i] << endl;
    }
    myfile.close();
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

    // File does not exist
    if(data.fail()){
        throw invalid_argument("The file does not exist");
    }
    string edge;

    unsigned from, to;
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

                if (from < num_nodes_ && to < num_nodes_) {
                    edges_[from].push_back(&nodes_[to]);
                }
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
