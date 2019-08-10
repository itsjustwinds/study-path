/*
 * Oxy_function.h
 *
 *  Created on: Jan 23, 2019
 *      Author: huy
 */
#pragma once
#ifndef OXY_FUNCTION_H_
#define OXY_FUNCTION_H_
#include<iostream>
#include<fstream>
#include<math.h>
#define db double
using namespace std;
struct point {
	int x,y;
};
bool loadArray(const char *path, point a[], int &n);
db distance(point x);
void sort(point a[], int n);
bool saveFile(const char *path, point a[],int n);
#endif /* OXY_FUNCTION_H_ */