#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
stack<int > s;
int m,n,num[maxn],low[maxn],cur[maxn],ans,cnt,d;
vector<int > e[maxn];
void dfs(int u,int trc){
	num[u]=low[u]=++cnt;
	if (u==8){
        int K=0;
	}
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (v==trc) continue;
		if (num[v]) low[u]=min(low[u],num[v]);
		else {
			s.push(u);
			dfs(v,u);
			low[u]=min(low[v],low[u]);
			if (low[v]<num[u]) continue;
			int dem=0;
			++d;
			do{
				v=s.top();s.pop();
				if (cur[v]<d) {
					++dem;
					cur[v]=d;
				}
			}while(v!=u);
			ans=max(ans,dem);
		}
	}
	s.push(u);
}
int main(){
	freopen("SAFENET2.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=n;++i)
	if (!num[i]) dfs(i,-1);
	cout<<max(ans,1);
}
