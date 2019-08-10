/*
 * BST.h
 *
 *  Created on: May 22, 2019
 *      Author: huy
 */
#pragma once
#ifndef BST_H_
#define BST_H_
#include<iostream>
using namespace std;
struct Node{
	int val,stage;
	Node *Left,*Right;
};
struct BST{
	Node* root;
	BST(int* &a,int n);
	void add(Node* &root,int x,int stage);
	void print_pre_order(Node* root);
	void print_asc_order(Node* root);
	void print_dec_order(Node* root);
	void print_post_order(Node* root);
	void get_height(Node* root,int &res);
	Node* min_value(Node* root);
	Node* max_value(Node* root);
	void successor(Node* root,int x, Node* &res);
	void predecessor(Node* root,int x, Node* &res);
	void delete_tree(Node *&root);
};



#endif /* BST_H_ */