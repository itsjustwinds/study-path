/*
 * main.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root;
	ifstream fin("input.txt");
	input(fin,root);
	fin.close();
	ofstream fout("output.txt");
	output(fout,root);
	fout.close();
	delete_pointer(root);
	return 0;
}

