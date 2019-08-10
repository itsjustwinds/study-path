#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
int main()
{
    freopen("803c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if ((double)k*(k+1)/2>n)
    {
        cout<<-1;
        return 0;
    }
    for (ll a=1; a*a<=n; a++)
    {
        if (n%a) continue;
        ll i=a;
        ll tmp=((i+i*k)*k)/2;
        if (tmp<=n)
        {
            ll tmp2=n-tmp;
            if (tmp2%i==0)
            {
                ans=max(ans,i);
            }
        }
        i=n/a;
        tmp=((i+i*k)*k)/2;
        if (tmp<=n)
        {
            ll tmp2=n-tmp;
            if (tmp2%i==0)
            {
                ans=max(ans,i);
            }
        }
    }
    if (ans)
    {
        ll d=0;
        for (int j=1; j<=k-1; j++)
        {
            cout<<ans*j<<" ";
            d+=ans*j;
        }
        cout<<n-d;
        return 0;
    }
    cout<<-1;
    return 0;
}
