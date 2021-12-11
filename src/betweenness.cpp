#include "betweenness.h"

Betweenness::Betweenness(const vector<Node> &nodes, const AdjList &adjacency)
{
    nodes_ = nodes;
    adjacency_ = adjacency;
}

void Betweenness::accumulateNodes(Node *node)
{
    map<Node *, double> delta;
    // cout << "here" << endl;
    while (!node_stack_.empty())
    {
        Node *next_node = node_stack_.top();
        // cout << next_node->getId() << " " << node->getId() << endl;
        node_stack_.pop();

        double coeff = (1 + delta[next_node]) / sigma_[next_node];
        for (auto vertex : predecessors_[next_node])
        {
            delta[next_node] = delta[next_node] + sigma_[vertex] * coeff;
        }

        if (next_node != node)
        {
            betweenness_values_[next_node] = betweenness_values_[next_node] + delta[next_node];
        }
    }

    /* for (auto x : betweenness_values_)
    {
        cout << (x.first)->getId() << ": " << x.second << endl;
    } */
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
            if (dist.find(w) == dist.end())
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
map<Node *, double> Betweenness::calculateBetweenness()
{
    int i = 0;
    for (auto node : nodes_)
    {
        // cout << "LOOP " << i << endl;
        shortestPathCalculation(&node);
        accumulateNodes(&node);
        ++i;
    }

    return betweenness_values_;
}
