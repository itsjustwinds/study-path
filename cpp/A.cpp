#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
ll n,m,w[maxn],val[maxn],d[4][maxn],cnt[4];
ll res,Sum[4][maxn];
void dfs(ll i,ll sum,ll val){
    if (sum>m) return;
	if (i==4){
		if (sum>m) return;
		res=max(res,val);
		return;
	}
	for (ll j=0;j<=cnt[i];++j){
		dfs(i+1,sum+j*(w[1]+i),val+Sum[i][j]);
	}
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
	//freopen("A.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (ll i=1;i<=n;++i)
		cin>>w[i]>>val[i];
	for (ll i=1;i<=n;++i){
		ll x=w[i]-w[1];
		cnt[x]++;
		d[x][cnt[x]]=val[i];
	}
	sort(d[0]+1,d[0]+cnt[0]+1,cmp);
	sort(d[1]+1,d[1]+cnt[1]+1,cmp);
	sort(d[2]+1,d[2]+cnt[2]+1,cmp);
	sort(d[3]+1,d[3]+cnt[3]+1,cmp);
	for (ll k=0;k<=3;++k){
		for (ll j=1;j<=cnt[k];++j)
			Sum[k][j]=Sum[k][j-1]+d[k][j];
	}
	dfs(0,0,0);
	cout<<res;
}
