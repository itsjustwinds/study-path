#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int num[maxn],low[maxn],cnt,n,m,res;
vector<int> e[maxn];
void dfs(int u,int trc)
{
    cnt++;
    num[u]=cnt;low[u]=cnt;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if (v==trc) continue;
        if (num[v])
        {
            low[u]=min(low[u],num[v]);
            continue;
        }
        dfs(v,u);
        low[u]=min(low[u],low[v]);
    if (low[v]>=num[v]) res++;
    }
}
int main()
{
    freopen("KBUILD.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (!low[i]) dfs(i,i);
    cout<<res;
    return 0;
}
