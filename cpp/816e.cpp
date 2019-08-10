#include<bits/stdc++.h>
#define oo 1111111111111111LL
#define maxn 5005
#define ll long long
using namespace std;
ll c[maxn],d[maxn],f[maxn][maxn],g[maxn][maxn],n,b,sz[maxn],h[maxn];
vector<int> e[maxn];
void dfs(int u)
{
    for (int i=1; i<=n; i++)
    {
        f[u][i]=oo;
        g[u][i]=oo;
    }
    f[u][1]=c[u]-d[u];
    g[u][1]=c[u];
    g[u][0]=0;
    sz[u]=1;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i];
        dfs(v);
        for (int x=1; x<=sz[u]; x++)
            h[x]=f[u][x];
        for (int x=1; x<=sz[u]; x++)
            for (int y=1; y<=sz[v]; y++)
            {
                f[u][x+y]=min(f[u][x+y],h[x]+min(f[v][y],g[v][y]));
            }
        for (int x=0; x<=sz[u]; x++)
            h[x]=g[u][x];
        for (int x=0; x<=sz[u]; x++)
            for (int y=1; y<=sz[v]; y++)
            {
                g[u][x+y]=min(g[u][x+y],h[x]+g[v][y]);
            }
        sz[u]+=sz[v];
    }
}
int main()
{
     freopen("816e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>b;
    for (int i=1; i<=n; i++)
    {
        cin>>c[i]>>d[i];
        if (i>=2)
        {
            int x;
            cin>>x;
            e[x].push_back(i);
        }
    }
    dfs(1);
    for (int i=1; i<=n; i++)
        if (min(f[1][i],g[1][i])>b)
        {
            cout<<i-1;
            return 0;
        }
    cout<<n;
    return 0;
}
