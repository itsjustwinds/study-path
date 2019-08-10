#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
#define maxn 100005
using namespace std;
ll n,m,d,s1[maxn],s2[maxn],ans;
typedef pair<ll,ll> II;
II a[maxn],b[maxn],now;
bool cmp(const II &a,const II &b)
{
    if (a.fs==b.fs) return a.sc<b.sc;
    return a.fs>b.fs;
}
int findd(int l,int r,int x)
{
    int res=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (s2[m]<=x)
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
    freopen("795b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>d;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs>>a[i].sc;
    for (int i=1;i<=m;i++)
        cin>>b[i].fs>>b[i].sc;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=n;i++)
    {
        s1[i]=s1[i-1]+a[i].fs;
        s2[i]=s2[i-1]+a[i].sc;
    }
    for (int i=1;i<=m;i++)
    {
        now.fs+=b[i].fs;
        now.sc+=b[i].sc;
        int cur=findd(1,n,d-now.sc);
        if (cur==0) continue;
        ans=max(ans,now.fs+s1[cur]);
    }
    cout<<ans;
}
