#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
int f[maxn],n,m,num[maxn],low[maxn],cnt;
vector<int> e[maxn];
ll res;
void dfs(int u,int trc)
{
        num[u]=++cnt;
        low[u]=cnt;
        f[u]=1;
        vector<int> tmp;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                if (num[v]) low[u]=min(low[u],num[v]);
                else
                {
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        if (low[v]==num[v]) tmp.push_back(v);
                        f[u]+=f[v];
                }
        }
        for (int i=0;i<tmp.size();++i)
        {
                int v=tmp[i];
                res+=(n-f[v])*f[v];
        }
}
int main()
{
        freopen("WEATHER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        dfs(1,-1);
        cout<<res;
        return 0;
}
