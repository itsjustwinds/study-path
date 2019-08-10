#include<bits/stdc++.h>
#define maxn 405
#define ll long long
using namespace std;
int n;
struct note {
    ll x,y,z;
};
int bef[maxn];
note a[maxn];
ll maxx,d[maxn],res;
ll tinh(note a,note b) {
    return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}
struct data {
    int u,v,f,c;
    ll cost;
};
vector<data > edge;
vector<int > g[maxn];
int s,t;
void add_edge(int u,int v,int c,ll cost) {
    g[u].push_back(edge.size());
    edge.push_back({u,v,0,c,cost});
    g[v].push_back(edge.size());
    edge.push_back({v,u,0,0,-cost});
}
struct cmp {
    bool operator ()(data a,data b) {
        return a.cost>b.cost;
    }
};
bool dijks() {
    for (int i=1; i<=n*2+2; ++i)
        d[i]=1e18;
    d[s]=0;
    priority_queue<data,vector<data>,cmp > q;
    q.push({s,0,0,0,0});
    while(!q.empty()) {
        int u=q.top().u;
        ll COST=q.top().cost;
        q.pop();
        if (d[u]!=COST)  continue;
        for (int i=0; i<g[u].size(); ++i) {
            int id=g[u][i];
            int v=edge[id].v;
            ll cost=edge[id].cost;
            if (d[u]+cost>=d[v]||edge[id].f==edge[id].c)continue;
            d[v]=d[u]+cost;
            bef[v]=id;
            q.push({v,0,0,0,d[v]});
        }
    }
    return d[t]!=1e18;
}
ll turn() {
    int T=t;
    int ans=1e9;
    while(T!=s) {
        int id=bef[T];
        ans=min(ans,edge[id].c-edge[id].f);
        T=edge[id].u;
    }
    T=t;
    while(T!=s) {
        int id=bef[T];
        edge[id].f+=ans;
        edge[id^1].f-=ans;
        T=edge[id].u;
    }
    return ans;
}
void solve() {
    while(dijks()) {
        ll x=turn();
        res+=x*(maxx-d[t]);
    }
}
int main() {
    freopen("ALIVE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i].x>>a[i].y>>a[i].z;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            ll cost=tinh(a[i],a[j]);
            maxx=max(maxx,cost);
        }
    maxx++;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            ll cost=maxx-tinh(a[i],a[j]);
            add_edge(i,j+n,1,cost);
        }
    s=2*n+1,t=2*n+2;
    for (int i=1; i<=n; ++i) {
        add_edge(s,i,1,0);
        add_edge(i+n,t,1,0);
    }
    solve();
    cout<<res;
}
