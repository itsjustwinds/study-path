#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,p[maxn][35],trc[maxn],high[maxn],root;
vector<int> e[maxn];
void dfs(int u,int t)
{
            high[u]=high[trc[u]]+1;
            for (int i=0; i<(int)e[u].size(); ++i)
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
            for (int i=log; i>=0; --i)
                        if (high[u]-(1<<i)>=high[v])
                        {
                                    u=p[u][i];
                        }
            if (u==v) return u;
            for (int i=log; i>=0; --i)
                        if (p[u][i]!=p[v][i]&&p[u][i]!=-1&&p[v][i]!=-1)
                        {
                                    u=p[u][i];
                                    v=p[v][i];
                        }
            return trc[u];
}
int main()
{
            freopen("HBTLCA.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            while(cin>>n)
            {
                        if (n==0) return 0;
                        for (int i=1; i<=n; ++i)
                                    e[i].clear();
                        for (int i=2; i<=n; ++i)
                        {
                                    int u,v;
                                    cin>>u>>v;
                                    e[u].push_back(v);
                                    e[v].push_back(u);
                        }
                        root=1;
                        dfs(1,-1);
                        memset(p,-1,sizeof(p));
                        for (int i=1; i<=n; ++i)
                                    p[i][0]=trc[i];
                        for (int j=1; (1<<j)<=n; ++j)
                        {
                                    for (int i=1; i<=n; ++i)
                                                if (p[i][j-1]!=-1)
                                                {
                                                            p[i][j]=p[p[i][j-1]][j-1];
                                                }
                        }
                        int test;
                        cin>>test;
                        while(test--)
                        {
                                    char x;
                                    cin>>x;
                                    if (x=='!')
                                    {
                                                cin>>root;
                                                continue;
                                    }
                                    int u,v;
                                    cin>>u>>v;
                                    if (root==1)
                                    {
                                                cout<<lca(u,v)<<"\n";
                                                continue;
                                    }
                                    int lcu=lca(u,root);
                                    int lcv=lca(v,root);
                                    int luv=lca(u,v);
                                    if (high[lcu]>=high[lcv]&&high[lcu]>=high[luv])
                                    {
                                                cout<<lcu<<"\n";
                                                continue;
                                    }
                                    if (high[lcv]>=high[lcu]&&high[lcv]>=high[luv])
                                    {
                                                cout<<lcv<<"\n";
                                                continue;
                                    }
                                    cout<<luv<<"\n";
                        }
            }
}
