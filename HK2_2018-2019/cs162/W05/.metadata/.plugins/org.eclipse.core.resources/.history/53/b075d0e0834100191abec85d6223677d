/*
 * main.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root=new Node;
	int n;
	ifstream fin("input.txt");
	input(fin,root,n);
	fin.close();
	insert(root,n);
	ofstream fout("output.txt");
	output(fout,root);
	fout.close();
	delete_pointer(root);
	return 0;
}

