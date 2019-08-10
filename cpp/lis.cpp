#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
int f[maxn],a[maxn],n,res;
int get(int l,int r,int x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (f[m]<x)
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
        freopen("LIS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        f[1]=a[1];
        res=1;
        for (int i=2;i<=n;++i)
        {
                int x=get(1,res,a[i]);
                if (x==res)++res;
                f[x+1]=a[i];
        }
        cout<<res;
}
