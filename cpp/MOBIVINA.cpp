#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
int n,s,t,dd[maxn],d[maxn],pos[maxn],cnt;
ll res;
struct data{
        int u,v,f,c;
};
vector<data > edge;
vector<int > g[maxn];
void add_edge(int u,int v,int c){
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,c});
}
void add_edge_none(int u,int v,int c){
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,0});
}
bool bfs(){
        dd[s]=++cnt;
        queue<int > q;
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
                        d[v]=d[u]+1;
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
                if (d[v]!=d[u]+1||edge[id].f==edge[id].c) continue;
                int x=dfs(v,min(low,edge[id].c-edge[id].f));
                if (x){
                        edge[id].f+=x;
                        edge[id^1].f-=x;
                        return x;
                }
        }
        return 0;
}
void solve(){
        while(bfs()){
                int x;
                while(1){
                        x=dfs(s,1e9);
                        if (x==0) break;
                        res+=x;
                }
        }
}
int main(){
        freopen("MOBIVINA.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        s=n+1,t=n+2;
        for (int i=1;i<=n;++i){
                int x;
                cin>>x;
                add_edge_none(s,i,x);
        }
        for (int i=1;i<=n;++i){
                int x;
                cin>>x;
                add_edge_none(i,t,x);
        }
        for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j){
                int x;
                cin>>x;
                if (j>i&&x) add_edge(i,j,x);
        }
        solve();
        cout<<res;
}
