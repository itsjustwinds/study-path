#include<bits/stdc++.h>
using namespace std;
int f[5000],n,p,q,a[5000],b[5000];
int main()
{
    //freopen("hr47b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p>>q;
    for (int i=1; i<=p; i++)
        cin>>a[i];
    for (int i=1; i<=q; i++)
        cin>>b[i];
    for (int i=1; i<=p; i++)
        for (int j=1; j<=q; j++)
                f[n-(a[i]+b[j])%n]++;
    int res=1,rem=f[1];
    for (int i=2; i<=n; i++)
        if (f[i]<rem)
        {
            res=i;
            rem=f[i];
        }
    cout<<res;
    return 0;
}
