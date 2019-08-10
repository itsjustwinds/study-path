/*
 * main.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */
#include"function.h"

int main(){
	ifstream fin;
	Node *left=nullptr;
	Node *right=nullptr;
	fin.open("input1.txt");
	input(fin,left);
	fin.close();
	fin.open("input2.txt");
	input(fin,right);
	fin.close();
	create_list(left,right);
	ofstream fout("output.txt");
	output(fout,left);
	fout.close();
	delete_pointer(left);
}


