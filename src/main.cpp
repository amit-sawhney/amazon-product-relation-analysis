#include <iostream>
#include "graph.h"
#include "node.h"
#include "dfs.h"

using namespace std;

int main()
{
    cout << "I compiled" << endl;

    Node node(1);

    cout << "The created node has an id of " << node.getId() << endl;

    Graph g("data/data.txt", 262111);
    g.Traversal();

    return 0;
}