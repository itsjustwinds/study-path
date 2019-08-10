#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int n,m;
vector<int > R,B,G;
vector<int > e[maxn],g[maxn];
struct data {
    int u,v,f,c;
};
vector<data > edge;
int res,s,t,cnt,pos[maxn],high[maxn],dd[maxn];
char S[maxn];
void add_edge(int u,int v,int c) {
    g[u].push_back(edge.size());
    edge.push_back({u,v,0,c});
    g[v].push_back(edge.size());
    edge.push_back({v,u,0,0});
}
void add_edge_two(int u,int v,int c) {
    g[u].push_back(edge.size());
    edge.push_back({u,v,0,c});
    g[v].push_back(edge.size());
    edge.push_back({v,u,0,c});
}
bool bfs() {
    queue<int > q;
    dd[s]=++cnt;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        pos[u]=0;
        for (int i=0; i<g[u].size(); ++i) {
            int id=g[u][i];
            int v=edge[id].v;
            if (dd[v]==cnt||edge[id].f>=edge[id].c) continue;
            dd[v]=cnt;
            high[v]=high[u]+1;
            q.push(v);
        }
    }
    return dd[t]==cnt;
}
int dfs(int u,int low) {
    if (u==t||low==0) return low;
    for (; pos[u]<g[u].size(); ++pos[u]) {
        int id=g[u][pos[u]];
        int v=edge[id].v;
        if (high[v]!=high[u]+1||edge[id].f>=edge[id].c) continue;
        int x=dfs(v,edge[id].c-edge[id].f);
        if (x) {
            edge[id].f+=x;
            edge[id^1].f-=x;
            return x;
        }
    }
    return 0;
}
void go(vector<int > a,vector<int > b) {
    for (int i=1; i<=n+2; ++i)
        g[i].clear();
    int ans=0;
    edge.clear();
    for (int i=0; i<a.size(); ++i) {
        int x=a[i];
        for (int j=0; j<e[x].size(); ++j) {
            int y=e[x][j];
            add_edge_two(x,y,1e9);
        }
        add_edge(s,x,1);
    }
    for (int i=0; i<b.size(); ++i) {
        int x=b[i];
        add_edge(x,t,1);
    }
    while(bfs()) {
        int x;
        while(1) {
            x=dfs(s,1e9);
            if (x==0) break;
            ans+=x;
        }
    }
    res=min(res,ans);
}
int main() {
    freopen("VOI.inp","r",stdin);
    freopen("VOI.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(S+1);
    for (int i=1; i<=strlen(S+1); ++i) {
        if (S[i]=='R') R.push_back(i);
        if (S[i]=='G') G.push_back(i);
        if (S[i]=='B') B.push_back(i);
    }
    s=n+1;
    t=n+2;
    cin>>m;
    for (int i=1; i<=m; ++i) {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    res=R.size();
    res=min(res,(int)B.size());
    res=min(res,(int)G.size());
    go(R,B);
    go(R,G);
    go(G,B);
    cout<<res;
}
