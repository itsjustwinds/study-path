#include<bits/stdc++.h>
#define maxn 105
#define db double
using namespace std;
struct data{
	int u,v;
	db c;
};
vector<data > edge,EDGE;
int root[maxn],n,m,dd[maxn*maxn];
db res,esp,M;
bool check(db m){

}
bool cmp(data a,data b){
	return a.c>b.c;
}
int main(){
	freopen("QBTRANS.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	esp=1e-2;
	for (int i=1;i<=m;++i){
		int u,v;
		db c;
		cin>>u>>v>>c;
		edge.push_back({u,v,c});
	}
	for (int i=1;i<=n;++i)
		root[i]=i;
	int DDD=0;
	sort(edge.begin(),edge.end(),cmp);
	for (int i=0;i<edge.size();++i){
		int u=edge[i].u;
		int v=edge[i].v;
		int ru=getr(u);
		int rv=getr(v);
		if (ru==rv) continue;
		root[ru]=rv;
		++DDD;
		e[u].push_back({v,edge[i].c});
		e[v].push_back({u,edge[i].c});
		if (DDD==n-1) break;
	}
	res=-1;
	while(r-l>esp){
		M=(l+r)/2;
		if (check(M)){
			res=M;
			l=M;
		}
		else r=M;
	}
	if (res==-1) cout<<-1;
	else cout<<setprecision(2)<<fixed<<res;
}