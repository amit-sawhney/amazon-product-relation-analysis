#include "node.h"
#include <iostream>

Node::Node(int id) {
    id_ = id;
    importance_ = 0;
}

void Node::setImportance(double importance) {
    importance_ = importance;
}

int Node::getId() const {
    return id_;
}

double Node::getImportance() const {
    return importance_;
}