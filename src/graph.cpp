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

vector<double> Graph::PageRank() const
{
    // Step 1 Create Matrix
    Matrix matrix = createGoogleMatrix();

    // Step 2 Choose Random Markov Start Vector (Possibly just 1/N)
    vector<double> probabilities;
    probabilities.resize(num_nodes_, 1.0 / num_nodes_);

    // Step 3 Find 1st Probabilities (Matrix Vector Multiplication)
    probabilities = Linear::getMatrixVectorProduct(matrix, probabilities);
    double norm = Linear::getNorm(probabilities);

    // Step 4 Repeat Step 3 until at steady state vector (When Norm of Vector is Below a Certain Point)
    for (size_t i = 1; i < KMAXITERATIONS; i++) {
        probabilities = Linear::getMatrixVectorProduct(matrix, probabilities);
        double new_norm = Linear::getNorm(probabilities);
        if (abs(norm - new_norm) < kTOLERANCE) {
            break;
        }
    }

    savePageRank(probabilities);
    return probabilities;
}

vector<double> Graph::SparsePageRank() const
{
    // Step 1 Create Matrix
    SparseMatrix s_matrix = createSparseGoogle();

    // Step 2 Choose Random Markov Start Vector (Possibly just 1/N)
    vector<double> probabilities;
    probabilities.resize(num_nodes_, 1.0 / num_nodes_);

    // Step 3 Find 1st Probabilities (Matrix Vector Multiplication)
    double sparseValue = (1.0 - kDAMPENING) / num_nodes_;
    probabilities = Linear::getSparseProduct(s_matrix, probabilities, sparseValue);
    double norm = Linear::getNorm(probabilities);

    // Step 4 Repeat Step 3 until at steady state vector (When Norm of Vector is Below a Certain Point)
    for (size_t i = 1; i < KMAXITERATIONS; i++) {
        probabilities = Linear::getSparseProduct(s_matrix, probabilities, sparseValue);
        double new_norm = Linear::getNorm(probabilities);
        if (abs(norm - new_norm) < kTOLERANCE) {
            break;
        }
        norm = new_norm;
    }

    savePageRank(probabilities);
    return probabilities;
}

void Graph::savePageRank(const vector<double> &probabilities) const {
    ofstream myfile;
    myfile.open ("deliverables/" + name_ + "_PageRank.txt");
    myfile << "Importance Score for " << to_string(num_nodes_) << " nodes:" << endl;

    for (unsigned i = 0; i < probabilities.size(); i++) {
        myfile << "Node " << to_string(i) << " -> " << probabilities[i] << endl;
    }
    myfile.close();
}

Matrix Graph::createGoogleMatrix() const {
    double positiveAdjustment = (1.0 - kDAMPENING) / num_nodes_;
    double noLinksInfluence = kDAMPENING / num_nodes_;

    vector<double> default_row;
    default_row.resize(num_nodes_, positiveAdjustment);
    Matrix matrix;
    matrix.resize(num_nodes_, default_row);

    for (size_t c = 0; c < num_nodes_; c++) {
        if (edges_[c].size() == 0) {
            for (size_t r = 0; r < num_nodes_; r++) {
                matrix[r][c] += noLinksInfluence;
            }
        } else {
            double influence = kDAMPENING / edges_[c].size();
            for (const auto &node : edges_[c]) {
                matrix[node->getId()][c] += influence;
            }
        }
    }
    return matrix;
}

SparseMatrix Graph::createSparseGoogle() const {
    double positiveAdjustment = (1.0 - kDAMPENING) / num_nodes_;
    double noLinksInfluence = (kDAMPENING / num_nodes_) + positiveAdjustment;

    SparseMatrix matrix;
    matrix.resize(num_nodes_, list<tuple<unsigned, double>>());

    for (size_t c = 0; c < num_nodes_; c++) {
        if (edges_[c].size() == 0) {
            for (size_t r = 0; r < num_nodes_; r++) {
                matrix[r].push_back(tuple<unsigned, double>(c, noLinksInfluence));
            }
        } 
        else {
            double influence = (kDAMPENING / edges_[c].size()) + positiveAdjustment;
            for (const auto &node : edges_[c]) {
                matrix[node->getId()].push_back(tuple<unsigned, double>(c, influence));
            }
        }
    }
    return matrix;
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
