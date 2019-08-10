/*
 * Date.h
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */
#pragma once
#ifndef DATE_H_
#define DATE_H_


#include<iostream>
#include<fstream>
using namespace std;
struct date{
	int d,m,y;
};
bool load_data(const char *path,date a[],int &n);
bool save_data(const char *path,date a[],int &n);
bool compare(const date &d1,const date &d2);
void sort(date a[],int &n);

#endif /* DATE_H_ */
