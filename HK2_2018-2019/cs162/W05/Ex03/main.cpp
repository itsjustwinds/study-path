/*
 * main.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	Node *root=nullptr;
	Node *odd=nullptr;
	Node *even=nullptr;
	ifstream fin("input.txt");
	input(fin,root);
	fin.close();
	get_list(root,odd,even);
	ofstream fout;
	fout.open("output1.txt");
	output(fout,odd);
	fout.close();
	fout.open("output2.txt");
	output(fout,even);
	fout.close();
	delete_pointer(odd);
	delete_pointer(even);
	return 0;
}

