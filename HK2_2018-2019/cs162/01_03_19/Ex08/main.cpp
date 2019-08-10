/*
 * main.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: huy
 */
#include"function.h"
int main(){
	int x;
	Node *root=new Node;
	ifstream fin("input.txt");
	input(fin,root,x);
	fin.close();
	delete_X(root,x);
	ofstream fout("output.txt");
	output(fout,root);
	fout.close();
	delete_pointer(root);
	return 0;
}



