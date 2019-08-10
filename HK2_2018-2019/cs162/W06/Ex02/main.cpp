/*
 * main.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root;
	ifstream fin("input.txt");
	input(fin,root);
	fin.close();
	ofstream fout;
	fout.open("output1.txt");
	insert(root,100);
	output(fout,root);
	fout.close();
	fout.open("output2.txt");
	remove_dups(root);
	output(fout,root);
	fout.close();
	delete_all(root);
	return 0;
}
