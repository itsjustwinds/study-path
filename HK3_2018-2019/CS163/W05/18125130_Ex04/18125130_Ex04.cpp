/*
 * 18125130_Ex04.cpp
 *
 *  Created on: Jun 12, 2019
 *      Author: huy
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void get_res(TreeNode* A,int &res,int &cnt,int B){
     if(A==NULL) return;
     if(cnt>=B) return;
     if(A->left!=NULL) get_res(A->left,res,cnt,B);
     cnt++;
     if(cnt==B) res=A->val;
     get_res(A->right,res,cnt,B);
 }

int Solution::kthsmallest(TreeNode* A, int B) {
    int res=0;
    int cnt=0;
    get_res(A,res,cnt,B);
    return res;
}



