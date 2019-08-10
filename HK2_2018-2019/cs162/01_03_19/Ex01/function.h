/*
 * function.h
 *
 *  Created on: Mar 1, 2019
 *      Author: huy
 */
#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<iostream>
#include<fstream>
using namespace std;
struct Node{
	int val;
	Node *Next;
};
void input(ifstream &fin, Node *&root);
void output(ofstream &fout, Node *&root);
void delete_pointer(Node *&root);

#endif /* FUNCTION_H_ */
