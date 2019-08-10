#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll di[1005],a[maxn],n,m,f[maxn],minn,maxx,dd[1005];
char s[maxn];
int tinh(int r)
{
    int now=0;
    int kq=0;
    while(now<=m)
    {
        now+=r;
        kq++;
        if (now>=m+1) return kq;
        while (s[now]=='1') now--;
    }
    return kq;
}
int main()
{
    freopen("CROSS12.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    maxx=-1000000;
    minn=1000000;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        dd[a[i]]=1;
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
    }
    cin>>(s+1);
    m=strlen(s+1);
    for (int i=minn;i<=maxx;i++)
        if (dd[i])
        di[i]=tinh(i);
    for (int i=1;i<=n;i++)
        a[i]=di[a[i]];
    sort(a+1,a+n+1);
    f[1]=a[1];
    f[2]=a[2];
    for (int i=3;i<=n;i++)
    {
        f[i]=min(f[i-1]+a[1]+a[i],f[i-2]+a[1]+a[i]+2*a[2]);
    }
    cout<<f[n];
    return 0;
}
