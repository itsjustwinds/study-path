#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,m;
ll sumW[maxn],sumDW[maxn];
struct data
{
        int d,w;
};
data a[maxn];
bool cmp(data a,data b)
{
        return a.d<b.d;
}
int findd(int l,int r,int x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (a[m].d<=x)
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
        freopen("TALENT.inp","r",stdin);
        freopen("TALENT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>n>>test;
        for (int i=1;i<=n;++i)
                cin>>a[i].d;
        for (int i=1;i<=n;++i)
                cin>>a[i].w;
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                sumW[i]=sumW[i-1]+a[i].w;
                sumDW[i]=sumDW[i-1]+1ll*a[i].d*a[i].w;
        }
        while(test--)
        {
                int p;
                cin>>p;
                int x=findd(1,n,p);
                ll res=0;
                res-=sumDW[x];
                res+=1ll*sumW[x]*p;
                res+=sumDW[n]-sumDW[x];
                res-=1ll*(sumW[n]-sumW[x])*p;
                cout<<res<<"\n";
        }
        return 0;
}
