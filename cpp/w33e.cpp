#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,m,q,d[maxn],s,t,w,ok;
vector<int> e[maxn];
void dfs(int u,int v,int k,int trcu,int trcv)
{
    if (ok) return;
    if (u==k||v==k) return;
    if (d[u]==2||d[v]==1) return;
    if (trcv==v&&d[u]!=0) return;
    if (trcu==u&&d[v]!=0) return;
    d[u]=1;
    d[v]=2;
    if (u==s&&v==t)
    {
        ok=1;
        return;
    }
    if (u==t&&v==s)
    {
        ok=1;
        return;
    }
    for (int i=0;i<(int)e[u].size();i++)
    {
        if (ok) return;
        int tmp=e[u][i];
        if (tmp==k) continue;
        dfs(tmp,v,k,u,v);
    }
    for (int i=0;i<(int)e[v].size();i++)
    {
        if (ok) return;
        int tmp=e[v][i];
        if (tmp==k) continue;
        dfs(u,tmp,k,u,v);
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
    while(test--)
    {
        cin>>s>>t>>w;
        ok=0;
        for (int i=1;i<=n;i++)
            d[i]=0;
        for (int j=0;j<(int)e[w].size();j++)
        {
            int u=e[w][j];
            for (int k=j+1;k<(int)e[w].size();k++)
            {
                int v=e[w][k];
                dfs(u,v,w,-1,-1);
            }
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
