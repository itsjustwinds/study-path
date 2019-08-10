#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,trc[maxn],high[maxn],p[maxn][32],res;
vector<int> e[maxn];
void dfs(int u,int t)
{
            high[u]=high[trc[u]]+1;
            for (int i=0;i<(int)e[u].size();++i)
            {
                        int v=e[u][i];
                        if (v==t) continue;
                        trc[v]=u;
                        dfs(v,u);
            }
}
int lca(int u,int v)
{
            if (high[u]<high[v]) swap(u,v);
            int log=log2(high[u]);
            for (int i=log;i>=0;--i)
            {
                        if (high[u]-(1<<i)>=high[v]) u=p[u][i];
            }
            if (u==v) return u;
            for (int i=log;i>=0;--i)
            if (p[u][i]!=p[v][i]&&p[u][i]!=-1&&p[v][i]!=-1)
            {
                        u=p[u][i];
                        v=p[v][i];
            }
            return trc[u];
}
void solve(int u,int v,int w)
{
            int kq=0;
            int lcu=lca(u,w);
            int lcv=lca(v,w);
            int luv=lca(u,v);
            if (lcu==lcv)
            {
                        kq+=high[luv]-high[lcu];
            }
            if (high[lcu]>high[lcv])
            {
                        kq+=high[w]-high[lcu]+1;
            }
            else kq+=high[w]-high[lcv]+1;
            res=max(res,kq);
}
int main()
{
            freopen("832D.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>n>>test;
            for (int i=2;i<=n;++i)
            {
                        int u;
                        cin>>u;
                        e[u].push_back(i);
                        e[i].push_back(u);
            }
            dfs(1,-1);
            memset(p,-1,sizeof(p));
            for (int i=1;i<=n;++i)
                        p[i][0]=trc[i];
            for (int j=1;(1<<j)<=n;++j)
                        for (int i=1;i<=n;++i)
                        if (p[i][j-1]!=-1)
                                    p[i][j]=p[p[i][j-1]][j-1];
            while(test--)
            {
                        int u,v,w;
                        cin>>u>>v>>w;
                        res=0;
                        solve(u,v,w);
                        solve(u,w,v);
                        solve(v,w,u);
                        cout<<res<<"\n";
            }
            return 0;
}
