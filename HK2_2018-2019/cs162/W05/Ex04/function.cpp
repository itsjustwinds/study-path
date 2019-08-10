/*
 * function.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */

#include"function.h"

void input(ifstream &fin,Node *&root){
	int x;
	fin>>x;
	if (!x) return;
	root=new Node;
	root->val=x;
	root->Next=nullptr;
	Node *cur=root;
	fin>>x;
	while(x){
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=nullptr;
		cur->Next=tmp;
		cur=cur->Next;
		fin>>x;
	}
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

void create_list(Node *&listA,Node *&listB,Node *&res){
	Node *curA=listA;
	Node *curB=listB;
	Node *curres=res;
	while(curA!=nullptr||curB!=nullptr){
		if (curA!=nullptr){
			if (curres==nullptr){
				res=curA;
				curres=curA;
			}
			else {
				curres->Next=curA;
				curres=curres->Next;
			}
			curA=curA->Next;
		}
		if (curB!=nullptr){
			if (curres==nullptr){
				res=curB;
				curres=curB;
			}
			else {
				curres->Next=curB;
				curres=curres->Next;
			}
			curB=curB->Next;
		}
	}
}