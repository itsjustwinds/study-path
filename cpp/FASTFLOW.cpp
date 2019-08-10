#include<bits/stdc++.h>
#define ll long long
#define maxn 5005
using namespace std;
int n,m;
struct data
{
            int v,f,c;
};
vector<int> g[maxn];
vector<data> e;
int q[2*maxn];
int dd[maxn],d[maxn],cnt,pos[maxn];
ll res;
bool bfs()
{
            dd[1]=++cnt;
            int l=1,r=0;
            q[++r]=1;
            while(l<=r)
            {
                        int u=q[l];
                        ++l;
                        pos[u]=0;
                        for (int i=0; i<(int)g[u].size(); ++i)
                        {
                                    int id=g[u][i];
                                    int v=e[id].v;
                                    if (dd[v]==cnt||e[id].f==e[id].c) continue;
                                    dd[v]=cnt;
                                    d[v]=d[u]+1;
                                    q[++r]=v;
                        }
            }
            return dd[n]==cnt;
}
int dfs(int u,int low)
{
            if (u==n||low==0) return low;
            for (; pos[u]<(int)g[u].size(); ++pos[u])
            {
                        int id=g[u][pos[u]];
                        int v=e[id].v;
                        if (d[v]!=d[u]+1||e[id].f==e[id].c) continue;
                        int get=dfs(v,min(low,e[id].c-e[id].f));
                        if (get)
                        {
                                    e[id].f+=get;
                                    e[id^1].f-=get;
                                    //++pos[u];
                                    return get;
                        }
            }
            return 0;
}
int main()
{
            freopen("FASTFLOW.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            for (int i=1; i<=m; ++i)
            {
                        int u,v,w;
                        cin>>u>>v>>w;
                        if (u==v) continue;
                        g[u].push_back(e.size());
                        e.push_back({v,0,w});
                        g[v].push_back(e.size());
                        e.push_back({u,0,w});
            }
            while(bfs())
            {
                        while(int x=dfs(1,1000000000))
                                    res+=x;
            }
            cout<<res;
            return 0;
}
