#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n;
ll a[maxn],bit[maxn],ans,res,maxx;
ll get(int u)
{
    ll kq=1000000000;
    while(u)
    {
        kq=min(kq,bit[u]);
        u-=u&(-u);
    }
    return min(0LL,kq);
}
void update(ll sum,int u)
{
    while(u<=n)
    {
        bit[u]=min(bit[u],sum);
        u+=u&(-u);
    }
}
int main()
{
    freopen("TheMaximumSubarray.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i_love_u;
    cin>>i_love_u;
    while(i_love_u--)
    {
        cin>>n;
        res=-1000000000,ans=0;
        maxx=-1000000000;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxx=max(maxx,a[i]);
        }
        if (maxx<0)
        {
            cout<<maxx<<" "<<maxx<<"\n";
            continue;
        }
        for (int i=1;i<=n;i++)
            bit[i]=1000000000;
        ll sum=0;
        for (int i=1;i<=n;i++)
        {
            if(a[i]>0) ans+=a[i];
            sum+=a[i];
            ll k=get(i-1);
            update(sum,i);
            res=max(res,sum-k);
        }
        cout<<res<<" "<<ans<<"\n";
    }
    return 0;
}
