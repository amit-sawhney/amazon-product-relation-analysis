#include <iostream>
#include "graph.h"
#include "node.h"

using namespace std;

int main() {

    cout << "I compiled" << endl;

    Node node(1);

    cout << "The created node has an id of " << node.getId() << endl;

    return 0;
}