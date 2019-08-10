/*
 * book.h
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */
#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include<iostream>
#include<cstring>
using namespace std;
struct book{
	char title[200];
	char ISBN[10];
	char author[40];
	char language[30];
	int year_published;
	int price;
	int stock_level;
	book *Next;
};

bool compare(book *&a,book *&b);
bool right(char a[],char b[]);


#endif /* BOOK_H_ */