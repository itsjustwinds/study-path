/*
 * main.cpp
 *
 *  Created on: Mar 16, 2019
 *      Author: huy
 */

#include<iostream>
using namespace std;
int dfs(int *a,int now,int n,int sum,int total,int X){
	if(now==n) {
		if (total+sum==X)
			return 1;
		return 0;
	}
	//////////// +
	if (dfs(a,now+1,n,a[now],total+sum,X)) return 1;
	if (now==0) return 0;
	//////////// -
	if (dfs(a,now+1,n,-a[now],total+sum,X)) return 1;
	//////////// *
	if (dfs(a,now+1,n,sum*a[now],total,X)) return 1;
	//////////// /
	if (dfs(a,now+1,n,sum/a[now],total,X)) return 1;
	return 0;
}
int main(){
	int *a;
	int n,X;
	cin>>n>>X;
	a=new int[n];
	for (int i=0;i<n;++i)
		cin>>a[i];
	if (dfs(a,0,n,0,0,X)) cout<<"YES";
	else cout<<"NO";
	delete[] a;
	return 0;
}
