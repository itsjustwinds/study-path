#include<bits/stdc++.h>
#define ll long long
#define maxn 100
using namespace std;
int n;
vector<ll > p1,p2;
ll a[maxn];
void dfs1(int i,ll sum){
	if (i==n/2+1){
		p1.push_back(sum);
		return;
	}
	dfs1(i+1,sum);
	dfs1(i+1,sum+a[i]);
}
void dfs2(int i,ll sum){
	if (i==n+1){
		p2.push_back(sum);
		return;
	}
	dfs2(i+1,sum);
	dfs2(i+1,sum+a[i]);
}
int main(){
	freopen("trade.inp","r",stdin);
	//freopen("trade.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int test;
	scanf("%d%d",&n,&test);
	for (int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	dfs1(1,0);
	dfs2(n/2+1,0);
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());
	unique(p1.begin(),p1.end());
	unique(p2.begin(),p2.end());
	while(test--){
		ll m;
		ll res=0;
		scanf("%lld",&m);
		int now=p2.size()-1;
		for (int i=0;i<p1.size();++i){
			ll x=p1[i];
			if (x>m) break;
			while(now<p2.size()&&x+p2[now]>m)
                --now;
			if (now>=0)res=max(res,x+p2[now]);
			else res=max(res,x);
		}
		printf("%lld\n",res);
	}
}
