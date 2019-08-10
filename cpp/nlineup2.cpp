#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int f[maxn],a[maxn],n,maxx,res1;
int find1(int x)
{
    int l=1;int r=maxx;
    while (l<r)
    {
        int vt=(l+r)/2;
        if (a[f[vt]]<=x) l=vt+1;
        else r=vt;
    }
    return l;
}
int find2(int x)
{
    int l=1;int r=maxx;
    while (l<r)
    {
        int vt=(l+r)/2;
        if (a[f[vt]]>=x) l=vt+1;
        else r=vt;
    }
    return l;
}
int main()
{
    freopen("nlineup.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        if (a[f[maxx]]<=a[i])
    {
        f[++maxx]=i;
    }
    else f[find1(a[i])]=i;
    res1=n-maxx;
    maxx=0;
    a[0]=10000000;
    for (int i=1;i<=n;i++)
        if (a[f[maxx]]>=a[i])
    {
        f[++maxx]=i;
    }
    else f[find2(a[i])]=i;
    cout<<min(res1,n-maxx);
    return 0;
}

