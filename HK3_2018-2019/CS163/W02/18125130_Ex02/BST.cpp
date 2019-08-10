/*
 * BST.cpp
 *
 *  Created on: May 22, 2019
 *      Author: huy
 */

#include"BST.h"

void BST::delete_tree(Node *&root){
	if (root==nullptr) return;
	delete_tree(root->Left);
	delete_tree(root->Right);
	delete root;
	root=nullptr;
}

void BST::add(Node* &root,int x,int stage){
	if (root==nullptr){
		root=new Node;
		root->val=x;
		root->Left=nullptr;
		root->Right=nullptr;
		root->stage=stage;
		return;
	}

	if (x==root->val) return;
	if (x<root->val) add(root->Left,x,stage+1);
	if (x>root->val) add(root->Right,x,stage+1);
}

BST::BST(int* &a,int n){
	root=new Node;
	root->val=a[0];
	root->stage=1;
	root->Left=nullptr;
	root->Right=nullptr;
	for (int i=1;i<n;++i){
		add(root,a[i],1);
	}
}

void BST::print_pre_order(Node* root){
	if (root==nullptr) return;
	printf("%d ",root->val);
	print_pre_order(root->Left);
	print_pre_order(root->Right);
}

void BST::print_asc_order(Node* root){
	if (root==nullptr) return;
	print_asc_order(root->Left);
	printf("%d ",root->val);
	print_asc_order(root->Right);
}

void BST::print_dec_order(Node* root){
	if (root==nullptr) return;
	print_dec_order(root->Right);
	printf("%d ",root->val);
	print_dec_order(root->Left);
}

void BST::print_post_order(Node* root){
	if (root==nullptr) return;
	print_post_order(root->Left);
	print_post_order(root->Right);
	printf("%d ",root->val);
}

void BST::get_height(Node* root,int &res){
	if(root==nullptr) return;
	res=max(res,root->stage);
	get_height(root->Left,res);
	get_height(root->Right,res);
}

Node* BST::min_value(Node* root){
	while(root->Left!=nullptr) root=root->Left;
	return root;
}

Node* BST::max_value(Node* root){
	while(root->Right!=nullptr) root=root->Right;
	return root;
}

void BST::successor(Node* root,int x, Node* &res){
	if (root==nullptr) return;
	if (x>=root->val) successor(root->Right,x,res);
	else {
		res=root;
		successor(root->Left,x,res);
	}
}

void BST::predecessor(Node* root,int x, Node* &res){
	if (root==nullptr) return;
	if (x<=root->val) predecessor(root->Left,x,res);
	else {
		res=root;
		predecessor(root->Right,x,res);
	}
}
