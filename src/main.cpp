#include <exception>
#include <iostream>

#include "dfs.h"
#include "graph.h"
#include "node.h"
#include "pagerank.h"

using namespace std;

int main(int argc, char **argv) {
    try {
        if (argc != 4) {
            throw invalid_argument("The correct number of data points was not inputted.");
        }

        // Data Path - "data/data.txt"
        string file = argv[1]; 

        // Number of Nodes - 10000 nodes
        stringstream string_nodes(argv[2]);
        int num_nodes = 0;
        string_nodes >> num_nodes;
        if (num_nodes < 0) {
            throw invalid_argument("There was an invalid number of nodes entered.");
        }

        // Output File Name - "Amazon_Items"
        string name = argv[3];
        
        // Creating and Running Graph Algorithms
        Graph g(file, num_nodes, name);
        g.Traversal();
        g.RunPageRank();

    } catch (exception& e) {
        cout << e.what() << endl;
        cout << "Pleas enter 1. Data File Path   2. Number of Nodes   3. Output File Name" << endl;
    }

    return 0;
}
