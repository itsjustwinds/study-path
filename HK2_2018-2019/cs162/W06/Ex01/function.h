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
	Node *Next;
};

void input(ifstream &fin,Node *&root);
void output(ofstream &fout,Node *&cur,Node *&root);
void delete_all(Node *&cur,Node *&root);
int get_min(Node *&root);
void remove_min(Node *&root);


#endif /* FUNCTION_H_ */
