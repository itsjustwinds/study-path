#include<bits/stdc++.h>
#define maxn 35
#define ll long long
using namespace std;
typedef vector<int > Vi;
map<Vi,ll > Map;
int n,m,mark[maxn];
ll res,cost[maxn];
vector<int > e[maxn];
void dfs1(int i){
	if (i==m/2+1){
		ll sum=0;
		Vi tmp;
		tmp.clear();
		tmp.resize(n);
		for (int j=1;j<=m;++j){
			if (!mark[j]) continue;
			sum+=cost[j];
			for (int id=0;id<e[j].size();++id){
				int x=e[j][id];
				tmp[x-1]++;
			}
		}
		Map[tmp]=sum;
		return;
	}
	dfs1(i+1);
	mark[i]=1;
	dfs1(i+1);
	mark[i]=0;
}
void dfs2(int i){
	if (i==m+1){
		ll sum=0;
		Vi tmp,Need;
		tmp.clear();
		Need.clear();
		tmp.resize(n);
		for (int j=1;j<=n;++j)
			Need.push_back(2);
		for (int j=1;j<=m;++j){
			if (!mark[j]) continue;
			sum+=cost[j];
			for (int id=0;id<e[j].size();++id){
				int x=e[j][id];
				tmp[x-1]++;
			}
		}
		for (int j=0;j<n;++j)
			Need[j]-=tmp[j];
		if (Map[Need]==0) return;
		res=min(res,Map[Need]+sum);
		return ;
	}
	dfs2(i+1);
	mark[i]=1;
	dfs2(i+1);
	mark[i]=0;
}
int main(){
	freopen("CHNREST.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for (int i=1;i<=m;++i){
		cin>>cost[i];
	}
	string s;
	res=1e18;
	getline(cin,s);
	for (int i=1;i<=n;++i){
		getline(cin,s);
		int x=0;
		s=s+' ';
		for (int i=0;i<s.length();++i){
			if (s[i]!=' '){
				x=x*10+s[i]-'0';
				continue;
			}
			e[x].push_back(i);
			x=0;
		}
	}
	dfs1(1);
	dfs2(m/2+1);
	if (res!=1e18)cout<<res;
	else cout<<-1;
}
