/*
 * main.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root=new Node;
	Node *sum=new Node;
	ifstream fin("input.txt");
	input(fin,root);
	fin.close();
	get_sum(root,sum);
	ofstream fout("output.txt");
	output(fout,sum);
	fout.close();
	delete_pointer(sum);
	delete_pointer(root);
	return 0;
}

