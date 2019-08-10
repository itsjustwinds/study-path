#include<bits/stdc++.h>
#define maxn 105
#define ll long long
#define inf 100000000000000000LL
using namespace std;
int n,s,t,pos[maxn],dd[maxn],d[maxn],cnt;
ll res;
struct data
{
        int u,v;
        ll f,c;
};
vector<int > g[maxn];
vector<data >edge;
void add_edge(int u,int v,ll c)
{
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,0});
}
bool bfs()
{
        dd[s]=++cnt;
        queue<int > q;
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0;i<g[u].size();++i)
                {
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
ll dfs(int u,ll low)
{
        if (u==t||low==0) return low;
        for (;pos[u]<g[u].size();++pos[u])
        {
                int id=g[u][pos[u]];
                int v=edge[id].v;
                if (d[v]!=d[u]+1||edge[id].f==edge[id].c) continue;
                ll x=dfs(v,min(low,edge[id].c-edge[id].f));
                if (x!=0)
                {
                        edge[id].f+=x;
                        edge[id^1].f-=x;
                        return x;
                }
        }
        return 0;
}
int main()
{
        freopen("E_MUL.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        s=n+1,t=n+2;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                if (x<0) add_edge(s,i,-x);
                else
                {add_edge(i,t,x);
                res+=x;
                }
        }
        for (int i=1;i<=n;++i)
        {
                for (int j=2;j*i<=n;++j)
                        add_edge(i,i*j,inf);
        }
        while(bfs())
        {
              while(ll x=dfs(s,1e9))
              {
                      res-=x;
              }
        }
        cout<<res;
        return 0;
}
