#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct data
{
        int u,v,f,c;
};
int n,m,s,t,sum,res,d[maxn],dd[maxn],cnt,pos[maxn];
vector<int > g[maxn];
vector<data >edge;
void add_edge(int u,int v,int c)
{
        g[u].push_back(edge.size());
        edge.push_back({u,v,0,c});
        g[v].push_back(edge.size());
        edge.push_back({v,u,0,0});
}
bool bfs()
{
        queue<int > q;
        q.push(s);
        dd[s]=++cnt;
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=edge[id].v;
                        if (dd[v]==cnt||edge[id].c==edge[id].f) continue;
                        dd[v]=cnt;
                        d[v]=d[u]+1;
                        q.push(v);
                }
        }
        return dd[t]==cnt;
}
int dfs(int u,int low)
{
        if (u==t||low==0) return low;
        for (;pos[u]<g[u].size();++pos[u])
        {
                int id=g[u][pos[u]];
                int v=edge[id].v;
                if (d[v]!=d[u]+1||edge[id].f==edge[id].c) continue;
                int x=dfs(v,min(low,edge[id].c-edge[id].f));
                if (x)
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
        freopen("JOBSET.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        s=n+1;
        t=n+2;
        for (int i=1;i<=n;++i)
        {
                int c;
                cin>>c;
                if (c>0) add_edge(s,i,c);
                else add_edge(i,t,-c);
                if (c>0) sum+=c;
        }
        cin>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                add_edge(u,v,1e9);
        }
        while(bfs())
        {
                while(int x=dfs(s,1e9))
                {
                        res+=x;
                }
        }
        cout<<sum-res;
}
