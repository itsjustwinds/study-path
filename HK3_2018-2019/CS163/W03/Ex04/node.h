#ifndef NODE_H
#define NODE_H


class Node {
public:
    int data;
    Node* child_left;
    Node* child_right;
    Node* parrent;

    Node() : data(0), child_left(nullptr), child_right(nullptr), parrent(nullptr) {}
    Node(int data) : data(data), child_left(nullptr), child_right(nullptr), parrent(nullptr) {}
    ~Node() {
        child_left = nullptr;
        child_right = nullptr;
        parrent = nullptr;
    }    
};

#endif
