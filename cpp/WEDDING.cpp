#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n,g[maxn],f[maxn],res,s,t,trc[maxn],dd[maxn],D[maxn],nex[maxn];
vector<int >e[maxn];
vector<int > path;
void dfs(int u)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                trc[v]=u;
                dfs(v);
        }
}
int dfs2(int u,int trc)
{
        if (D[u]!=0) return D[u];
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                if (dd[v]) continue;
                D[u]=max(D[u],dfs2(v,u));
        }
        D[u]++;
        return D[u];
}
int main()
{
        freopen("WEDDING.inp","r",stdin);
        freopen("WEDDING.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2;i<=n;++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        cin>>s>>t;
        dfs(s);
        path.push_back(t);
        dd[t]=1;
        int tt=t;
        while(tt!=s)
        {
                nex[trc[tt]]=tt;
                tt=trc[tt];
                path.push_back(tt);
                dd[tt]=1;
        }
        int d=0;
        for (int i=path.size()-1;i>=0;--i)
        {
                int u=path[i];
                ++d;
                f[u]=max(f[trc[u]],d+dfs2(u,-1)-1);
        }
        d=0;
        for (int i=0;i<path.size();++i)
        {
                int u=path[i];
                ++d;
                g[u]=max(g[nex[u]],d+dfs2(u,-1)-1);
        }
        for (int i=0;i<path.size()-1;++i)
        {
                int u=path[i];
                int v=path[i+1];
                res=max(res,min(g[u],f[v]));
        }
        cout<<res;
        return 0;
}
