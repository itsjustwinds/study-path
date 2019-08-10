/*
 * function.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: huy
 */
#include"function.h"

void input(ifstream &fin, Node *&root){
	root=new Node;
	while(1){
		int x;
		fin>>x;
		if (x==0) break;
		Node *tmp;
		tmp=new Node;
		tmp->val=x;
		tmp->Next=root;
		root=tmp;
	}
}

void output(ofstream &fout,Node *&root){
	if (root==nullptr) return;
	fout<<root->val<<" ";
	output(fout,root->Next);
}

void delete_pointer(Node *&root){
	if (root==nullptr) return;
	delete_pointer(root->Next);
	delete root;
}


