#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int n,a[maxn],L,R,b[maxn],dd[maxn];
ll res,sum[maxn],bit[maxn];
vector<ll > AC;
void update(int u){
	while(u<maxn){
		bit[u]++;
		u+=u&(-u);
	}
}
int get(int u){
	int res=0;
	while(u){
		res+=bit[u];
		u-=u&(-u);
	}
	return res;
}
int main(){
	freopen("C11SEQ.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>L>>R;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		sum[i+n]=sum[i]-L;
		sum[i+2*n]=sum[i]-R;
		AC.push_back(sum[i]);
		AC.push_back(sum[i+n]);
		AC.push_back(sum[i+2*n]);
	}
	AC.push_back(0);
	sort(AC.begin(),AC.end());
	AC.resize(unique(AC.begin(),AC.end())-AC.begin());
	int TTT=lower_bound(AC.begin(),AC.end(),0)-AC.begin()+1;
	for (int i=1;i<=3*n;++i)
		b[i]=lower_bound(AC.begin(),AC.end(),sum[i])-AC.begin()+1;
	update(TTT);
	for (int i=1;i<=n;++i){
		res+=get(b[i+n])-get(b[i+2*n])+dd[b[i+2*n]];
		update(b[i]);
		dd[b[i]]++;
	}
	cout<<res;
}
