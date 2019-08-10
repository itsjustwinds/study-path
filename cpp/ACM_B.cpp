#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int a[maxn],n,h[maxn],bit[maxn],trc[maxn];
ll f[maxn],sum[maxn];
int get(int u)
{
        int res=0;
        while(u<maxn)
        {
                res=max(res,bit[u]);
                u+=u&(-u);
        }
        return res;
}
void update(int u,int val)
{
        while(u)
        {
                bit[u]=max(bit[u],val);
                u-=u&(-u);
        }
}
int cal(ll x)
{
        int res=0;
        int l=1,r=n;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (x>f[m])
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
        freopen("ACM_B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                for (int i=1; i<=n; ++i)
                        cin>>a[i];
                for (int i=1; i<=n; ++i)
                {
                        cin>>h[i];
                        sum[i]=sum[i-1]+h[i];
                }
                h[0]=1e6;
                a[0]=-1;
                memset(bit,0,sizeof bit);
                for (int i=1; i<=n; ++i)
                {
                        trc[i]=0;
                        trc[i]=get(h[i]);
                        update(h[i],i);
                }
                //memset(f,0,sizeof f);
                for (int i=1; i<=n; ++i)
                {
                        f[i]=f[trc[i]]+1ll*(a[i]-a[trc[i]]-1)*(h[i])-(sum[i-1]-sum[trc[i]]);
                }
                int q;
                cin>>q;
                while(q--)
                {
                        ll k;
                        cin>>k;
                        cout<<cal(k)<<"\n";
                }
        }
}
