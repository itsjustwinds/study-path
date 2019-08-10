#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f1[5000000],f2[5000000],a[55],m;
ll n,dem1,dem2;
void dfs1(int i,ll s)
{
    if (i==n/2+1) return;
        if (s+a[i]<=m)
    {
        f1[++dem1]=s+a[i];
        dfs1(i+1,s+a[i]);
    }
    dfs1(i+1,s);
}
void dfs2(int i,ll s)
{
    if (i==n+1) return;
    if (s+a[i]<=m)
    {
        f2[++dem2]=s+a[i];
        dfs2(i+1,s+a[i]);
    }
        dfs2(i+1,s);
}
ll findd(int l,int r,ll x)
{
    ll res=0;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (f2[m]<=x)
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int main()
{
    freopen("festival.inp","r",stdin);
    //freopen("festival.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dfs1(1,0);
    dfs2(n/2+1,0);
    ll res=dem1+dem2;
    sort(f1+1,f1+dem1+1);
    sort(f2+1,f2+dem2+1);
    for (int i=1;i<=dem1;i++)
    {
        //for (int j=1;j<=dem2;j++)
        //    if (f1[i]+f2[j]<=m) res++;
        //else break;
        res+=findd(1,dem2,m-f1[i]);
    }
    cout<<res;
    return 0;
}
