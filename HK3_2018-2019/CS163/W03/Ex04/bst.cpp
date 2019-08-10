#include "bst.h"

BST::BST() : root(nullptr) {};

BST::~BST() {
    DeleteTree(root);
}

Node* BST::Insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }

    if (root->data < data) {
        root->child_right = Insert(root->child_right, data);
    } else {
        root->child_left = Insert(root->child_left, data);
    }

    return root;
}

void BST::PrintInOrder(ofstream &fo, Node* root) {
    if (root == nullptr) {
        return;
    }

    PrintInOrder(fo, root->child_left);
    fo << root->data << " ";
    PrintInOrder(fo, root->child_right);

}


bool BST::Search(Node* root, int data) {
    if (root == nullptr) return false;

    if (root->data == data) return true;
    
    if (root->data < data) {
        return Search(root->child_right, data);
    } else {
        return Search(root->child_left, data);
    }
}

void BST::DeleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    DeleteTree(root->child_left);
    DeleteTree(root->child_right);
    delete root;
    root = nullptr;
}


Node* BST::DeleteANode(Node* root, int data) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data < data) {
        root->child_right = DeleteANode(root->child_right, data);
    } else if (root->data > data) {
        root->child_left = DeleteANode(root->child_left, data);
    } else {
        if (root->child_left == nullptr) {
            Node* temp_node = root->child_right;
            delete root;
            root = nullptr;
            return temp_node;
        } else if (root->child_right == nullptr) {
            Node* temp_node = root->child_left;
            delete root;
            root = nullptr;
            return temp_node;
        } else {
            Node* temp_node = MinValueNode(root->child_right);
            root->data = temp_node->data;
            root->child_right = DeleteANode(root->child_right, temp_node->data);
        } 
    }
    
    return root;
}


Node* BST::MinValueNode(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->child_left == nullptr) {
        return root;
    } else {
        return MinValueNode(root->child_left);
    }
}
