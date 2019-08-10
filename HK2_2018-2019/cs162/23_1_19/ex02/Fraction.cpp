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
bool compare (Fraction p1, Fraction p2){
	db num1=(db)p1.nu/p1.de;
	db num2=(db)p2.nu/p2.de;
	if (num1>num2) return 1;
	return 0;
}
bool saveAFraction(const char *path, Fraction a[],int n){
	ofstream fout(path);
	if (!fout.is_open())
		return 0;
	fout<<n<<"\n";
	for (int i=0;i<n;++i){
		fout<<a[i].nu<<" "<<a[i].de<<"\n";
	}
	fout.close();
	return 1;
}
void sortAsc(Fraction a[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(compare(a[i],a[j])) {
				Fraction temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
