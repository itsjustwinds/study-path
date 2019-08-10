#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 5000000
using namespace std;
ll bit[55][maxn],g[55][maxn];
int n,k,a[maxn],maxx;
void update(int u,int level,int val){
	while(u<maxn){
		bit[level][u]+=val;
		u+=u&(-u);
	}
}
ll get(int u,int level){
	ll res=0;
	while(u){
		res=(res+bit[level][u])%mod;
		u-=u&(-u);
	}
	return res;
}
int main(){
	freopen("INCVN.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		a[i]++;
		maxx=max(maxx,a[i]);
	}
	update(1,0,1);
	for (int i=1;i<=n;++i)
	for (int j=k;j>=1;--j){
		int tmp=get(a[i],j-1);
		update(a[i]+1,j,tmp);
	}
	cout<<get(maxx+1,k);
	return 0;
}
