
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    freopen("codefor1.inp","r",stdin);
    ios::sync_with_stdio(0);
    ll n,l,r,m=0,x,ans=0;
    cin>>n>>l>>r;
    x=n;
    do
    {
        x=x>>1LL;
        m++;
    }
    while(x!=0);
    for(ll i=l; i<=r; i++)
    {
        x=i&(-i);
        x=log2(x);
        if(n&(1LL<<(m-x-1)))
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
