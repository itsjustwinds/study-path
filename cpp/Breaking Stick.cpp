#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
ll f[maxn],n,ans;
vector<ll > p;
ll tinh(ll x,vector<ll > p)
{
    if (x<maxn) return f[x];
    if (p.size()==1) return x+1;
    ll k=p.back();
    p.pop_back();
    return tinh(x/k,p)*k+1;
}
int main()
{
    freopen("Breaking Stick.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[1]=1;
    for (ll i=1; i<maxn; ++i)
        for (ll j=2; i*j<maxn; ++j)
            f[i*j]=max(f[i*j],f[i]*j+1);
    cin>>n;
    while(n--)
    {
        ll x;
        cin>>x;
        ll X=x;
        if (x==1)
        {
            ans++;
            continue;
        }
        p.clear();
        if (x<maxn)
        {
            ans+=f[x];
            continue;
        }
        for (ll i=2; i*i<=x; ++i)
            if (x%i==0)
            {
                while(x%i==0)
                {
                    x/=i;
                    p.push_back(i);
                }
            }
        if (x!=1) p.push_back(x);
        ans+=tinh(X,p);
    }
    cout<<ans;
}
