#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,k,a[maxn],sum[maxn],c[maxn],bit[maxn];
int findd(int x)
{
        int l=1,r=n+1;
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (c[m]<x)
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        return res+1;
}
void update(int u)
{
        while(u<maxn)
        {
                bit[u]++;
                u+=u&(-u);
        }
}
ll get(int u)
{
        ll res=0;
        while(u)
        {
                res+=bit[u];
                u-=u&(-u);
        }
        return res;
}
int main()
{
        freopen("KMEDIAN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                sum[i]=sum[i-1];
                if (x>=k) sum[i]++;
                else sum[i]--;
                c[i]=sum[i];
        }
        c[n+1]=0;
        sort(c+1,c+n+2);
        update(findd(0));
        ll ans=0;
        for (int i=1;i<=n;++i)
        {
                ans+=get(findd(sum[i]));
                update(findd(sum[i]));
        }
        cout<<ans;
}
