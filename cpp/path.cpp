#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int deg[maxn],n,m,ok,dd[maxn],trace[maxn],dem,res[maxn];
vector<int> w[maxn];
void dfs(int u)
{
    if (ok==1) return;
    for (int i=0;i<deg[u];i++)
    {
        if (ok) return;
        int v=w[u][i];
        if (dd[v]!=0) continue;
        dd[v]=1;
        trace[v]=u;
        if (v==n) ok=1;
        dfs(v);
        //dd[v]=0;
    }
}
int main()
{
    freopen("path.inp","r",stdin);
    freopen("path.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        w[u].push_back(v);
    }
    dd[1]=1;
    dfs(1);
    int x=n;
    while (x!=1)
    {
        dem++;
        res[dem]=x;
        x=trace[x];
    }
    cout<<1<<" ";
    for (int i=dem;i>=1;i--)
        cout<<res[i]<<" ";
    return 0;
}
