/*
 * Ex02_1.h
 *
 *  Created on: Jul 10, 2019
 *      Author: huy
 */
#pragma once
#ifndef EX02_1_H_
#define EX02_1_H_
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void input(int &n, int &begin, int &finish, int** &edge);
void bfs(int &n,int &begin,int &finish,int** &edge,vector<int > &res);
void answer1();




#endif /* EX02_1_H_ */