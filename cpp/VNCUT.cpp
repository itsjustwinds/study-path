#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int f[maxn][maxn],n,m;
int cal(int n,int m){
	if (n==m) return 1;
	if (n<m) swap(n,m);
	if (f[n][m]) return f[n][m];
	f[n][m]=1e9;
	for (int i=1;i<=(m+1)>>1;++i)
		f[n][m]=min(f[n][m],cal(n,i)+cal(n,m-i));
	for (int i=1;i<=(n+1)>>1;++i)
		f[n][m]=min(f[n][m],cal(i,m)+cal(n-i,m));
	return f[n][m];
}
int main(){
	freopen("VNCUT.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cout<<cal(n,m);
}
