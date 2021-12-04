#include <iostream>
#include "graph.h"
#include "node.h"
#include "dfs.h"

using namespace std;

int main()
{
    Graph g("data/data.txt", 262111, "Amazon_Items");
    g.Traversal();

    return 0;
}