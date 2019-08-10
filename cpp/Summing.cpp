#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define ll long long
#define sc second
using namespace std;
typedef pair<int,int> II;
vector<II> e[maxn];
int n,a[maxn],sum[maxn],dem2,dem1,stage[maxn],trc[maxn];
long long res;
typedef pair<ll,int> III;
III f1[maxn],f2[maxn];
void dfs(int root,int u)
{
    if (u==1)
    {
        for (int i=0; i<(int)e[u].size(); i++)
        {
            int v=e[u][i].fs;
            stage[v]=stage[u]+1;
            sum[v]=sum[u]+e[u][i].sc;
            if (a[v])
            {
                f2[++dem2]=II(v,i);
            }
            else f1[++dem1]=II(v,i);
        if (a[1]==0&&a[v]==1) res=res+sum[v];
        if (a[1]==1&&a[v]==0) res=res+sum[v];
            dfs(i,v);
        }
        return;
    }
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i].fs;
        stage[v]=stage[u]+1;
        sum[v]=sum[u]+e[u][i].sc;
        if (a[v])
        {
            f2[++dem2]=II(v,root);
        }
        else f1[++dem1]=II(v,root);
        if (a[1]==0&&a[v]==1) res+=sum[v];
        if (a[1]==1&&a[v]==0) res+=sum[v];
        dfs(root,v);
    }
}
int main()
{
    freopen("summing.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(II(v,w));
        trc[v]=u;
    }
    dfs(-1,1);
    for (int i=1; i<=dem1; i++)
    {
        for (int j=1; j<=dem2; j++)
        {
            if (f1[i].sc==f2[j].sc)
            {
                int u=f1[i].fs;
                int tmp1=u;
                int v=f2[j].fs;
                int tmp2=v;
                while(stage[u]<stage[v])
                {
                    v=trc[v];
                }
                while(stage[u]>stage[v])
                {
                    u=trc[u];
                }
                while(u!=v)
                {
                    u=trc[u];
                    v=trc[v];
                }
                res+=sum[tmp1]+sum[tmp2]-2*sum[u];
            }
            else res+=sum[f1[i].fs]+sum[f2[j].fs];
        }
    }
    cout<<res;
    return 0;
}
