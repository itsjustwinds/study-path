#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define sc second
using namespace std;
int f[maxn][4],n,res[maxn];
vector<int> e[maxn];
typedef pair<int,int> II;
vector<II> trc[maxn][4];
void dfs(int u,int truoc)
{
    for (int j=0; j<(int)e[u].size(); j++)
    {
        int v=e[u][j];
        if (v==truoc) continue;
        dfs(v,u);
    }
    for (int i=1; i<=3; i++)
    {
        f[u][i]=i;
        for (int j=0;j<(int)e[u].size();j++)
        {
            int v=e[u][j];
            int minn=1000000000;
            II tmp=II(v,0);
            for (int k=1;k<=3;k++)
            {
                if (k==i) continue;
                if (f[v][k]<minn)
                {
                    minn=f[v][k];
                    tmp.sc=k;
                }
            }
            f[u][i]+=minn;
            trc[u][i].push_back(tmp);
        }
    }
}
void dfs2(int u,int truoc,int k)
{
    res[u]=k;
    for (int i=0;i<(int)trc[u][k].size();i++)
    {
        II tmp=trc[u][k][i];
        if (tmp.fs==truoc) continue;
        dfs2(tmp.fs,u,tmp.sc);
    }
}
int main()
{
    freopen("CTREE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,-1);
    if (f[1][1]==min(f[1][1],min(f[1][2],f[1][3])))
    {
        cout<<f[1][1]<<"\n";
        dfs2(1,-1,1);
    }
    else if (f[1][2]==min(f[1][1],min(f[1][2],f[1][3])))
    {
        cout<<f[1][2]<<"\n";
        dfs2(1,-1,2);
    }
    else
    {
        cout<<f[1][3]<<"\n";
        dfs2(1,-1,3);
    }
    for (int i=1;i<=n;i++)
        cout<<res[i]<<"\n";
    return 0;
}
