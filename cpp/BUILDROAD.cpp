#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
int n,m,need,s,t,bef[maxn],inq[maxn];
ll ans,d[maxn];
vector<int > g[maxn];
struct data {
    int u,v,f,c;
    ll cost;
} ;
vector<data > edge;
void add_edge(int u,int v,int c,int cost) {
    g[u].push_back(edge.size());
    edge.push_back({u,v,0,c,cost});
    g[v].push_back(edge.size());
    edge.push_back({v,u,0,0,-cost});
}
bool bfs()
{
        queue<ll >q;
        for (ll i=1; i<=2*n+2; ++i)
                d[i]=1e15;
        q.push(s);
        d[s]=0;
        inq[s]=1;
        while(!q.empty())
        {
                ll u=q.front();
                q.pop();
                inq[u]=0;
                for (ll i=0; i<g[u].size(); ++i)
                {
                        ll id=g[u][i];
                        ll v=edge[id].v;
                        ll cost=edge[id].cost;
                        if (d[u]+cost>=d[v]||edge[id].f>=edge[id].c) continue;
                        bef[v]=id;
                        d[v]=d[u]+cost;
                        if (!inq[v])
                        {
                                q.push(v);
                                inq[v]=1;
                        }
                }
        }
        return d[t]!=1e15;
}
int turn() {
    int T=t;
    int ans=1e9;
    while(T!=s) {
        int id=bef[T];
        int u=edge[id].u;
        ans=min(ans,edge[id].c-edge[id].f);
        T=u;
    }
    T=t;
    while(T!=s) {
        int id=bef[T];
        int u=edge[id].u;
        edge[id].f+=ans;
        edge[id^1].f-=ans;
        T=u;
    }
    return ans;
}
int main() {
    freopen("BUILDROAD.inp","r",stdin);
    read(n);read(m);
    need=n;
    for (int i=1; i<=m; ++i) {
    	int u,v,c;
        read(u);read(v);read(c);
        add_edge(u,v+n,1,c);
    }
    s=2*n+1,t=2*n+2;
    for (int i=1; i<=n; ++i) {
        add_edge(s,i,1,1e9+7);
        add_edge(i+n,t,1,1e9+7);
    }
    while(bfs()) {
        int x=turn();
        ans+=d[t]-2ll*(1e9+7);
        need-=x;
    }
    if (need>0) {
        printf("-1");
        return 0;
    }
    write(ans);
}
