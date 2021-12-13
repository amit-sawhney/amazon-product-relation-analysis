#pragma once

class Node {

    public:
        Node(int id);

        void setImportance(double importance);
        void setBetweenness(double betweenness);

        int getId() const;
        double getImportance() const;
        double getBetweenness() const;

    private:
        int id_;
        double importance_; // PageRank Score
        double betweenness_;
};