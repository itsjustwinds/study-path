#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef pair <int,int>II;
typedef pair <int,II>III;
int root[10001],n,m,s[10001],h[10001],dem,res;
III f[10001];
int getroot(int u)
{
    while (root[u]!=u) u=root[u];
    return u;
}
void unionn(int u,int v)
{
    if (h[u]<h[v]) root[u]=v;
    else
    {
        h[u]=max(h[u],h[v]+1);
        root[v]=u;
    }
}
int main()
{
    freopen("bear.inp","r",stdin);
    //freopen("bear.out","w",stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    for (int i=1;i<=m;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        f[i].fs=2*t+s[x]+s[y];
        //f[i].fs=t;
        f[i].sc.fs=x;
        f[i].sc.sc=y;
    }
    sort(f+1,f+m+1);
    for (int i=1;i<=n;i++)
    {
        root[i]=i;
        h[i]=0;
    }
    for (int i=1;i<=m;i++)
    {
        int u=getroot(f[i].sc.fs);
        int v=getroot(f[i].sc.sc);
        if (u!=v)
        {
            dem++;
            res+=f[i].fs;
            //res+=2*f[i].fs+s[f[i].sc.fs]+s[f[i].sc.sc];
            unionn(u,v);
        }
        if (dem==n-1) break;
    }
    cout<<res+s[1];
    return 0;
}
