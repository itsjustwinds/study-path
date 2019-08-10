/*
 * main.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */
#include"function.h"

int main(){
	ifstream fin;
	Node *listA=nullptr;
	Node *listB=nullptr;
	Node *res=nullptr;
	fin.open("input1.txt");
	input(fin,listA);
	fin.close();
	fin.open("input2.txt");
	input(fin,listB);
	fin.close();
	create_list(listA,listB,res);
	ofstream fout("output.txt");
	output(fout,res);
	fout.close();
	delete_pointer(res);
}


