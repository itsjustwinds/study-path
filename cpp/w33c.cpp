#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],x,n,k,root[100005],res,d1[maxn],d2[maxn],f[maxn][maxn];
int get(int u)
{
    while(root[u]!=u) u=root[u];
    return u;
}
void unions(int u,int v)
{
    root[u]=root[v];
}
int main()
{
    freopen("w33c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>k>>n;
    for (int i=1;i<=x;i++)
        root[i]=i;
    for (int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        int ru=get(u);
        int rv=get(v);
        if (ru!=rv)unions(ru,rv);
    }
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        d1[i]=get(a[i]);
    for (int i=1;i<=n;i++)
        d2[i]=d1[n-i+1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
    {
        if (d1[i]==d2[j]) f[i][j]=f[i-1][j-1]+1;
        f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]));
        res=max(res,f[i][j]);
    }
    cout<<res;
    return 0;
}
