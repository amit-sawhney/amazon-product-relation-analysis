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
        /**
         * Method that will create and DFS Traversal on the graph, while counting the number of connected components.
         * O(n + m) Time.
         */
        DFS(AdjList &edges, vector<Node> &nodes);

        /**
         * A forward iterator through a Graph of Nodes.
         */
        class Iterator : iterator<forward_iterator_tag, Node> {
            public:
                /**
                 * A custom iterator through a Graph of Nodes.
                 * @param index is the current index of the traversal
                 * @param traversal_order is a vector with the traversal path.
                 */
                Iterator(unsigned index, vector<Node*> &traversal_order);

                Iterator operator++();
                Node* operator*() const;
                bool operator!=(const Iterator &other);

            private:
                unsigned index_;
                Node* current_;
                vector<Node*> traversal_order_;
        };

        Iterator begin();
        Iterator end();

        int getConnectedComponents();
        
    private:
        int connected_components_;
        vector<Node*> traversal_order_;

        /**
         * Helper Method for DFS Traversal that visits the neighboring edges of the specified id.
         * O(n + m) Time.
         */
        void DFSHelper(int id, vector<bool> &visited, AdjList &edges, vector<Node> &nodes);
};