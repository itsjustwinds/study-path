/*
 * function.cpp
 *
 *  Created on: Mar 8, 2019
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

void get_list(Node *&root,Node *&odd,Node *&even){
	int cnt=0;
	Node *cur_odd=odd;
	Node *cur_even=even;
	for (Node *cur=root;cur!=nullptr;cur=cur->Next){
		++cnt;
		if (cnt%2==1){
			if (cur_odd==nullptr){
				odd=cur;
				cur_odd=odd;
				continue;
			}
			cur_odd->Next=cur;
			cur_odd=cur_odd->Next;
		}
		if (cnt%2==0){
			if (cur_even==nullptr){
				even=cur;
				cur_even=even;
				continue;
			}
			cur_even->Next=cur;
			cur_even=cur_even->Next;
		}
	}
	if (cur_even!=nullptr) cur_even->Next=nullptr;
	if (cur_odd!=nullptr) cur_odd->Next=nullptr;
}
