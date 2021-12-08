#include "node.h"

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

int Node::getImportance() const {
    return importance_;
}