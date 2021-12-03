#pragma once
#include "node.h"
#include <vector> 
#include <list>
#include <stack>

using namespace std;
typedef vector<list<Node*>> AdjList;


class DFS {
    public:
        // DFS(AdjList &edges, vector<Node> &nodes);
        DFS();
        int getConnectedComponents();
        class Iterator : iterator<forward_iterator_tag, Node> {
            public:
                Iterator();
                Iterator(unsigned index);
                Iterator & operator++();
                Node operator*();
                bool operator!=(const Iterator &other);
            private:
                int index_;
                Node* current_;
        };

        Iterator begin();
        Iterator end();
    private:
        vector<Node*> traversal_order_;
        int connected_components_;
        void DFSHelper(int id, vector<bool> &visited);
        
};