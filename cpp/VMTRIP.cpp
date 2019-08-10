#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,s,t,d[2][maxn],dd[maxn],k,a[maxn],cntin[maxn],cntout[maxn],res[maxn];
vector<int> e[maxn],in[maxn],out[maxn],deg[maxn];
void bfs(int id,int s,int t)
{
    queue<int > q;
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0; i<(int)e[u].size(); i++)
        {
            if (u==t) return;
            int v=e[u][i];
            if (d[id][v]==-1)
            {
                d[id][v]=d[id][u]+1;
                if (v==t) k=d[id][v]+1;
                q.push(v);
            }
        }
    }
}
void dfs(int u)
{
    dd[u]=0;
    for (int i=0; i<(int)in[u].size(); i++)
    {
        int v=in[u][i];
        if (!dd[v]) continue;
        cntout[v]--;
        if (cntout[v]==0)
        {
            dfs(v);
        }
    }
    for (int i=0; i<(int)out[u].size(); i++)
    {
        int v=out[u][i];
        if (!dd[v]) continue;
        cntin[v]--;
        if (cntin[v]==0)
        {
            dfs(v);
        }
    }
}
int main()
{
    freopen("VMTRIP.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(d,-1,sizeof(d));
    d[0][s]=0;
    d[1][t]=0;
    bfs(0,s,t);
    bfs(1,t,s);
    for (int i=1; i<=k; i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        dd[i]=1;
    for (int i=1; i<=n; i++)
        if (d[0][i]+d[1][i]!=d[0][t])
            dd[i]=0;
        else
        {
            deg[d[0][i]+1].push_back(i);
        }
    for (int i=1; i<=k; i++)
    {
        for (int l=0; l<(int)deg[i].size(); l++)
        {
            int u=deg[i][l];
            for (int j=0; j<(int)e[u].size(); j++)
            {
                int v=e[u][j];
                if (!dd[v]) continue;
                if (d[0][u]+1==d[0][v])
                {
                    in[v].push_back(u);
                    cntin[v]++;
                    out[u].push_back(v);
                    cntout[u]++;
                }
            }
        }
    }
    for (int i=1; i<=k; i++)
    {
        int tmp=a[i];
        int minn=1000000000;
        for (int j=0; j<(int)deg[tmp].size(); j++)
        {
            int v=deg[tmp][j];
            if (dd[v]) minn=min(minn,v);
        }
        res[tmp]=minn;
        for (int j=0; j<(int)deg[tmp].size(); j++)
        {
            int v=deg[tmp][j];
            if (v==minn) continue;
            if (!dd[v]) continue;
            dfs(v);
        }
    }
    for(int i=1; i<=k; i++)
        cout<<res[i]<<" ";
    return 0;
}
