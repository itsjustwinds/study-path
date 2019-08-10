/*
 * main.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root;
	int x,y;
	ifstream fin("input.txt");
	input(fin,root,x,y);
	fin.close();
	insert_after(root,x,y,0);
	ofstream fout("output.txt");
	output(fout,root);
	fout.close();
	delete_pointer(root);
	return 0;
}

