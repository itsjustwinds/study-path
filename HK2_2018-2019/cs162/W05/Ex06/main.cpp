/*
 * main.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */
#include"function.h"

int main(){
	ifstream fin;
	Node *root=nullptr;
	int res=0;
	fin.open("input.txt");
	input(fin,root);
	fin.close();
	cal_num(root,res);
	ofstream fout("output.txt");
	fout<<res;
	fout.close();
	delete_pointer(root);
}

