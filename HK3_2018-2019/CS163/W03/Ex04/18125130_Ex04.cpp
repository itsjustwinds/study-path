#include <iostream>
#include <fstream>
#include "bst.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;

bool Init(BST* tree) {
    ifstream fi("Input.txt");
    if (fi.is_open() == false) {
        return false;
    }

    int data;
    while (fi >> data) {
        tree->root = tree->Insert(tree->root, data);
    }
   
    fi.close();

    cout << "Load data to tree OK!\n\n";
    return true;
}

bool Run(BST* tree) {
    cout << "Enter a number to remove from tree: ";
    int x;
    cin >> x;
   
    if (tree->Search(tree->root, x) == false) {
        cout << "No exist node which value is " << x << " in tree.\n\n";
        return false;
    }

    tree->root = tree->DeleteANode(tree->root, x);

    cout << "Remove node which value is " << x << " from tree OK!\n\n";
    return true;
}

bool Save(BST* tree) {

    ofstream fo("Output.txt");

    tree->PrintInOrder(fo, tree->root);

    fo.close();
    cout << "Save tree by In-Order Traversal to file \"Output.txt\" OK!\n";
    return true;
}

int main() {
    BST* tree = new BST();
    
    Init(tree);
    Run(tree);
    Save(tree);
    delete tree;
}
