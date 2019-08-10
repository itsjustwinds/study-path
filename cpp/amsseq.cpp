#include <bits/stdc++.h>
#define maxn 10020
#define maxx 10000000
using namespace std;
long long f[maxn],n,a[maxn],k;
int main()
{
    //freopen("amsseq.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        f[i]=-maxx;
    long long res=-maxx;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=1;j<=k;j++)
        if (f[i]+a[i+j]>f[i+j])
        {
            f[i+j]=f[i]+a[i+j];
        }
    }
    for (int i=0;i<=n;i++)
        res=max(res,f[i]);
    cout<<res;
    return 0;
}
