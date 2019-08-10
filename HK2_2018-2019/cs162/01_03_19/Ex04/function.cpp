/*
 * function.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: huy
 */
#include"function.h"

void input(ifstream &fin,Node *&root,int &x,int &y){
	Node *cur=root;
	int num;
	fin>>num;
	while(num){
		cur->Next=new Node;
		cur=cur->Next;
		cur->val=num;
		fin>>num;
	}
	cur->Next=nullptr;
	fin>>x>>y;
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

void insert(Node *&root,int &x,int &y){
	int ok=0;
	if (root==nullptr||root->val==y){
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=root;
		root=tmp;
		return;
	}
	for (Node *cur=root;cur->Next!=nullptr;cur=cur->Next)
	if (cur->Next->val==y){
		ok=1;
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=cur->Next;
		cur->Next=tmp;
		break;
	}
	if (ok==0){
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=root;
		root=tmp;
	}
}
