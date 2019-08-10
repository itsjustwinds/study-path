#include<bits/stdc++.h>
#define maxn 100005
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
int n,a[maxn],s,t,val,dem,pre[maxn];
ll res,sum,d[maxn];
struct data
{
        int u,v;
        ll f,c,cost;
};
vector<data > edge;
vector<int > g[maxn];
int ok;
void add_edge(int u,int v,ll c,ll cost)
{
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c,cost});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,0,-cost});
}
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.cost>b.cost;
        }
};
bool dijsk()
{
        for (int i=1;i<=n+2;++i)
                d[i]=1e18;
        d[s]=0;
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        q.push({s,0,0,0,0});
        while(!q.empty())
        {
                int u=q.top().u;
                ll cost=q.top().cost;
                q.pop();
                if (cost!=d[u]) continue;
                if (u==t) return 1;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        if (!ok&&edge[id].c==val+1) edge[id].c=val;
                        int v=edge[id].v;
                        ll C=edge[id].cost;
                        if (d[u]+C>=d[v]||edge[id].f>=edge[id].c) continue;
                        d[v]=d[u]+C;
                        pre[v]=id;
                        q.push({v,0,0,0,d[v]});
                }
        }
        return 0;
}
ll turn()
{
        int u=t;
        ll tmp=1e9;
        while(u!=s)
        {
                int id=pre[u];
                tmp=min(tmp,edge[id].c-edge[id].f);
                u=edge[id].u;
        }
        u=t;
        while(u!=s)
        {
                int id=pre[u];
                edge[id].f+=tmp;
                edge[id^1].f-=tmp;
                u=edge[id].u;
        }
        return tmp;
}
void solve()
{
        ok=1;
        if (dem==sum%n) ok=0;
        while(dijsk())
        {
                int tmp=turn();
                int id=pre[t];
                if (edge[id].f==val+1) ++dem;
                if (ok&&dem==sum%n)
                {
                        ok=0;
                }
                res+=1ll*tmp*d[t];
        }
        write(res);
}
int main()
{
        freopen("ARRANGE.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=1;i<=n;++i)
        {
                read(a[i]);
                sum+=a[i];
        }
        val=sum/n;
        s=n+1,t=n+2;
        for (int i=1;i<=n;++i)
                add_edge(s,i,a[i],0);
        for (int i=1;i<n;++i)
        {
                add_edge(i,i+1,1e18,1);
                add_edge(i+1,i,1e18,1);
        }
        for (int i=1;i<=n;++i)
                add_edge(i,t,val+1,0);
        solve();
}
