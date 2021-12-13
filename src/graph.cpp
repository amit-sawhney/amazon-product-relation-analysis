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
    num_nodes_ = num_nodes;
    createNodeList();
    parseNodes(filename);
    name_ = name;
}

void Graph::Traversal()
{
    // Create DFS Traversal
    DFS dfs(edges_, nodes_);
    connected_components_ = dfs.getConnectedComponents();

    // Output DFS Traversal to File
    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_Traversal.txt");
    myfile << "Path Traversal for " << to_string(num_nodes_) << " nodes with " 
            << to_string(connected_components_) << " Connected Component(s):" << endl;
    for (auto it = dfs.begin(); it != dfs.end(); ++it)
    {
        myfile << (*it)->getId() << endl;
    }
    myfile.close();
}

void Graph::RunPageRank() 
{
    // Getting and Setting the Probabilities
    PageRank pagerank = PageRank(edges_);
    vector<double> probabilities = pagerank.createProbabilities();
    for (unsigned i = 0; i < probabilities.size(); i++) {
        nodes_[i].setImportance(probabilities[i]);
    }

    // Sorting the Probabilities
    vector<Node> sorted_nodes = nodes_;
    sort(sorted_nodes.begin(), sorted_nodes.end(), compareProbabilities);

    // Saving Probabilities to File
    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_PageRank.txt");
    myfile << "Importance Score for " << to_string(num_nodes_) << " nodes:" << endl;

    for (unsigned i = 0; i < num_nodes_; i++) {
        myfile << "Node " << to_string(sorted_nodes[i].getId()) << " -> " << to_string(sorted_nodes[i].getImportance()) << endl;
    }
    myfile.close();
}


bool Graph::compareProbabilities(const Node node1, const Node node2) 
{
    return (node1.getImportance() > node2.getImportance());
}

map<Node *, double> Graph::BetweennessCentrality() const
{
    // Getting and Setting the Betweenness Scores
    Betweenness b(nodes_, edges_);
    map<Node*, double> betweenness = b.calculateBetweenness();

    for (auto it = betweenness.begin(); it != betweenness.end(); ++it) {
        it->first->setBetweenness(it->second);
    }

    // Sorting the Betweenness Scores
    vector<Node> sorted_nodes = nodes_;
    sort(sorted_nodes.begin(), sorted_nodes.end(), compareBetweenness);

    // Saving Probabilities to File
    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_Betweenness.txt");
    myfile << "Betweenness Score for " << to_string(num_nodes_) << " nodes:" << endl;

    for (unsigned i = 0; i < num_nodes_; i++) {
        myfile << "Node " << to_string(sorted_nodes[i].getId()) << " -> " << to_string(sorted_nodes[i].getBetweenness()) << endl;
    }
    myfile.close();

    return betweenness;
}

bool Graph::compareBetweenness(const Node node1, const Node node2) 
{
    return (node1.getBetweenness() > node2.getBetweenness());
}

void Graph::createNodeList()
{
    nodes_.resize(num_nodes_, NULL);
    for (size_t i = 0; i < num_nodes_; i++)
    {
        nodes_[i] = Node(i);
    }
}

void Graph::parseNodes(string filename)
{
    // Checking if file is exists.
    ifstream data(filename);
    if(data.fail()) {
        throw invalid_argument("The file does not exist");
    }

    edges_.resize(num_nodes_);
    string edge;
    unsigned from, to;

    if (data.is_open()) {
        while (getline(data, edge)) {
            // Adding Edges to adjacency list and Ignore Comments from input file
            if (edge[0] != '#') {
                istringstream edgeStream;
                edgeStream.str(edge);
                edgeStream >> from;
                edgeStream >> to;

                if (from < num_nodes_ && to < num_nodes_)
                {
                    edges_[from].push_back(&nodes_[to]);
                }
            }
        }
    }
}


AdjList Graph::getEdges() const
{
    return edges_;
}

string Graph::outputEdges() const 
{
    string output;
    for (size_t i = 0; i < num_nodes_; i++)
    {
        output += '|' + to_string(i) + '|';
        for (auto node : edges_[i])
        {
            output += " -> " + to_string(node->getId());
        }
        output += '\n';
    }
    return output;
}

void Graph::saveAnalysis() 
{
    // Saving Page Rank Importance and Betweenness Value to File
    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_Analysis.txt");
    myfile << "Analysis of Page Rank Versus Betweenness Centrality for " << to_string(num_nodes_) << " nodes:" << endl << endl;
    myfile << "Node\t  PageRank\t  Betweenness Centrality" << endl;

    for (unsigned i = 0; i < num_nodes_; i++) {
        myfile << "Node " << to_string(nodes_[i].getId()) << " -> " << to_string(nodes_[i].getImportance())
                                                          << " -> " << to_string(nodes_[i].getBetweenness()) << endl;
    }
    myfile.close();
}
