/*
 * 18125130_Ex02_2.cpp
 *
 *  Created on: Jul 17, 2019
 *      Author: huy
 */

#include<iostream>
#include<vector>
using namespace std;
void dijkstra(int s,int t,int n,int **&a,int *&d){
	for (int i=1;i<=n;++i)
		d[i]=1e9;
	d[s]=0;
	vector<int > arr;
	arr.clear();
	arr.push_back(s);
	while(arr.size()){
		int u=0;
		for (int i=0;i<arr.size();++i)
			if (d[arr[i]]<d[arr[u]]) u=i;
		swap(arr[u],arr.back());
		u=arr.back();
		arr.pop_back();
		for (int v=1;v<=n;++v){
			if (a[u][v]==0) continue;
			if (d[u]+a[u][v]<d[v]){
				d[v]=d[u]+a[u][v];
				arr.push_back(v);
			}
		}
	}
}
int main(){
	int n,m;
	int **a;
	int *d;
	int s,t;
	cin>>n>>m>>s>>t;
	a=new int*[n+1];
	d=new int[n+1];
	for (int i=1;i<=n;++i)
		a[i]=new int[n+1];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			cin>>a[i][j];
	dijkstra(s,t,n,a,d);
	cout<<d[t]<<"\n";
	for (int i=1;i<=n;++i)
		cout<<d[i]<<" ";
}

