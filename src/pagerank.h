#pragma once

#include "node.h"
#include "linear.hpp"

#include <cmath>
#include <list>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<list<Node*>> AdjList;
typedef vector<vector<double>> Matrix;
typedef vector<list<tuple<unsigned, double>>> SparseMatrix;

class PageRank {
    public:
        PageRank(AdjList edges);

        /**
         * Method that will run Google's Page Rank Algorithm on its own graph.
         * @return the probabilities of each of the nodes
         */
        vector<double> createProbabilities() const;

        /**
         * Helper Method for PageRank that will create the Google Page Rank Matrix.
         * The influence of each page is split evenly between the pages it links to. We should divide each row entry by the total column sum.
         * If a node has no outgoing edges, there is an equal probability of going to any other edge then.
         * To arrive at a unique solution we will do "M = 0.85 A + (0.15 / n) One"  --  One is a matrix of size n x n where every entry is 1.
         */
        Matrix createGoogleMatrix() const;

        /** 
         * Helper Method for PageRank but uses a sparse matrix to save space and time.
         */
        SparseMatrix createSparseGoogle() const;

    private: 
        unsigned num_nodes_;
        AdjList edges_;
};