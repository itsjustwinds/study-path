#include<bits/stdc++.h>
#define maxn 25005
using namespace std;
int f[maxn],n,a[maxn];
int main()
{
    //freopen("nkcable.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n-1;i++)
        cin>>a[i];
    f[2]=a[1];
    f[3]=f[2]+a[2];
    for (int i=4;i<=n;i++)
        f[i]=min(f[i-1],f[i-2])+a[i-1];
    cout<<f[n];
    return 0;
}
