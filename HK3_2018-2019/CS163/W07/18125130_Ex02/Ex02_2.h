/*
 * Ex02_2.h
 *
 *  Created on: Jul 10, 2019
 *      Author: huy
 */
#pragma once
#ifndef EX02_2_H_
#define EX02_2_H_
#include<iostream>
#include<vector>
using namespace std;
void input(int &n, int &begin, int &finish,int* &bef, int** &edge);
void dfs(int &n,int &now,int &begin,int &finish,int* &bef, int** &edge,vector<int > &res);
void answer2();
#endif /* EX02_2_H_ */