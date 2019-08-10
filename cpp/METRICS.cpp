#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
struct data
{
        int val,id;
};
int a[maxn],n,m;
data b[maxn];
ll res,sumJ[maxn],sumB[maxn],sumFB[maxn],sumBi[maxn];
bool cmp(data a,data b)
{
        return a.val<b.val;
}
int findd(int l,int r,int x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (x>=b[m].val)
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
        freopen("METRICS.inp","r",stdin);
        //freopen("METRICS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        cin>>m;
        for (int i=1;i<=m;++i)
        {
                cin>>b[i].val;
                b[i].id=i;
        }
        sort(b+1,b+m+1,cmp);
        for (int i=1;i<=m;++i)
                sumB[i]=sumB[i-1]+b[i].val;
        for (int i=1;i<=m;++i)
                sumJ[i]=sumJ[i-1]+b[i].id;
        for (int i=1;i<=m;++i)
                sumFB[i]=sumFB[i-1]+1ll*b[i].id*b[i].val;
        for (int i=1;i<=n;++i)
        {
                int idx=findd(1,m,a[i]);
                res+=1ll*idx*i*a[i]-1ll*i*sumB[idx]-1ll*a[i]*sumJ[idx]+sumFB[idx];
                res-=1ll*i*a[i]*(m-idx)-1ll*i*(sumB[m]-sumB[idx])-1ll*a[i]*(sumJ[m]-sumJ[idx])+(sumFB[m]-sumFB[idx]);
        }
        cout<<res;
        return 0;
}
