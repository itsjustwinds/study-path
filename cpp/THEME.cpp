#include<bits/stdc++.h>
#define maxn 5005
#define ll long long
#define fs first
#define sc second
#define mod 1000000007
using namespace std;
typedef pair<int,int > II;
II f[maxn],power[maxn],Base;
int a[maxn],n,Num[maxn],res;
map<II,int > Mark;
bool check(int k){
	Mark.clear();
	II now=II(0,0);
	for (int i=2;i<=k;++i)
		now=II(((1ll*now.fs*Base.fs)%mod+Num[i])%mod,((1ll*now.sc*Base.sc)%mod+Num[i])%mod);
	f[1]=now;
	for (int i=k+1;i<=n;++i){
		now.fs=(now.fs-(1ll*Num[i-k+1]*power[k-2].fs)%mod+mod)%mod;
		now.sc=(now.sc-(1ll*Num[i-k+1]*power[k-2].sc)%mod+mod)%mod;
		now.fs=((1ll*now.fs*Base.fs)%mod+Num[i])%mod;
		now.sc=((1ll*now.sc*Base.sc)%mod+Num[i])%mod;
		if (i>=2*k) Mark[f[i-2*k+1]]=1;
		if (Mark[now]) return 1;
		f[i-k+1]=now;
	}
	return 0;
}
int main(){
	freopen("THEME.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=2;i<=n;++i)
		Num[i]=a[i]-a[i-1]+100;
	Base=II(137,179);
	power[0]=II(1,1);
	for (int i=1;i<=n;++i)
		power[i]=II((1ll*power[i-1].fs*Base.fs)%mod,(1ll*power[i-1].sc*Base.sc)%mod);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if (res>=5)cout<<res;
	else cout<<0;
	return 0;
}
