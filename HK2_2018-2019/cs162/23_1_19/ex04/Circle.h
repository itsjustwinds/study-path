/*
 * Circle.h
 *
 *  Created on: Jan 23, 2019
 *      Author: huy
 */

#pragma once
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include<iostream>
#include<fstream>
#include<iomanip>
#define db double
#define Pi (db)3.14159265359
using namespace std;

struct circle{
	int x,y;
	db r;
};
bool load_array(const char *path,circle a[],int &n);
db get_val(circle a);
db get_sum(circle a[],int &n);
bool save_file(const char *path,double &res);
#endif /* CIRCLE_H_ */
