#include "node.h"
#include <iostream>

Node::Node(int id) {
    id_ = id;
    importance_ = 0;
    betweenness_ = 0;
}

void Node::setImportance(double importance) {
    importance_ = importance;
}

void Node::setBetweenness(double betweenness) {
    betweenness_ = betweenness;
}

int Node::getId() const {
    return id_;
}

double Node::getImportance() const {
    return importance_;
}

double Node::getBetweenness() const {
    return betweenness_;
}