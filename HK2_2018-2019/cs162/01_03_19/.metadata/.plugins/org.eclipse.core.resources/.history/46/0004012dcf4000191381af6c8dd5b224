/*
 * function.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: huy
 */
#include"function.h"

void input(ifstream &fin,Node *&root,int &x){
	Node *cur=root;
	int num;
	fin>>num;
	while(num){
		cur->Next=new Node;
		cur=cur->Next;
		cur->val=num;
		fin>>num;
	}
	fin>>x;
	cur->Next=nullptr;
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
	if(root==nullptr) return;
	delete_pointer(root->Next);
	delete root;
}

void delete_X(Node *&root,int &x){
	if (root==nullptr) return;
	while (root->val==x){
		Node *tmp=root->Next;
		delete root;
		root=tmp;
	}
	for (Node *cur=root;cur->Next!=nullptr;){
		if (cur->Next->val==x){
			Node *tmp=cur->Next->Next;
			delete cur->Next;
			cur->Next=tmp;
			continue;
		}
		cur=cur->Next;
	}
}
