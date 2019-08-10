#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
ll res;
ll d[maxn],inq[maxn],bef[maxn],ccost[maxn][maxn],cc[maxn][maxn];
struct data
{
        ll u,v,f,c,cost;
};
vector<ll > g[maxn];
vector<data >edge;
ll n,m,need,s,t;
void add_edge(ll u,ll v,ll c,ll cost)
{
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c,cost});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,0,-cost});
}
bool bfs()
{
        queue<ll >q;
        for (ll i=1; i<=n; ++i)
                d[i]=1e18;
        while(!q.empty()) q.pop();
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
        return d[t]!=1e18;
}
ll turn(ll t,ll need)
{
        ll low=1e9;
        ll u=t;
        while(u!=s)
        {
                ll id=bef[u];
                low=min(low,edge[id].c-edge[id].f);
                u=edge[id].u;
        }
        u=t;
        if (low>need) low=need;
        while(u!=s)
        {
                ll id=bef[u];
                edge[id].f+=low;
                edge[id^1].f-=low;
                u=edge[id].u;
        }
        return low;
}
int main()
{
        //freopen("D:\\c++\\MINCOST.inp","r",stdin);
        //freopen("D:\\c++\\MINCOST.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>need>>s>>t;
        for (ll i=1; i<=m; ++i)
        {
                ll u,v,c,cost;
                cin>>u>>v>>cost>>c;
                cc[u][v]=c;
                cc[v][u]=c;
                ccost[u][v]=cost;
                ccost[v][u]=cost;
        }
        for (int i=1;i<=n;++i)
                for (int j=i+1;j<=n;++j)
                if (cc[i][j]!=0)
        {
                add_edge(i,j,cc[i][j],ccost[i][j]);
                add_edge(j,i,cc[i][j],ccost[i][j]);
        }
        while(bfs())
        {
                ll x=turn(t,need);
                if (x==0) break;
                if (x>=need)
                {
                        res+=1ll*d[t]*need;
                        need=0;
                        break;
                }
                res+=1ll*d[t]*x;
                need-=x;
        }
        if (need==0)
        {
                cout<<res<<"\n";
                for (ll i=0; i<edge.size(); ++i)
                {
                        if (edge[i].f<=0) continue;
                        cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].f<<"\n";
                }
                cout<<"0 0 0";
        }
        else cout<<-1;
}
