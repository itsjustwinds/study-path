#include<bits/stdc++.h>
#define maxn 205
using namespace std;
char S[maxn][maxn];
int n,m,s,t,Begin,cnt,dd[maxn],high[maxn],pos[maxn];
struct data{
	int u,v,f,c;
};
vector<int > g[maxn];
vector<data > edge;
void add_edge(int u,int v,int c){
	g[u].push_back(edge.size());
	edge.push_back({u,v,0,c});
	g[v].push_back(edge.size());
	edge.push_back({v,u,0,0});
}
bool bfs(){
	queue<int > q;
	dd[s]=++cnt;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		pos[u]=0;
		for (int i=0;i<g[u].size();++i){
			int id=g[u][i];
			int v=edge[id].v;
			if (dd[v]==cnt||edge[id].f==edge[id].c) continue;
			dd[v]=cnt;
			high[v]=high[u]+1;
			q.push(v);
		}
	}
	return dd[t]==cnt;
}
int dfs(int u,int low){
	if (u==t||low==0) return low;
	for (;pos[u]<g[u].size();++pos[u]){
		int id=g[u][pos[u]];
		int v=edge[id].v;
		if (high[v]!=high[u]+1||edge[id].f==edge[id].c) continue;
		int x=dfs(v,min(low,edge[id].c-edge[id].f));
		if (x){
			edge[id].f+=x;
			edge[id^1].f-=x;
			return x;
		}
	}
	return 0;
}
bool check(int X){
	while(edge.size()!=Begin){
		data T=edge.back();
		edge.pop_back();
		g[T.u].pop_back();
	}
	for (int i=0;i<edge.size();++i)
		edge[i].f=0;
	for (int i=1;i<=n;++i)
		add_edge(s,i,X);
	int ans=0;
	while(bfs()){
		int x;
		while(1){
			x=dfs(s,1e9);
			if (x==0) break;
			ans+=x;
			if (ans>=2*m) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("TWOBLACK.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int j=1;j<=n;++j)
		for (int i=m;i>=1;--i)
			cin>>S[i][j];
	swap(n,m);
	s=n+m+1,t=n+m+2;
	for (int i=1;i<=m;++i)
		add_edge(i+n,t,2);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (S[i][j]=='1') add_edge(i,j+n,1);
	Begin=edge.size();
	int l=1,r=m;
	int res=0;
	while(l<=r){
		int M=(l+r)>>1;
		if (check(M)){
			res=M;
			r=M-1;
		}
		else l=M+1;
	}
	cout<<res;
}
