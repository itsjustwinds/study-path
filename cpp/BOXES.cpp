#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct data{
	int u,v,f,c,cost;
};
vector<data > edge;
vector<int >g[maxn];
int n,a[maxn],s,t,d[maxn];
void add_edge(int u,int v,int c,int cost){
	g[u].push_back(edge.size());
	edge.push_back({u,v,0,c,cost});
	g[v].push_back(edge.size());
	edge.push_back({v,u,0,0,-cost});
}
int bef[maxn];
struct cmp{
    bool operator ()(data a,data b){
        return a.cost>b.cost;
    }
};
bool dijks(){
	priority_queue<data,vector<data>,cmp > q;
	for (int i=1;i<=n+2;++i)
		d[i]=1e9;
	d[s]=0;
	q.push({s,0,0,0,0});
	while(!q.empty()){
		int u=q.top().u;
		int COST=q.top().cost;
		q.pop();
		if (COST!=d[u]) continue;
		for (int i=0;i<g[u].size();++i){
			int id=g[u][i];
			int v=edge[id].v;
			int cost=edge[id].cost;
			if (d[u]+cost>=d[v]||edge[id].f==edge[id].c) continue;
			d[v]=d[u]+cost;
			bef[v]=id;
			q.push({v,0,0,0,d[v]});
		}
	}
	return d[t]!=1e9;
}
int turn(){
	int T=t;
	int maxx=1e9;
	while(T!=s){
		int id=bef[T];
		int u=edge[id].u;
		maxx=min(maxx,edge[id].c-edge[id].f);
		T=u;
	}
	T=t;
	while(T!=s){
		int id=bef[T];
		int u=edge[id].u;
		edge[id].f+=maxx;
		edge[id^1].f-=maxx;
		T=u;
	}
	return maxx;
}
void solve(){
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	edge.clear();
	for (int i=1;i<=n+2;++i)
		g[i].clear();
	s=n+1;t=n+2;
	for (int i=1;i<n;++i){
		add_edge(i,i+1,1e5,1);
		add_edge(i+1,i,1e5,1);
	}
	add_edge(1,n,1e5,1);
	add_edge(n,1,1e5,1);
	for (int i=1;i<=n;++i)
		add_edge(s,i,a[i],0);
	for (int i=1;i<=n;++i)
		add_edge(i,t,1,0);
	int ans=0;
	while(dijks()){
		int x=turn();
		ans+=d[t];
	}
	cout<<ans;
}
int main(){
	freopen("BOXES.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while(test--){
		solve();
		cout<<"\n";
	}
}
