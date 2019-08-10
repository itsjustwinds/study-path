/*
 * Student.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */

#include"Student.h"

void delete_pointer(student a[],int &n){
	for (int i=0;i<n;++i)
		delete[] a[i].name;
}

bool load_data(const char *path, student a[],int &n){
	ifstream fin(path);
	if (!fin.is_open())
		return 0;
	fin>>n;
	for (int i=0;i<n;++i)
		input(fin,a[i]);
	fin.close();
	return 1;
}

void input(ifstream &fin, student &a){
	fin>>a.ID;
	char Stmp[5005];
	fin.ignore(5005,'\n');
	fin.get(Stmp,5005,'\n');
	a.name=new char[strlen(Stmp)+1];
	strcpy(a.name,Stmp);
	fin>>a.GPA;
}

student max(student &a, student &b){
	if (a.GPA!=b.GPA) {
		if (a.GPA>b.GPA) return a;
		return b;
	}
	if (a.ID<b.ID) return a;
	return b;
}

student best_of_list(student a[],int &n){
	student res=a[0];
	for (int i=1;i<n;++i)
		res=max(res,a[i]);
	return res;
}

bool save_data(const char *path, student &a){
	ofstream fout(path);
	if (!fout.is_open()) return 0;
	fout<<a.ID<<"\n";
	fout<<a.name<<"\n";
	fout<<a.GPA<<"\n";
	return 1;
}
