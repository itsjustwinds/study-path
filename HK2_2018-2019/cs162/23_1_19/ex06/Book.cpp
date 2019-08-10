/*
 * Book.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */

#include"Book.h"

void delete_pointer(book a[],int &n){
	for (int i=0;i<n;++i)
		delete[] a[i].s;
}

bool load_data(const char *path,book a[],int &n){
	ifstream fin(path);
	if (!fin.is_open())
		return 0;
	fin>>n;
	for (int i=0;i<n;++i)
		input(fin,a[i]);
	fin.close();
	return 1;
}

void input(ifstream &fin,book &a){
	char Stmp[5005];
	fin>>a.ID;
	fin.ignore(1000,'\n');
	fin.get(Stmp,5005,'\n');
	a.s=new char[strlen(Stmp)+1];
	strcpy(a.s,Stmp);
	fin>>a.stock;
	fin>>a.price;
}

bool save_data(const char *path,ll res){
	ofstream fout(path);
	if (!fout.is_open())
		return 0;
	fout<<res;
	fout.close();
	return 1;
}

ll get_res(book a[],int &n){
	ll res=0;
	for (int i=0;i<n;++i)
		res+=1ll*a[i].stock*a[i].price;
	return res;
}