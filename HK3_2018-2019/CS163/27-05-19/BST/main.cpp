/*
 * main.cpp
 *
 *  Created on: May 27, 2019
 *      Author: huy
 */

#include<iostream>
using namespace std;
struct Node{
	int val;
	Node *Left,*Right;
};
void add_node(Node *&root,int x){
	if (root==NULL){
		root=new Node;
		root->val=x;
		root->Left=root->Right=NULL;
		return;
	}
	if (x<=root->val) add_node(root->Left,x);
	else add_node(root->Right,x);
}
void display(Node *&root){
	if (root==NULL) return;
	display(root->Left);
	cout<<root->val<<" ";
	display(root->Right);
}
void delete_tree(Node *&root){
	if (root==NULL) return;
	delete_tree(root->Left);
	delete_tree(root->Right);
	delete root;
	root=NULL;
}
bool check_exist(Node *&root,int x){
	if (root==NULL) return 0;
	if (x==root->val) return 1;
	if (x<root->val) return check_exist(root->Left,x);
	if (x>root->val) return check_exist(root->Right,x);
	return 0;
}
void print_all_range(int x,int y,Node* root){
	if (root==NULL) return;
	if (root->val>=x)
		print_all_range(x,y,root->Left);
	if (root->val>=x&&root->val<=y) cout<<root->val<<" ";
	if (root->val<=y)
		print_all_range(x,y,root->Right);
}
int get_level(int x,Node *root,int level){
	if (root==NULL) return -1;
	if (root->val==x) return level;
	if (root->val>x) return get_level(x,root->Left,level+1);
	if (root->val<x) return get_level(x,root->Right,level+1);
	return -1;
}

void LCA(Node* root,int x,int y,Node* &res,int &okX,int &okY){
	if (root==NULL) return;
	int LeftX=LeftY=RightX=RightY=0;

}

void print_level(Node*root,int level,int need){
	if (root==NULL) return;
	if(level>need) return;
	print_level(root->Left,level+1,need);
	if (level==need) cout<<root->val<<" ";
	print_level(root->Right,level+1,need);
}
int main(){
	Node *root;
	root=NULL;
	int n;
	while(1){
		cin>>n;
		if (n==0) break;
		add_node(root,n);
	}
	//display(root);
	print_level(root,1,get_level(4,root,1));
	delete_tree(root);
	return 0;
}





