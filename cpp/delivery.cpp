#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int f[maxn],n,k,t,z[maxn],a[maxn];
int main()
{
    freopen("delivery.inp","r",stdin);
    freopen("delivery.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>t;
    for (int i=0;i<n;i++)
        cin>>z[i];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+z[i-1];
        int l=f[i]+k;
        if (l>=a[i]) f[i]+=max(0,(k-(l-a[i])))+t;
        else f[i]+=k;
    }
    //f[n]=f[n-1]+z[n-1];
    //if (f[n]+k>=a[n]) f[n]+=k+t;
    cout<<f[n];
    return 0;
}
