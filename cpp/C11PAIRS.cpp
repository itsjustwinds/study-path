#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
int d[maxn],Left,Right;
int n,a[maxn],P[maxn][30];
ll res;
int get(int i,int j){
	int log=log2(j-i+1);
	return max(P[i][log],P[j-(1<<log)+1][log]);
}
int Find(int l,int r,int x){
	int res=0;
	while(l<=r){
		int m=(l+r)>>1;
		if (get(m,x)<=a[x]){
			res=m;
			r=m-1;
		}
		else l=m+1;
	}
	return res-1;
}
int findD(int l,int r,int x){
	int res=r;
	while(l<=r){
		int m=(l+r)>>1;
		if (d[m]>=x){
			res=m;
			r=m-1;
		}
		else l=m+1;
	}
	return res;
}
int main(){
	freopen("C11PAIRS.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		P[i][0]=a[i];
	for (int j=1;1<<j<=n;++j){
		for (int i=1;i+(1<<j)-1<=n;++i)
			P[i][j]=max(P[i][j-1],P[i+(1<<(j-1))][j-1]);
	}
	Left=Right=1;
	d[1]=1;
	for (int i=2;i<=n;++i){
		int Pos=Find(1,i,i);
		int K=findD(Left,Right,Pos);
		res+=Right-K+1;
		while(Left<=Right&&a[d[Right]]<a[i]) Right--;
		d[++Right]=i;
	}
	cout<<res;
}
