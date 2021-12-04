#pragma once

#include "node.h"
#include <iostream>
#include <list>
#include <stack>
#include <vector> 

using namespace std;
typedef vector<list<Node*>> AdjList;

class DFS {
    public:
        DFS(AdjList &edges, vector<Node> &nodes);
        class Iterator : iterator<forward_iterator_tag, Node> {
            public:
                Iterator(unsigned index);
                Iterator operator++();
                Node* operator*() const;
                bool operator!=(const Iterator &other);
            private:
                int index_;
                Node* current_;
        };

        Iterator begin();
        Iterator end();

        int getConnectedComponents();
    private:
        int connected_components_;
        void DFSHelper(int id, vector<bool> &visited, AdjList &edges, vector<Node> &nodes);
    protected:
        static vector<Node*> traversal_order_;
};