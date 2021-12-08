#pragma once
#include <vector>
using namespace std;

typedef vector<list<Node*>> AdjList;
typedef vector<vector<double>> Matrix;
#define kDAMPENING 0.85

class Linear {
    public:
        /** 
         * Method that Gets the Matrix Vector Product
         * @param matrix of size m x n
         * @param vec of size n x 1
         * @return product of size n x 1
         *      Strassen's matrix multiplication
         * O(mn) Time. 
         */
        static vector<double> getMatrixVectorProduct(const Matrix &matrix, const vector<double> &vec) {
            vector<double> output;
            output.resize(matrix[0].size(), 0.0);

            for (size_t r = 0; r < matrix[0].size(); r++) {
                for (size_t c = 0; c < matrix.size(); c++) {
                    output[r] += matrix[r][c] * vec[c];
                }
            }
            return output;
        }

        static vector<double> getSparseProduct(const AdjList &adjList, const vector<double> &vec) {
            double positiveAdjustment = (1.0 - kDAMPENING) / vec.size();
            double noLinksInfluence = (kDAMPENING / vec.size()) + positiveAdjustment;
            double vecSum = getVectorSum(vec);

            vector<double> output;
            output.resize(vec.size(), 0.0);
            
            for (size_t i = 0; i < vec.size(); i++) {
                if (adjList[i].size() == 0) {
                    output[i] = noLinksInfluence * vecSum;
                } else {
                    double nonZeroSum = 0.0;
                    for (const auto &node : adjList[i]) {
                        nonZeroSum += vec[node->getId()];
                    }
                    output[i] += nonZeroSum * kDAMPENING / adjList[i].size();
                    output[i] += positiveAdjustment * (vecSum - nonZeroSum) * (vec.size() - adjList[i].size());
                }
            }
            return output;
        }

        /**
         * Method gets the 2-Norm of a vector
         * @param vec a vector of size n x 1
         * @return norm of the vector
         * O(n) Time.
         */
        static double getNorm(const vector<double> &vec) {
            double norm = 0;
            for (size_t i = 0; i < vec.size(); i++) {
                norm += vec[i] * vec[i];
            }
            return norm;
        }
    private:
        /**
         * Helper Method that gets the sum of all the values in the vector.
         * @param vec a vector of size n x 1
         * @return sum of the values in the vector.
         * O(n) Time.
         */
        static double getVectorSum(const vector<double> &vec) {
            double sum = 0;
            for (size_t i = 0; i < vec.size(); i++) {
                sum += vec[i];
            }
            return sum;
        }
};