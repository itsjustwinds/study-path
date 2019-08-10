#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
using namespace std;
int n,m,need,bef[maxn],s,t;
ll res,d[maxn];
struct data
{
        int u,v,f,c;
        ll cost;
};
vector<int > zero,g[maxn];
vector<data >edge;
void add_edge(int u,int v,int c,ll cost)
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
bool dijks()
{
        for (int i=1;i<=n;++i)
                d[i]=1e18;
        d[s]=0;
        priority_queue<data,vector<data>,cmp > q;
        q.push({s,0,0,0,0});
        while(!q.empty())
        {
                int u=q.top().u;
                ll C=q.top().cost;
                q.pop();
                if (d[u]!=C) continue;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=edge[id].v;
                        ll cost=edge[id].cost;
                        if (d[u]+cost>=d[v]||edge[id].f>=edge[id].c) continue;
                        d[v]=d[u]+cost;
                        bef[v]=id;
                        q.push({v,0,0,0,d[v]});
                }
        }
        return d[t]!=1e18;
}
void turn()
{
        int u=t;
        while(u!=s)
        {
                int id=bef[u];
                edge[id].f+=1;
                edge[id^1].f-=1;
                u=edge[id].u;
        }
        u=t;
}
bool BFS()
{
        for (int i=1;i<=n;++i)
                d[i]=0;
        d[s]=1;
        queue<int > q;
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=edge[id].v;
                        if (d[v]||edge[id].f<=0) continue;
                        d[v]=1;
                        q.push(v);
                        bef[v]=id;
                }
        }
        return d[t]==1;
}
void TURN()
{
        int u=t;
        vector<int > res;
        res.clear();
        while(u!=s)
        {
                int id=bef[u];
                int v=edge[id].u;
                res.push_back(u);
                u=v;
                edge[id].f=0;
        }
        res.push_back(s);
        cout<<res.size()<<" ";
        for (int i=res.size()-1;i>=0;--i)
                cout<<res[i]<<" ";
}
void trace()
{
        while(BFS())
        {
                TURN();
                cout<<"\n";
        }
}
int main()
{
        freopen("HIWAY2.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        need=2;
        cin>>n>>m>>s>>t;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                ll c;
                cin>>u>>v>>c;
                add_edge(u,v,1,c);
                add_edge(v,u,1,c);
        }
        while(dijks())
        {
                turn();
                need--;
                res+=d[t];
                if (need==0) break;
        }
        if (need>0)
        {
                cout<<-1;
                return 0;
        }
        cout<<res;
        //trace();
}
