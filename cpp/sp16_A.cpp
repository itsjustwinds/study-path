#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn],n,m;
int res;
bool check(int M){
    if (b[1]>=M&&a[n]>=M) return 1;
    if (a[1]>=M&&b[m]>=M) return 1;
	if (a[1]>=M&&a[n]>=M){
		for (int i=1;i<=m;++i)
			if (b[i]>=M) return 1;
	}
	if (b[1]>=M&&b[m]>=M){
		for (int i=1;i<=n;++i)
			if (a[i]>=M) return 1;
	}
	return 0;
}
int main(){
	//freopen("SP16_A.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
	int l=1,r=1e9;
	while(l<=r){
		int M=(l+r)>>1;
		if (check(M)){
			res=M;
			l=M+1;
		}
		else r=M-1;
	}
	cout<<res;
}
