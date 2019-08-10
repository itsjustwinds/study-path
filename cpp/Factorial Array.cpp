#include<bits/stdc++.h>
#define maxn 100005
#define block 400
#define mod 1000000000
#define ll long long
using namespace std;
ll gt[50],n,a[maxn];
struct data
{
    ll sum,min;
};
ll pos(ll i)
{
    ll k=(i-1)/block+1;
    return k;
}
data f[maxn];
ll tinh(ll x)
{
    if (x>=40) return 0;
    return gt[x];
}
int main()
{
    freopen("Factorial Array.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    gt[1]=1;
    for (ll i=2; i<=40; ++i)
        gt[i]=(1ll*gt[i-1]*i)%mod;
    cin>>n>>test;
    for (ll i=1;i<=n;++i)
        f[i].min=1000;
    for (ll i=1; i<=n; ++i)
    {
        cin>>a[i];
        f[pos(i)].min=min(a[i],f[pos(i)].min);
        f[pos(i)].sum=(f[pos(i)].sum+tinh(a[i]))%mod;
    }
    while(test--)
    {
        ll c,u,v;
        cin>>c>>u>>v;
        if (c==1)
        {
            ll start=pos(u);
            ll last=pos(v);
            for (ll i=start; i<=last; ++i)
            {
                if (f[i].min>=40)
                {
                    f[i].min++;
                    f[i].sum=0;
                    continue;
                }
                ll MIN=100000;
                for (ll j=(i-1)*block+1;j<=i*block;++j)
                {
                    if (j<u||j>v)
                    {
                        MIN=min(MIN,a[j]);
                        continue;
                    }
                    a[j]++;
                    MIN=min(MIN,a[j]);
                    f[i].sum=(f[i].sum-tinh(a[j]-1)+mod)%mod;
                    f[i].sum=(f[i].sum+tinh(a[j]))%mod;
                }
                f[i].min=MIN;
            }
        }
        if (c==2)
        {
            ll res=0;
            ll start=pos(u)+1;
            ll last=pos(v)-1;
            if (start>=last)
            {
                for (ll i=u;i<=v;++i)
                    res=(res+tinh(a[i]))%mod;
                cout<<res<<"\n";
                continue;
            }
            for (ll i=start;i<=last;++i)
                res=(res+f[i].sum)%mod;
            for (ll i=u;i<(start-1)*block+1;++i)
                res=(res+tinh(a[i]))%mod;
            for (ll i=last*block+1;i<=v;++i)
                res=(res+tinh(a[i]))%mod;
            cout<<res<<"\n";
        }
        if (c==3)
        {
            ll start=pos(u);
            f[start].sum=(f[start].sum-tinh(a[u])+mod)%mod;
            a[u]=v;
            f[start].sum=(f[start].sum+tinh(a[u]))%mod;
            ll MIN=1100;
            for (ll i=(start-1)*block+1;i<=start*block;++i)
                MIN=min(MIN,a[i]);
            f[start].min=MIN;
        }
    }
}
