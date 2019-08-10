#ifndef BST_H
#define BST_H

#include "node.h"
#include <fstream>

using std::ofstream;

class BST {
public:
    BST();
    ~BST();

    Node* root;
    void DeleteTree(Node* root);
    Node*  DeleteANode(Node* root, int data);
    Node* MinValueNode(Node* root);
    bool Search(Node* root, int data);
    Node* Insert(Node* root, int data);
    void PrintInOrder(ofstream &fo, Node* root);
};
#endif
