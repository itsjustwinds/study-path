#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int d[maxn],c[maxn],a[maxn],f[maxn],n,dd[maxn],maxx;
int main()
{
    //freopen("811c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (d[a[i]]==0)d[a[i]]=i;
        c[a[i]]=i;
        maxx=max(maxx,a[i]);
    }
    for (int i=1;i<=n;i++)
    if (d[a[i]]==i)
    {
        int sum=a[i];
        for (int j=1;j<=maxx;j++) dd[j]=0;
        dd[a[i]]=1;
        int l=d[a[i]],r=c[a[i]];
        int lc=-1,rc=-1;
        while(1)
        {
            lc=l;rc=r;
            for (int j=l;j<=r;j++)
            if (!dd[a[j]])
            {
                lc=min(lc,d[a[j]]);
                rc=max(rc,c[a[j]]);
                dd[a[j]]=1;
                sum=sum^a[j];
            }
            if (lc==l&&rc==r) break;
            l=lc;r=rc;
        }
        for (int j=0;j<l;j++)
        {
            f[r]=max(f[r],f[j]+sum);
        }
    }
    int res=0;
    for (int i=1;i<=n;i++)
        res=max(res,f[i]);
    cout<<res;
    return 0;
}
