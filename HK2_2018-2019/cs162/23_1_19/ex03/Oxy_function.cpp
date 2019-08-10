/*
 * Oxy_function.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: huy
 */
#include"Oxy_function.h"
bool loadArray(const char *path, point a[], int &n){
	ifstream fin(path);
	if (!fin.is_open()){
		return 0;
	}
	fin>>n;
	for (int i=0;i<n;++i){
		fin>>a[i].x;
		fin>>a[i].y;
	}
	fin.close();
	return 1;
}
db distance(point x){
	db res;
	res=sqrt((db)x.x*x.x+(db)x.y*x.y);
	return res;
}
void sort(point a[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(distance(a[i])<distance(a[j])) {// a[i] < a[j]
				point temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
bool saveFile(const char *path, point a[],int n){
	ofstream fout(path);
	if (!fout.is_open())
		return 0;
	fout<<n<<"\n";
	for (int i=0;i<n;++i)
		fout<<a[i].x<<" "<<a[i].y<<"\n";
	fout.close();
	return 1;
}

