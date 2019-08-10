#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
int a[maxn][maxn],n,m,need;
vector<vector<vector<int> > > f;
int tinh(int i,int j,int k){
    return f[j][i][k];
}
int main(){
	freopen("SP15_C.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>need;
	f.resize(n+1);
	for (int i=0;i<=n;++i)
        f[i].resize(i+2);
    for (int j=0;j<=n;++j)
        for (int i=1;i<=j+1;++i)
        f[j][i].resize(m+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			cin>>a[i][j];
	for (int j=1;j<=n;++j)
	for (int i=j;i>=1;--i)
	for (int k=1;k<=m;++k)
    f[j][i][k]=f[j][i+1][k]+f[j][i][k-1]-f[j][i+1][k-1]+a[i][k];
	int res=1e9;
	for (int i=1;i<=n;++i)
    for (int j=i;j<=n;++j){
        int l=1;
        int sum=0;
        for (int r=1;r<=m;++r){
            sum+=tinh(i,j,r)-tinh(i,j,r-1);
            while(l<r&&sum-tinh(i,j,l)+tinh(i,j,l-1)>=need) {
                sum-=tinh(i,j,l)-tinh(i,j,l-1);
                ++l;
            }
            if (sum>=need) res=min(res,(j-i+1)*(r-l+1));
        }
    }
    if (res!=1e9) cout<<res;
    else cout<<-1;
}
