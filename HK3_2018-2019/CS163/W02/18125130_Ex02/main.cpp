/*
 * main.cpp
 *
 *  Created on: May 22, 2019
 *      Author: huy
 */

#include"BST.h"

int main(){
	int* a;
	int n;
	cin>>n;
	a=new int[n];
	for (int i=0;i<n;++i)
		cin>>a[i];
	BST x(a,n);
	delete[] a;
	a=nullptr;
	Node* res=nullptr;
	x.predecessor(x.root,5,res);
	if (res!=nullptr) printf("%d",res->val);
	else printf("no noob");
	x.delete_tree(x.root);
}