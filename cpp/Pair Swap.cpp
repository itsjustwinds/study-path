#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int P[maxn][35],n,a[maxn],k;
int get(int l,int r){
	int log=log2(r-l+1);
	int x=P[l][log];
	int y=P[r-(1<<log)+1][log];
	if (a[x]<a[y]) return x;
	else return y;
}
int main(){
	freopen("Pair Swap.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		P[i][0]=i;
	for (int j=1;1<<j<=n;++j)
	for (int i=1;i+(1<<j)-1<=n;++i){
		int x=P[i][j-1];
		int y=P[i+(1<<(j-1))][j-1];
		if (a[x]<a[y]) P[i][j]=x;
		else P[i][j]=y;
	}
	for (int i=1;i<n;++i){
		int x=get(i+1,min(n,i+k));
		if (a[i]>a[x]){
			swap(a[i],a[x]);
			for (int i=1;i<=n;++i)
				cout<<a[i]<<" ";
			return 0;
		}
	}
			for (int i=1;i<=n;++i)
				cout<<a[i]<<" ";
}
