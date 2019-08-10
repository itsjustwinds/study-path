#include<bits/stdc++.h>
#define maxn 200005
#include<fstream>
using namespace std;
ifstream fi("ccc.inp");
ofstream fo("ccc.out");
int root[maxn],n,m,h[maxn],res;
int findroot(int u)
{
    while(root[u]!=u) u=root[u];
    return u;
}
void unionn(int u,int v)
{
    if (h[u]>h[v])
    {
        root[v]=u;
        return;
    }
    root[u]=v;
    h[v]=max(h[u]+1,h[v]);
    return;
}
int main()
{
    //freopen("ccc.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n>>m;
    for (int i=1;i<=n;i++)
    {
        root[i]=i;
        h[i]=1;
    }
    res=n;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        fi>>u>>v;
        int ru=findroot(u);
        int rv=findroot(v);
        if (ru!=rv)
        {
            unionn(ru,rv);
            res--;
        }
        fo<<res<<"\n";
    }
    return 0;
}
