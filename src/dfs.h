#pragma once
#include "node.h"
#include <vector> 
#include <list>
#include <stack>
#include <iostream>
using namespace std;
typedef vector<list<Node*>> AdjList;


class DFS {
    public:
        DFS(AdjList &edges, vector<Node> &nodes);
        // DFS();
        int getConnectedComponents();
        class Iterator : iterator<forward_iterator_tag, Node> {
            public:
                Iterator();
                Iterator(unsigned index);
                Iterator operator++();
                Node* operator*();
                bool operator!=(Iterator &other);
            private:
                int index_;
                Node* current_;
        };

        Iterator begin();
        Iterator end();
    private:

        int connected_components_;
        void DFSHelper(int id, vector<bool> &visited, AdjList &edges, vector<Node> &nodes);
    protected:
        static vector<Node*> traversal_order_;
};