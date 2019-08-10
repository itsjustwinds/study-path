#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll dd[maxn],n;
vector<ll > ngto,res;
ll ans;
ll tinh(ll a,ll n)
{
        if (n==0) return 1;
        if (n==1) return a;
        ll tmp=tinh(a,n>>1);
        tmp=tmp*tmp;
        if (n&1) tmp=tmp*a;
        return tmp;
}
ll f[maxn];
int main()
{
        //freopen("FINDNUM.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2;i*i<maxn;++i)
        if (!dd[i])
        {
                for (int j=i*i;j<maxn;j+=i)
                        dd[j]=1;
        }
        for (int i=1;i<=maxn;++i)
                f[i]=1e18;
        for (int i=2;i<maxn&&ngto.size()<=10;++i)
        if(!dd[i]) ngto.push_back(i);
        f[1]=1;
        for (int i=0;i<ngto.size();++i)
        {
                ll x=ngto[i];
                for (int j=n-1;j>=1;--j)
                {
                        ll d=1;
                        ll k=x;
                        while(f[j]*k>0&&j*(d+1)<=n)
                        {
                               f[j*(d+1)]=min(f[j*(d+1)],1ll*f[j]*k);
                               k*=x;
                               ++d;
                        }
                }
        }
        cout<<f[n];
}
