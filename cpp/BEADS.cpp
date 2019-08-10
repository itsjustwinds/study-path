#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,a[maxn],Finc[maxn],Fdec[maxn],MAXinc,MAXdec,res;
int FINDinc(int l,int r,int x)
{
    int res=0;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if (x>Finc[m])
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int FINDdec(int l,int r,int x)
{
    int res=0;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if (x<Fdec[m])
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
    freopen("BEADS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        int inc=FINDinc(1,MAXinc,a[i]);
        int dec=FINDdec(1,MAXdec,a[i]);
        Finc[inc+1]=a[i];
        Fdec[dec+1]=a[i];
        if (inc==MAXinc) ++MAXinc;
        if (dec==MAXdec) ++MAXdec;
        res=max(res,inc+dec+1);
    }
    cout<<res;
}
