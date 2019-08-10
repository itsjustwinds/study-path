#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll n,a[maxn],x[maxn];
ll res,f[maxn];
bool check(ll m)
{
        for (int i=1; i<=n; ++i)
        {
                f[i]=a[i];
        }
        for (int i=1; i<=n; ++i)
        {
                if (f[i]>=m) continue;
                for (int j=1; j<=n; ++j)
                {
                        if (i==j) continue;
                        if (f[j]-m-abs(x[i]-x[j])<=0) continue;
                        ll d=min(f[j]-m,m-f[i]+abs(x[i]-x[j]));
                        f[i]+=d-abs(x[i]-x[j]);
                        f[j]-=d;
                        if (f[i]>=m) break;
                }
                if (f[i]<m) return 0;
        }
        return 1;
}
int main()
{
        freopen("RICE.inp","r",stdin);
        freopen("RICE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                cin>>x[i]>>a[i];
        ll l=1,r=1e12;
        while(l<=r)
        {
                ll m=(l+r)>>1;
                if (check(m))
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        cout<<res;
}
