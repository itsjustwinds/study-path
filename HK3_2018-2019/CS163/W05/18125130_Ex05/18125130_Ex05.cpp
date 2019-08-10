/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode * A, TreeNode *B){
    if (A==NULL&&B==NULL) return 1;
    if (A==NULL||B==NULL) return 0;
    if (A->val!=B->val) return 0;
    return check(A->left,B->right)&&check(A->right,B->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return 1;
        return check(root,root);
    }
};
