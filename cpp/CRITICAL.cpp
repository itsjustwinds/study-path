#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
int f[maxn],khop[maxn],trc[maxn],n,m,low[maxn],num[maxn],cnt,nchild[maxn],root[maxn];
double res;
vector<int> e[maxn];
void dfs(int u,int t)
{
        num[u]=++cnt;
        low[u]=cnt;
        f[u]=1;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==t) continue;
                if (num[v])
                {
                        low[u]=min(low[u],num[v]);
                }else
                {
                        nchild[u]++;
                        root[v]=root[u];
                        trc[v]=u;
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        f[u]+=f[v];
                }
        }
}
void tinh(int u)
{
        int sum=0;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (trc[v]==u&&low[v]>=num[u])
                {
                res+=sum*(f[v]);
                sum+=f[v];
                }
        }
        res+=(f[root[u]]-sum-1)*sum;
}
int main()
{
        freopen("CRITICAL.inp","r",stdin);
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
        for (int i=1;i<=n;++i)
        if (!num[i])
        {
                root[i]=i;
                dfs(i,-1);
        }
        for (int v=1;v<=n;++v)
        if (trc[v])
        {
                int u=trc[v];
                if (low[v]>=num[u])khop[u]=khop[u]||trc[u]||nchild[u]>=2;
        }
        for (int i=1;i<=n;++i) if (khop[i])
                tinh(i);
        res/=n;
        cout<<setprecision(2)<<fixed<<res;
        return 0;
}
