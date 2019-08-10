#include<bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
int n,T;
ll cost[maxn],a[maxn],res,TMP;
ll cal(int i){
	if (cost[i]) return cost[i];
	if (i==1) return a[1];
	ll tmp=2*cal(i-1);
	if (i<=n) tmp=min(tmp,a[i]);
	cost[i]=tmp;
	return tmp;
}
int main(){
	freopen("913C.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	TMP=1e18;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=32;i>=1;--i){
		if (((T>>(i-1))&1)==0){
            TMP=min(TMP,res+cal(i));
            continue;
		}
		res+=cal(i);
	}
	cout<<min(TMP,res);
}
