/*
 * function.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: huy
 */
#include"function.h"

void input(ifstream &fin,Node *&root){
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

void delete_last(Node *&root){
	if (root==nullptr) return;
	if (root->Next==nullptr) {
		delete root;
		root=nullptr;
		return;
	}
	Node *tmp=root;
	for (;tmp->Next->Next!=nullptr;tmp=tmp->Next){}
	delete tmp->Next;
	tmp->Next=nullptr;
}
