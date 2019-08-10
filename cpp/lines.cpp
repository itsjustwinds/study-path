#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn],n,vt[maxn],res,ans[maxn],f[maxn],ng[maxn],trace[maxn],dem;
int findd(int x)
{
    int kq=0;
    int l=1;int r=res;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (a[f[m]]<x)
        {
            kq=m;
            l=m+1;
        }
        else r=m-1;
    }
    return kq;
}
int main()
{
    freopen("lines.inp","r",stdin);
    freopen("lines.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++)
    {
        vt[b[i]]=i;
        ng[i]=b[i];
    }
    for (int i=1;i<=n;i++)
        a[i]=vt[a[i]];
    for (int i=1;i<=n;i++)
    if (a[i]>a[f[res]])
    {
        trace[i]=f[res];
        f[++res]=i;
    }
    else{
        int k=findd(a[i]);
        trace[i]=f[k];
        f[k+1]=i;
    }
    cout<<res<<"\n";
    int now=f[res];
    while(now)
    {
        cout<<ng[a[now]]<<" ";
        now=trace[now];
    }
    return 0;
}
