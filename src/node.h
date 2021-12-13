#pragma once

class Node {

    public:
        Node(int id);

        void setImportance(double importance);
        void setBetweenness(double betweenness);
        void setImportanceRank(unsigned importanceRank);
        void setBetweennessRank(unsigned betweennessRank);

        int getId() const;
        double getImportance() const;
        double getBetweenness() const;

        unsigned getImportanceRank() const;
        unsigned getBetweennessRank() const;

    private:
        int id_;
        double importance_; // PageRank Score
        double betweenness_;

        unsigned importanceRank_;
        unsigned betweennessRank_;
};