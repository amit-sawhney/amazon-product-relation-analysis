#pragma once

class Node {

    public:
        Node(int id);

        void setImportance(double importance);

        int getId() const;
        int getImportance() const;

    private:
        int id_;
        double importance_; // PageRank Score
};