#include "betweenness.h"

Betweenness::Betweenness()
{
}

Betweenness::Betweenness(vector<Node> *nodes, AdjList *adjacency)
{
    nodes_ = nodes;
    adjacency_ = adjacency;
}

void Betweenness::calculateBetweenness()
{
    for (auto node : nodes_)
    {
        shortestPathCalculation(node);
    }
}

void Betweenness::accumulateNodes(Node *node)
{
}

void Betweenness::shortestPathCalculation(Node *node)
{
    node_stack_ = stack<Node *>();
    predecessors_.clear();
    sigma_.clear();

    map<Node *, int> dist;

    sigma_[node] = 1.0;
    dist[node] = 0;

    queue<Node *> q;

    q.push(node);

    while (!q.empty())
    {
        Node *v = q.front();
        q.pop();
        node_stack_.push(v);
        int distV = dist[v];
        double sigmaV = sigma_[v];

        for (auto w : adjacency_[v->getId()])
        {
            if (dist.find(v) == dist.end())
            {
                q.push(w);
                dist[w] = distV + 1;
            }

            if (dist[w] == distV + 1)
            {
                sigma_[w] += sigmaV;
                predecessors_[w].push_back(v);
            }
        }
    }
}