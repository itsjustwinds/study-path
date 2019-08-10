#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int ac[maxn],a[maxn],n,dd[maxn],trc[maxn],f[maxn],dem;
int main()
{
    //freopen("frogjumps.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ac[i]=a[i];
    }
    sort(ac+1,ac+n+1);
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;
    for (int i=1;i<=n;i++)
    {
        if (dd[a[i]])
        {
            trc[i]=dd[a[i]];
            dd[a[i]]=i;
        }
        else dd[a[i]]=i;
    }
    f[1]=0;
    for (int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+1;
        if (trc[i]) f[i]=min(f[i],f[trc[i]]+1);
    }
    cout<<f[n];
    return 0;
}
