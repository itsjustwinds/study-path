/*
 * function.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: huy
 */

#include"function.h"

void input(ifstream &fin,Node *&root,int &n){
	int x;
	fin>>x;
	Node *cur=root;
	while(x){
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=nullptr;
		cur->Next=tmp;
		cur=cur->Next;
		fin>>x;
	}
	fin>>n;
	cur=root->Next;
	delete root;
	root=cur;
}

void output(ofstream &fout,Node *&root){
	if (root==nullptr) {
		fout<<0;
		return;
	}
	fout<<root->val<<" ";
	output(fout,root->Next);
}

void delete_pointer(Node *&root){
	if (root==nullptr) return;
	delete_pointer(root->Next);
	delete root;
}

void insert(Node *&root,int &n){
	if (root==nullptr||root->val>n){
		Node *tmp=new Node;
		tmp->val=n;
		tmp->Next=root;
		root=tmp;
		return;
	}
	Node *cur=root;
	for (;cur->Next!=nullptr;cur=cur->Next){
		if (cur->Next->val>n){
			Node *tmp=new Node;
			tmp->val=n;
			tmp->Next=cur->Next;
			cur->Next=tmp;
			return;
		}
	}
	Node *tmp=new Node;
	tmp->val=n;
	tmp->Next=nullptr;
	cur->Next=tmp;
}
