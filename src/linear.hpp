#pragma once
#include <vector>
using namespace std;
typedef vector<vector<double>> Matrix;

class Linear {
    public:
        /** 
         * Method that Gets the Matrix Vector Product
         * @param matrix of size m x n
         * @param vec of size n x 1
         * @return product of size n x 1
         * O(mn) Time. 
         */
        static vector<double> getMatrixVectorProduct(Matrix &matrix, vector<double> &vec) {
            vector<double> output;
            output.resize(matrix[0].size(), 0.0);

            for (size_t r = 0; r < matrix[0].size(); r++) {
                for (size_t c = 0; c < matrix.size(); c++) {
                    output[r] += matrix[r][c] * vec[c];
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
        static double getNorm(vector<double> &vec) {
            double norm = 0;
            for (size_t i = 0; i < vec.size(); i++) {
                norm += vec[i] * vec[i];
            }
            return norm;
        }
    private:
};