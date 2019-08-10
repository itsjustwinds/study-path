/*
 * Ex02_1.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: huy
 */
#include"Ex02_2.h"

void input(int &n, int &begin, int &finish,int* &bef, int** &edge){
	cin>>n>>begin>>finish;
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

void dfs(int &n,int &now,int &begin,int &finish,int* &bef, int** &edge,vector<int > &res){
	if (now==finish){
		int x=finish;
		while(x!=begin){
			res.push_back(x);
			x=bef[x];
		}
		res.push_back(x);
		return;
	}
	if (bef[finish]!=-1) return;
	for (int i=0;i<n;++i){
		if (bef[i]!=-1||edge[now][i]==0) continue;
		bef[i]=now;
		dfs(n,i,begin,finish,bef,edge,res);
	}
}

void answer2(){
	int n,begin,finish;
	int *bef;
	int **edge;
	vector<int > res;
	input(n,begin,finish,bef,edge);
	dfs(n,begin,begin,finish,bef,edge,res);
	for (int i=res.size()-1;i>=0;--i)
		cout<<res[i]<<" ";
	for (int i=0;i<n;++i){
		delete[] edge[i];
		edge[i]=NULL;
	}
	delete[] edge;
	delete[] bef;
	bef=NULL;
	edge=NULL;
}
