#include "betweenness.h"

Betweenness::Betweenness(const vector<Node> &nodes, const AdjList &adjacency)
{
    nodes_ = nodes;
    adjacency_ = adjacency;
}

void Betweenness::accumulateNodes(Node *node)
{
    map<Node *, double> delta;

    // Iterate through shortestPath calculated values to find betweenness
    while (!node_stack_.empty())
    {
        Node *next_node = node_stack_.top();
        node_stack_.pop();

        // Calculate change in betweenness values
        double coeff = (1 + delta[next_node]) / sigma_[next_node];
        for (auto vertex : predecessors_[next_node])
        {
            delta[vertex] = delta[vertex] + (sigma_[vertex] * coeff);
        }

        if (next_node != node)
        {
            betweenness_values_[next_node] = betweenness_values_[next_node] + delta[next_node];
        }
    }
}

void Betweenness::shortestPathCalculation(Node *node)
{
    predecessors_.clear();
    sigma_.clear();

    map<int, int> dist;

    sigma_[node] = 1.0;

    queue<Node *> q;

    q.push(node);

    // Run BFS on nodes to find shortest path
    while (!q.empty())
    {
        Node *v = q.front();
        q.pop();
        node_stack_.push(v);
        int distV = dist[v -> getId()];
        double sigmaV = sigma_[v];

        for (auto w : adjacency_[v->getId()])
        {
            if (!dist.count(w -> getId()))
            {
                q.push(w);
                dist[w -> getId()] = distV + 1;
            }

            // Add predecessors when finding shortest path
            if (dist[w -> getId()] == distV + 1)
            {
                sigma_[w] = sigma_[w] + sigmaV;
                predecessors_[w].push_back(v);
            }
        }
    }
}
map<Node *, double> Betweenness::calculateBetweenness()
{
    for (auto node : nodes_)
    {
        shortestPathCalculation(&node);
        accumulateNodes(&node);
    }

    return betweenness_values_;
}
