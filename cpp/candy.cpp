#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int n,a[maxn],m,now;
ll f[maxn][2],res;
ll go(){
	f[1][0]=0;
	f[1][1]=a[1];
	for (int i=2;i<=n;++i){
		f[i][0]=max(f[i-1][1],f[i-1][0]);
		f[i][1]=f[i-1][0]+a[i];
	}
	return max(f[n][0],f[n][1]);
}
int main(){
	//freopen("CANDY.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	now=1;
	for (int k=1;k<=m;++k){
		int X,T;
		now=k;
		cin>>T>>X;
		a[T]=X;
		res+=go();
	}
	cout<<res;
}
