#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    void top_view(Node * root, map<int, pair<int, int> > &m, int hd, int level) {
        if (root == nullptr) {
            return;
        }
        if (m.find(hd) != m.end()) {
            if (level < m[hd].second) {
                m[hd] = make_pair(root->data, level);
            }
        } else {
            m[hd] = make_pair(root->data, level);
        }

        top_view(root->left, m, hd-1, level+1);
        top_view(root->right, m, hd+1, level+1);
    }
    void topView(Node * root) {
        map<int, pair<int, int> > m;
        top_view(root, m,0,0);
        int mn = 100000;
        int mx = -100000;

        for (auto x : m) {
            if (mx < x.first) mx = x.first;
            if (mn> x.first) mn = x.first;
        }
        int i = mn;
        while (i <= mx) {
            cout << m[i].first << " ";
            i = i + 1;
        }
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}

