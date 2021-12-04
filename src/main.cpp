#include <iostream>
#include "graph.h"
#include "node.h"
#include "dfs.h"

using namespace std;

int main()
{
    // Graph g("data/data.txt", 262111);
    Graph g("tests/dummy_data/ConnectedUndirectedGraph.txt", 7);
    g.Traversal();

    return 0;
}