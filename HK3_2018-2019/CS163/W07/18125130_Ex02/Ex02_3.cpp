/*
 * Ex02_1.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: huy
 */
#include"Ex02_2.h"

void input(int &n,int* &bef, int** &edge){
	cin>>n;
	edge=new int*[n];
	for (int i=0;i<n;++i)
		edge[i]=new int[n];
	int u,v;
	while(cin>>u){
		cin>>v;
		edge[u][v]=1;
	}
	bef=new int[n];
	for (int i=0;i<n;++i)
		bef[i]=-1;
}

void dfs(int &n,int &now,int* &bef, int** &edge){

	for (int i=0;i<n;++i){
		if (bef[i]!=-1||edge[now][i]==0) continue;
		bef[i]=now;
		dfs(n,i,bef,edge);
	}
}

void answer3(){
	int n;
	int *bef;
	int **edge;
	int res=0;
	input(n,bef,edge);
	for (int i=0;i<n;++i)
	if(bef[i]==-1){
		++res;
		dfs(n,i,bef,edge);
	}
	cout<<res;
	for (int i=0;i<n;++i){
		delete[] edge[i];
		edge[i]=NULL;
	}
	delete[] edge;
	delete[] bef;
	bef=NULL;
	edge=NULL;
}