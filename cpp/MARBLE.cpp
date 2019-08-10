#include<bits/stdc++.h>
#define maxn 605
using namespace std;
int f[maxn][maxn],n,m,a[maxn],b[maxn],K;
int main(){
	freopen("MARBLE.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>K;
	for (int i=1;i<=K;++i)
		cin>>a[i]>>b[i];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			f[i][j]=i*j;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			for(int k=1;k<=K;++k){
				int tmp=1e9;
				if (i<a[k]||j<b[k]) continue;
				tmp=min(tmp,f[i-a[k]][j-b[k]]);
				tmp=min
			}
		}
}
