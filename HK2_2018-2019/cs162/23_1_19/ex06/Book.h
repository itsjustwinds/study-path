/*
 * Book.h
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */
#pragma once
#ifndef BOOK_H_
#define BOOK_H_

#include<iostream>
#include<fstream>
#include<string.h>
#define ll long long
using namespace std;

struct book{
	int ID;
	char *s;
	int stock,price;
};

bool load_data(const char *path,book a[],int &n);
bool save_data(const char *path,ll res);
void input(ifstream &fin, book &a);
void delete_pointer(book a[],int &n);
ll get_res(book a[], int &n);

#endif /* BOOK_H_ */
