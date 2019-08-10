#include<bits/stdc++.h>
#define maxn 355
using namespace std;
int f[maxn][maxn][maxn],n,m,q,dd[maxn][maxn][maxn],d[maxn];
vector<int> e[maxn];
void dfs(int u,int v,int k)
{
    if (dd[u][v][k]||dd[v][u][k]) return;
    dd[u][v][k]=1;
    dd[v][u][k]=1;
    if (u==k||v==k) return;
    if (d[u]==2||d[v]==1) return;
    d[u]=1;
    d[v]=2;
    f[u][v][k]=1;
    f[v][u][k]=1;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int tmp=e[u][i];
        dfs(tmp,v,k);
    }
    for (int i=0;i<(int)e[v].size();i++)
    {
        int tmp=e[v][i];
        dfs(u,tmp,k);
    }
    d[u]=0;
    d[v]=0;
}
int main()
{
    freopen("w33e.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>m>>test;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<(int)e[i].size();j++)
        {
            int u=e[i][j];
            for (int k=j+1;k<(int)e[i].size();k++)
            {
                int v=e[i][k];
                dfs(u,v,i);
            }
        }
    }
    while(test--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if (f[u][v][w]||f[v][u][w]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

