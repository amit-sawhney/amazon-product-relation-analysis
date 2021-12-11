#include "pagerank.h"

#define kDAMPENING 0.85
#define KMAXITERATIONS 10
#define kTOLERANCE 0.00001

PageRank::PageRank(AdjList edges) {
    edges_ = edges;
    num_nodes_ = edges_.size();
}

vector<double> PageRank::createProbabilities() const {
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

    return probabilities;
}

Matrix PageRank::createGoogleMatrix() const {
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

vector<double> PageRank::createSparseProbabilities() const {
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

    return probabilities;
}

SparseMatrix PageRank::createSparseGoogle() const {
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
