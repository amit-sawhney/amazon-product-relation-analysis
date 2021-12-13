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

void Node::setImportanceRank(unsigned importanceRank) {
    importanceRank_ = importanceRank;
}

void Node::setBetweennessRank(unsigned betweennessRank) {
    betweennessRank_ = betweennessRank;
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

unsigned Node::getImportanceRank() const {
    return importanceRank_;
}

unsigned Node::getBetweennessRank() const {
    return betweennessRank_;
}