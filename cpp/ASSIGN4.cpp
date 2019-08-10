#include<bits/stdc++.h>
#define maxn 405
using namespace std;
template<typename T> inline void read(T &x) {
    char c;
    bool neg = false;
    while (!isdigit(c = getchar()) && c != '-');
    x = 0;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    if (neg) x = -x;
}
int n,m,c[maxn][maxn],s,t,res,cnt,bef[2*maxn],d[2*maxn];
vector<int > g[maxn];
struct data {
    int u,v,f,c,cost;
};
vector<data > edge;
void add_edge(int u,int v,int c,int cost){
    g[u].push_back(edge.size());
    edge.push_back({u,v,0,c,cost});
    g[v].push_back(edge.size());
    edge.push_back({v,u,0,0,-cost});
}
struct cmp{
    bool operator ()(data a,data b){
        return a.cost>b.cost;
    }
};
bool dijks(){
    for (int i=1;i<=n+m+2;++i)
        d[i]=1e9;
    d[s]=0;
    priority_queue<data,vector<data>,cmp > q;
    q.push({s,0,0,0,d[s]});
    while(!q.empty()){
        int u=q.top().u;
        int du=q.top().cost;
        q.pop();
        if (d[u]!=du) continue;
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
int back(){
    int T=t;
    int cost=1e9;
    while(T!=s){
        int id=bef[T];
        cost=min(cost,edge[id].c-edge[id].f);
        T=edge[id].u;
    }
    T=t;
    while(T!=s){
        int id=bef[T];
        edge[id].f+=cost;
        edge[id^1].f-=cost;
        T=edge[id].u;
    }
    return cost;
}
void solve() {
    res=0;
    while(dijks()){
        int x=back();
        res+=x*d[t];
    }
    printf("%d\n",res);
}
int main() {
    freopen("ASSIGN4.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    int test;
    read(test);
    while(test--) {
        read(n);read(m);
        s=n+m+1;
        t=n+m+2;
        for (int i=1; i<=n+m+2; ++i)
            g[i].clear();
        edge.clear();
        for (int i=1;i<=n;++i){
            int x;
            read(x);
            add_edge(s,i,x,0);
        }
        for (int i=1;i<=m;++i){
            int x;
            read(x);
            add_edge(i+n,t,x,0);
        }
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                int x;
                read(x);
                add_edge(i,j+n,1000000,x);
            }

        solve();
    }
}
