/*
 * main.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: huy
 */
#include"function.h"
int main(){
	Node *root=new Node;
	int x,y;
	ifstream fin("input.txt");
	input(fin,root,x,y);
	fin.close();
	insert(root,x,y);
	ofstream fout("output.txt");
	output(fout,root);
	fout.close();
	delete_pointer(root);
	return 0;
}



