#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
#define db double
using namespace std;
int a[maxn],n,k,sum[maxn],c[maxn],bit[maxn];
int findd(int x)
{
        int l=1,r=n+1,res=0;
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
void update(int x)
{
        while(x<maxn)
        {
                bit[x]++;
                x+=x&(-x);
        }
}
ll get(int x)
{
        ll res=0;
        while(x)
        {
                res+=bit[x];
                x-=x&(-x);
        }
        return res;
}
ll cal(int k)
{
        memset(bit,0,sizeof bit);
        ll res=0;
        for (int i=1;i<=n;++i)
        {
                sum[i]=sum[i-1];
                if (a[i]>=k) sum[i]++;
                else sum[i]--;
                c[i]=sum[i];
        }
        c[n+1]=0;
        sort(c+1,c+n+2);
        update(findd(0));
        for (int i=1;i<=n;++i)
        {
                res+=get(findd(sum[i]));
                update(findd(sum[i]));
        }
        return res;
}
int main()
{
        freopen("NKLUCK.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        ll tmp=cal(k)-cal(k+1);
        ll tmp1=1ll*n*(n+1)/2;
        db res=(db)tmp/tmp1;
        cout<<setprecision(6)<<fixed<<res;
        return 0;
}
