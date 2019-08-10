/*
 * main.cpp
 *
 *  Created on: May 20, 2019
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
int main(){
	Node *root;
	root=NULL;
	int n;
	while(1){
		cin>>n;
		if (n==0) break;
		add_node(root,n);
	}
	display(root);
	cout<<"\n"<<check_exist(root,500);
	delete_tree(root);
	return 0;
}


