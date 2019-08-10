#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 1000000007
using namespace std;
ll p[maxn][32];
ll a[maxn],res;
int n;
ll get(int l,int r)
{
            int log=log2(r-l+1);
            ll tmp=__gcd(p[l][log],p[r-(1<<log)+1][log]);
            return tmp;
}
int findd(int l,int r,ll x,int k)
{
            int kq=0;
            while(l<=r)
            {
                        int m=(l+r)>>1;
                        if (x<get(m,k))
                        {
                                    kq=m;
                                    r=m-1;
                        }
                        else l=m+1;
            }
            return kq;
}
int main()
{
            freopen("VOGCDSUM.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1;i<=n;++i)
                        cin>>a[i];
            for (int i=1;i<=n;++i)
                        p[i][0]=a[i];
            for (int j=1;(1<<j)<=n;++j)
            {
                        for (int i=1;i+(1<<j)-1<=n;++i)
                                    p[i][j]=__gcd(p[i][j-1],p[i+(1<<(j-1))][j-1]);
            }
            for (int i=1;i<=n;++i)
            {
                        int l=1;
                        while(l<=i)
                        {
                                    int tmp=findd(l,i,get(l,i),i);
                                    if (tmp==0) tmp=i+1;
                                    ll s=get(l,i)%mod;
                                    ll t=tmp-l;
                                    res=(res+(s*t)%mod)%mod;
                                    l=tmp;
                        }
            }
            cout<<res;
            return 0;
}
