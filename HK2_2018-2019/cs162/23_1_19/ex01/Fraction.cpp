/*
 * Fraction.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: huy
 */
#include"Fraction.h"
#define db double
using namespace std;
bool loadArray(const char *path, Fraction a[], int &n){
	ifstream fin(path);
	if (!fin.is_open()){
		return 0;
	}
	fin>>n;
	for (int i=0;i<n;++i){
		fin>>a[i].nu;
		fin>>a[i].de;
	}
	fin.close();
	return 1;
}
bool compare(Fraction p1, Fraction p2){
	db num1=(db)p1.nu/p1.de;
	db num2=(db)p2.nu/p2.de;
	if (num1>num2) return 1;
	return 0;
}
Fraction max(Fraction a[], int n){
	Fraction tmp=a[0];
	for (int i=0;i<n;++i)
		if (compare(a[i],tmp)) {
			tmp=a[i];
		}
	return tmp;
}
bool saveAFraction(const char *path, Fraction p){
	ofstream fout(path);
	if (!fout.is_open())
		return 0;
	fout<<p.nu<<" "<<p.de;
	fout.close();
	return 1;
}
