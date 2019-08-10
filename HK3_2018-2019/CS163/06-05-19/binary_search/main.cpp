/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: huy
 */

#include<iostream>
using namespace std;

int get(int* a,int n,int x){
	int resL = -1,resR = -1;
	int l = 0,r = n - 1;
	while(l <= r){
		int m = (l + r)>>1;
		if (a[m] >= x){
			resL = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	l = 0,r = n - 1;
	while(l <= r){
		int m = (l + r)>>1;
		if (a[m] <= x){
			resR = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	if (resL == -1) return 0;
	if (a[resL] == x){
		return resR - resL + 1;
	}
	return 0;
}

int main(){
	int* a;
	int n,x;
	cin>>n;
	a=new int[n];
	for (int i=0;i<n;++i)
		cin>>a[i];
	cin>>x;
	cout<<get(a,n,x);
	delete[] a;
}

