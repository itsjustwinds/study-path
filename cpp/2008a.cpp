#include<bits/stdc++.h>
#define maxn 100005
#define mod 14062008
using namespace std;
int n,k,dd[maxn],a[maxn];
int main()
{
    //freopen("2008a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    a[1]=1;
    for (int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
         dd[x]=1;
    }
    for (int i=1;i<=n;i++)
        if (!dd[i])
    {
        a[i+1]=(a[i+1]+a[i])%mod;
        a[i+2]=(a[i+2]+a[i])%mod;
    }
    cout<<a[n];
    return 0;
}
