/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root->left!=NULL) {
            if (root->val!=root->left->val) return 0;
            if (isUnivalTree(root->left)==0) return 0;
        }
        if (root->right!=NULL){
            if (root->val!=root->right->val) return 0;
            if (isUnivalTree(root->right)==0) return 0;
        }
        return 1;
    }
};
