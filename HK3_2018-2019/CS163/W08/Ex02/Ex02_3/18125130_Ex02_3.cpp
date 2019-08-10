/*
 * 18125130_Ex02_3.cpp
 *
 *  Created on: Jul 17, 2019
 *      Author: huy
 */

#include<iostream>
#include<vector>
using namespace std;
void dfs1(int u,int stage,vector<int > *&e,int *&s,int *&a,int *&par){
	if (stage%2==0) {
		int p=par[u];
		int minn=1e9;
		for (int i=0;i<e[u].size();++i){
			int v=e[u][i];
			dfs1(v,stage+1,e,s,a,par);
			minn=min(minn,s[v]);
		}
		s[u]=minn;
		if (minn==1e9) s[u]=s[p];
		return;
	}
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		dfs1(v,stage+1,e,s,a,par);
	}
}
void dfs2(int u,int stage,vector<int > *&e,int *&s,int *&a,int *&par){
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		a[v]=s[v]-s[u];
		dfs2(v,stage+1,e,s,a,par);
	}
}
int main(){
	int n;
	vector<int> *e;
	int *s,*a,*par;
	cin>>n;
	s=new int[n+1];
	a=new int[n+1];
	par=new int[n+1];
	e=new vector<int>[n+1];
	for (int i=2;i<=n;++i){
		int p;
		cin>>p;
		e[p].push_back(i);
		par[i]=p;
	}
	for (int i=1;i<=n;++i){
		cin>>s[i];
	}
	a[1]=s[1];
	dfs1(1,1,e,s,a,par);
	dfs2(1,1,e,s,a,par);
	long long res=0;
	for (int i=1;i<=n;++i){
		if (a[i]<0) {
			cout<<-1;
			return 0;
		}
		res+=a[i];
		//cout<<s[i]<<" "<<a[i]<<"\n";
	}
	cout<<res;
}


