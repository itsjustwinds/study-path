#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct data{
	int u,v,c,le,ri,id;
};
vector<data > edge;
vector<int > e[maxn];
int n,m,s,t,start,len,Next[maxn*maxn];
int d[maxn*maxn];
struct cmp{
    bool operator ()(data a,data b){
        return a.c>b.c;
    }
};
void dijks(){
	priority_queue<data,vector<data >,cmp > q;
	for (int i=0;i<edge.size();++i){
		int u=edge[i].u;
		int v=edge[i].v;
		d[i]=1e9;
		if (u!=s) continue;
		if (start<edge[i].le||start>=edge[i].ri){
			d[i]=start+edge[i].c;
		}
		else d[i]=edge[i].ri+edge[i].c;
		q.push({0,0,d[i],0,0,i});
	}
	while(!q.empty()){
		int id=q.top().id;
		int cost=q.top().c;
		q.pop();
		if (d[id]!=cost) continue;
		int v=edge[id].v;
		for (int i=0;i<e[v].size();++i){
			int ID=e[v][i];
			int U=edge[ID].u;
			int V=edge[ID].v;
			int le=edge[ID].le;
			int ri=edge[ID].ri;
			int tmp;
			if (d[id]<edge[ID].le||d[id]>=edge[ID].ri) tmp=d[id]+edge[ID].c;
			else tmp=edge[ID].ri+edge[ID].c;
			if (d[ID]>tmp){
				d[ID]=tmp;
				q.push({0,0,d[ID],0,0,ID});
			}
		}
	}
}
int main(){
	//freopen("BILL.inp","r",stdin);
	//freopen("BILL.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s>>t>>start>>len;
	for (int i=1;i<=len;++i)
		cin>>Next[i];
	for (int i=1;i<=m;++i){
		int u,v,c;
		cin>>u>>v>>c;
		int x=edge.size();
		e[u].push_back(edge.size());
		edge.push_back({u,v,c,(int)1e9,(int)1e9,i-1});
		e[v].push_back(edge.size());
		edge.push_back({v,u,c,(int)1e9,(int)1e9,i-1+m});
	}
	int S=Next[1];
	int trc=0;
	for (int i=2;i<=len;++i){
		for (int j=0;j<e[S].size();++j){
			int id=e[S][j];
			int v=edge[id].v;
			if (v!=Next[i]) continue;
				if (i==2) {
					edge[id].le=0;
					edge[id^1].le=0;
					edge[id].ri=edge[id].c;
					edge[id^1].ri=edge[id].c;
				}
				else{
					edge[id].le=edge[trc].ri;
					edge[id].ri=edge[id].le+edge[id].c;
					edge[id^1].le=edge[trc].ri;
					edge[id^1].ri=edge[id^1].le+edge[id].c;
				}
			S=edge[id].v;
			trc=id;
			break;
		}
	}
	dijks();
	int res=1e9;
	for (int i=0;i<edge.size();++i){
		int v=edge[i].v;
		if (v!=t) continue;
		res=min(res,d[i]);
	}
	cout<<res-start;
	return 0;
}
