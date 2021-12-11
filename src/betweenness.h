#include <map>
#include "node.h"
#include <stack>
#include <list>
#include <vector>
using namespace std;

typedef vector<list<Node*>> AdjList;

class Betweenness {
    public:
        // Betweenness();
        Betweenness(const vector<Node>& nodes, const AdjList& adjacency);

        // Edit nodes to add betweenness centrality values
        map<Node*, double> calculateBetweenness();
        
    private:
        stack<Node*> node_stack_;
        map<Node*, list<Node*>> predecessors_;
        map<Node*, double> sigma_;
        map<Node*, double> betweenness_values_;
        vector<Node> nodes_;
        AdjList adjacency_;

        void accumulateNodes(Node* node);
        void shortestPathCalculation(Node* node);
};