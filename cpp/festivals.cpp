#include<bits/stdc++.h>
#define maxn 100005
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
template<typename T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x < 10) {
        putchar(char(x + 48));
    } else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}
template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}
int d[maxn],n,m,K,trc[maxn],val[maxn],high[maxn],P[maxn][35],Pmin[maxn][35],root[maxn];
struct data {
    int u,v,c;
};
vector<data > edge,e[maxn];
vector<int > g[maxn];
bool CMP(data a,data b) {
    return a.c>b.c;
}
int getr(int u) {
    if (root[u]==u) return u;
    root[u]=getr(root[u]);
    return root[u];
}
int get(int u,int v) {
    int res=1e9;
    if (high[u]<high[v]) swap(u,v);
    int log=log2(high[u]);
    for (int i=log; i>=0; --i)
        if (high[u]-(1<<i)>=high[v]) {
            res=min(res,Pmin[u][i]);
            u=P[u][i];
        }
    if (u==v) return res;
    for (int i=log; i>=0; --i)
        if (P[u][i]!=-1&&P[v][i]!=-1&&P[u][i]!=P[v][i]) {
            res=min(res,Pmin[u][i]);
            res=min(res,Pmin[v][i]);
            u=P[u][i];
            v=P[v][i];
        }
    return res;
}
struct cmp {
    bool operator()(data a,data b) {
        return a.c>b.c;
    }
};
void dfs(int u) {
    for (int i=0; i<e[u].size(); ++i) {
        int v=e[u][i].v;
        if (v==trc[u]) continue;
        trc[v]=u;
        val[v]=e[u][i].c;
        high[v]=high[u]+1;
        dfs(v);
    }
}
void dijks() {
    priority_queue<data,vector<data>,cmp > q;
    for (int i=1; i<=n; ++i)
        if (d[i]==0) q.push({i,0,0});
    while(!q.empty()) {
        int u=q.top().u;
        int c=q.top().c;
        q.pop();
        if (d[u]!=c) continue;
        for (int i=0; i<g[u].size(); ++i) {
            int v;
            int id=g[u][i];
            if (u==edge[id].u) v=edge[id].v;
            else v=edge[id].u;
            int L=edge[id].c;
            if (d[u]+L<d[v]) {
                d[v]=d[u]+L;
                q.push({v,0,d[v]});
            }
        }
    }
}
int main() {
    freopen("FESTIVALS.inp","r",stdin);
    //freopen("FESTIVALS.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int test;
    read(n);
    read(m);
    read(K);
    read(test);
    for (int i=1; i<=m; ++i) {
        int u,v,c;
        read(u);
        read(v);
        read(c);
        g[u].push_back(edge.size());
        g[v].push_back(edge.size());
        edge.push_back({u,v,c});
    }
    for (int i=1; i<=n; ++i)
        d[i]=1e9;
    for (int i=1; i<=K; ++i) {
        int x;
        read(x);
        d[x]=0;
    }
    dijks();
    for (int id=0; id<edge.size(); ++id) {
        int u=edge[id].u;
        int v=edge[id].v;
        edge[id].c=min(d[u],d[v]);
    }
    for (int i=1; i<=n; ++i)
        root[i]=i;
    sort(edge.begin(),edge.end(),CMP);
    int DEM=0;
    for (int id=0; id<edge.size(); ++id) {
        int u=edge[id].u;
        int v=edge[id].v;
        int ru=getr(u);
        int rv=getr(v);
        if (ru==rv) continue;
        root[ru]=rv;
        e[u].push_back({0,v,edge[id].c});
        e[v].push_back({0,u,edge[id].c});
        ++DEM;
        if (DEM==n-1) break;
    }
    dfs(1);
    memset(P,-1,sizeof P);
    for (int i=1; i<=n; ++i) {
        P[i][0]=trc[i];
        Pmin[i][0]=val[i];
    }
    for (int j=1; (1<<j)<=n; ++j)
        for (int i=1; i<=n; ++i) {
            if (P[i][j-1]==-1) continue;
            int x=P[i][j-1];
            P[i][j]=P[x][j-1];
            Pmin[i][j]=min(Pmin[i][j-1],Pmin[x][j-1]);
        }
    while(test--) {
        int u,v;
        read(u);
        read(v);
        writeln(get(u,v));
    }
}
