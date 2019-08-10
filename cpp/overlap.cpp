#include<bits/stdc++.h>
#define maxn 1005
#define fs first
#define sc second
using namespace std;
int n,f[maxn],trace[maxn],now,dem,ans[maxn];
typedef pair<int,int> II;
typedef pair<II,int> III;
III a[maxn];
bool cmp(const III &a,const III &b)
{
    return a.fs.sc<b.fs.sc;
}
int main()
{
    freopen("overlap.inp","r",stdin);
    //freopen("overlap.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs.fs>>a[i].fs.sc;
        for (int i=1;i<=n;i++)
            a[i].sc=i;
    sort(a+1,a+n+1,cmp);
    f[1]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
            if (a[i].fs.fs==a[j].fs.sc)
        {
            if (f[j]+1>f[i])
            {
                trace[i]=j;
                f[i]=f[j]+1;
            }
        }
    int res=0;
    for (int i=1;i<=n;i++)
    if (f[i]>res)
    {
        res=f[i];
        now=i;
    }
    cout<<res<<"\n";
    while(now)
    {
        ans[++dem]=a[now].sc;
        now=trace[now];
    }
    for (int i=dem;i>=1;i--)
        cout<<ans[i]<<"\n";
    return 0;
}
