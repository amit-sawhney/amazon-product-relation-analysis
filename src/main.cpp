#include <exception>
#include <iostream>

#include "dfs.h"
#include "graph.h"
#include "node.h"
#include "pagerank.h"

using namespace std;

int main(int argc, char **argv) {
    try {
        if (argc != 5) {
            throw invalid_argument("The correct number of data points was not inputted.");
        }

        // Data Path - "data/data.txt"
        string file = argv[1]; 

        // Number of Nodes - 10000 nodes
        stringstream string_nodes(argv[2]);
        int num_nodes = 0;
        string_nodes >> num_nodes;
        if (num_nodes <= 0) {
            throw invalid_argument("There was an invalid number of nodes entered.");
        }

        // Output File Name - "Amazon_Items"
        string name = argv[3];

        // Algorithm to run
        string algorithm = argv[4];
        
        // Creating and Running Graph Algorithms
        Graph g(file, num_nodes, name);
        if (algorithm == "dfs") {
            g.Traversal();
        } else if (algorithm == "pagerank") {
            g.RunPageRank();
        } else if (algorithm == "betweenness") {
            g.BetweennessCentrality();
        } else if (algorithm == "all") {
            g.Traversal();
            g.RunPageRank();
            g.BetweennessCentrality();
            g.saveAnalysis();
        } else {
            throw invalid_argument("This is not a proper algorithm. Either type dfs, pagerank, betweenness, or all.");
        }

    } catch (exception& e) {
        cout << e.what() << endl;
        cout << "Pleas enter 1. Data File Path   2. Number of Nodes   3. Output File Name   4. Algorithm Name" << endl;
    }

    return 0;
}
