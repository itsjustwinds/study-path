#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int cha[maxn],n,p[maxn][35],h[maxn],maxh;
vector<int> e[maxn];
void dfs(int u,int trc)
{
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i];
                if (v==trc) continue;
                h[v]=h[u]+1;
                maxh=max(maxh,h[v]);
                dfs(v,u);
        }
}
int lca(int u,int v)
{
        if (h[u]<h[v]) swap(u,v);
        int log=log2(h[u]);
        for (int i=log;i>=0;i--)
        {
                if (h[u]-(1<<i)>=h[v]) u=p[u][i];
        }
        if (u==v) return u;
        for (int i=log;i>=0;i--)
        {
                if (p[u][i]!=p[v][i]&&p[u][i]!=-1&&p[v][i]!=-1)
                {
                        u=p[u][i];
                        v=p[v][i];
                }
        }
        return cha[u];
}
int main()
{
        freopen("LCA.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int tt;
        cin>>tt;
        for (int ii=1;ii<=tt;ii++)
        {
                cin>>n;
                for (int i=1;i<=n;i++) cha[i]=0;
                for (int i=1;i<=n;i++) e[i].clear();
                for (int i=1;i<=n;i++)
                {
                        int m;
                        cin>>m;
                        for (int j=1;j<=m;j++)
                        {
                                int x;
                                cin>>x;
                                cha[x]=i;
                                e[i].push_back(x);
                        }
                }
                int root;
                maxh=1;
                for (int i=1;i<=n;i++)
                        if (cha[i]==0) root=i;
                h[root]=1;
                dfs(root,-1);
                memset(p,-1,sizeof(p));
                for (int i=1;i<=n;i++)
                {
                        p[i][0]=cha[i];
                }
                for (int j=1;1<<j<=n;j++)
                {
                        for (int i=1;i<=n;i++)
                        if (p[i][j-1]!=-1)
                        {
                                p[i][j]=p[p[i][j-1]][j-1];
                        }
                }
                int q;
                cin>>q;
                cout<<"Case "<<ii<<":\n";
                while(q--)
                {
                        int u,v,w;
                        cin>>u>>v;
                        w=lca(u,v);
                        cout<<w<<"\n";
                }
        }
}
