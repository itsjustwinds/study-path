#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int dd[maxn],n,m,ok,trace[maxn],cnt[maxn],f[maxn][maxn],dd2[maxn];
vector<int> e[maxn],ct;
typedef pair<int,int> II;
vector<II> res;
void dfs(int trc,int u)
{
    if (ok) return;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        if (ok) return;
        int v=e[u][i];
        if (v==trc) continue;
        trace[v]=u;
        dd[v]++;
        if (dd[v]>=2)
        {
            ok=1;
            ct.push_back(v);
            int tmp=u;
            while(tmp!=v)
            {
                ct.push_back(tmp);
                tmp=trace[tmp];
            }
        }
        else dfs(u,v);
    }
}
void dfs2(int u)
{
    dd2[u]=1;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i];
        if (cnt[v]&&ok==0)
        {
            ok=1;
            res.push_back(II(u,v));
            continue;
        }
        if (cnt[v]) continue;
        if (dd2[v]) continue;
        res.push_back(II(u,v));
        dfs2(v);
    }
}
int main()
{
    freopen("vmst.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dd[1]=1;
    dfs(-1,1);
    for (int i=0; i<(int)ct.size(); i++)
    {
        int u=ct[i];
        cnt[u]=1;
    }
    for (int i=0; i<(int)ct.size(); i++)
    {
        int u=ct[i];
        for (int j=0; j<(int)e[u].size(); j++)
        {
            int v=e[u][j];
            if (!cnt[v]) continue;
            if (f[u][v]) continue;
            f[u][v]=1;
            f[v][u]=1;
            res.push_back(II(u,v));
        }
    }
    for (int i=1; i<=n; i++)
        if (dd2[i]==0&&cnt[i]==0)
        {
            ok=0;
            dfs2(i);
        }
    cout<<3<<"\n";
    for (int i=0; i<(int)res.size(); i++)
        if (i!=0)
        {
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }
    for (int i=0; i<(int)res.size(); i++)
        if (i!=1)
        {
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }
    for (int i=0; i<(int)res.size(); i++)
        if (i!=2)
        {
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }
    return 0;
}
