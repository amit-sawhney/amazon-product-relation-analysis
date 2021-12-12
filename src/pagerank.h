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
         * @return nxn Google Page Rank Matrix that stores the probabilities that one state will jump to another.
         */
        Matrix createGoogleMatrix() const;

        /** 
         * Helper Method for PageRank but uses a sparse matrix to save space and time.
         * @return Sparse Matrix that only contains the non-default values that are added to every entry.
         * The Sparse Matrix is a vector of linked lists of tuples.
         * Each linked list in the matrix represents the non-default values for that ougoing node.
         * The linked-list stores a tuple where the first entry is the row index and the second entry is the data. 
         */
        SparseMatrix createSparseGoogle() const;

    private: 
        unsigned num_nodes_;
        AdjList edges_;
};