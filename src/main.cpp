#include <iostream>
#include "graph.h"
#include "node.h"
#include "dfs.h"

using namespace std;

int main()
{
    Graph g("data/data.txt", 5000, "Amazon_Items");
    g.Traversal();
    g.SparsePageRank();

    return 0;
}