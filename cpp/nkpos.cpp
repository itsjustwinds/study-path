#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,res[maxn*maxn],cnt,deg[maxn],cur[maxn],S[maxn*maxn],dem,dd[maxn*maxn];
vector<int > g[maxn];
int m;
struct data{
	int u,v;
};
vector<data > edge;
void solve(){
	S[++dem]=1;
	while(dem){
		int u=S[dem];
		while(cur[u]<deg[u]&&dd[g[u][cur[u]]]) ++cur[u];
		if (cur[u]==deg[u]){
			res[++cnt]=u;
			--dem;
			continue;
		}
		int id=g[u][cur[u]];
		int v;
		if (u==edge[id].u) v=edge[id].v;
		else v=edge[id].u;
		dd[id]=1;
		S[++dem]=v;
	}
}
int main(){
	freopen("NKPOS.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		int x;
		cin>>x;
	}
	for (int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(edge.size());
		g[v].push_back(edge.size());
		edge.push_back({u,v});
		deg[u]++;deg[v]++;
	}
	solve();
	cout<<cnt-1<<"\n";
	for (int i=1;i<=cnt;++i)
		cout<<res[i]<<" ";
}
