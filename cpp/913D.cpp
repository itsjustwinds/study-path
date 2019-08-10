#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
int n,T;
struct data{
	int Max,Time;
};
data a[maxn],TMP[maxn];
int cnt,res;
vector<int > ans;
bool cmp(data a,data b){
    return a.Max<b.Max;
}
bool check(int m){
	cnt=0;
	for (int i=1;i<=n;++i)
	if (a[i].Max>=m) TMP[++cnt]={a[i].Time,i};
	sort(TMP+1,TMP+cnt+1,cmp);
	ll sum=0;
	if (cnt<m) return 0;
	for (int i=1;i<=m;++i)
		sum+=TMP[i].Max;
	if (sum>T) return 0;
	ans.clear();
	for (int i=1;i<=m;++i)
        ans.push_back(TMP[i].Time);
    return 1;
}
int main(){
	//freopen("913D.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	for (int i=1;i<=n;++i)
		cin>>a[i].Max>>a[i].Time;
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)>>1;
		if (check(m)){
			res=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout<<res<<"\n";
	cout<<ans.size()<<"\n";
	for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}
