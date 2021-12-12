#pragma once
#include <list>
#include <vector>
using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<list<tuple<unsigned, double>>> SparseMatrix;
#define kDAMPENING 0.85

class Linear {
    public:
        /** 
         * Method that Gets the Matrix Vector Product
         * @param matrix of size m x n
         * @param vec of size n x 1
         * @return product of size n x 1
         * O(mn) Time. 
         */
        static vector<double> getMatrixVectorProduct(const Matrix &matrix, const vector<double> &vec) {
            vector<double> output;
            output.resize(matrix[0].size(), 0.0);

            // Row Vector Multiplication
            for (size_t r = 0; r < matrix[0].size(); r++) {
                for (size_t c = 0; c < matrix.size(); c++) {
                    output[r] += matrix[r][c] * vec[c];
                }
            }
            return output;
        }

        /**
         * Method that Gets the Matrix Vector Product when the Matrix is Sparse
         * @param sparse of size m x n
         * @param vec of size n x 1
         * @param sparseValue is the values for the entrices not in the sparse matrix
         * @return product of size n x 1
         * O(mn) Time.
         */
        static vector<double> getSparseProduct(const SparseMatrix &sparse, const vector<double> &vec, double sparseValue) {
            double vecSum = getVectorSum(vec);

            vector<double> output;
            output.resize(vec.size(), 0.0);
            
            for (size_t i = 0; i < sparse.size(); i++) {
                double nonZeroSum = 0.0;

                // Adding all the non-Sparse Values
                for (const auto &tup : sparse[i]) {
                    nonZeroSum += vec[get<0>(tup)];
                    output[i] += get<1>(tup) * vec[get<0>(tup)];
                }

                // Adding the remaining Sparse Values since they are all the same.
                output[i] += sparseValue * (vecSum - nonZeroSum);
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