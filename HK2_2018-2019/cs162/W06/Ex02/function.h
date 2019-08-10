/*
 * function.h
 *
 *  Created on: Mar 21, 2019
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
	Node *Prev,*Next;
};
void input(ifstream &fin,Node *&root);
void output(ofstream &fout,Node *&root);
void delete_all(Node *&root);
void insert(Node *&root,int X);
void remove_all(Node *&root,int X);
void remove_dups(Node *&root);


#endif /* FUNCTION_H_ */