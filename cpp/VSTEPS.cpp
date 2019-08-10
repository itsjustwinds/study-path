#include<bits/stdc++.h>
#define maxn 100005
#define mod 14062008
using namespace std;
int f[maxn],n,k,a[maxn];
int main()
{
        freopen("VSTEPS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=k;++i)
        {
                int x;
                cin>>x;
                a[x]=1;
        }
        f[1]=1;
        if (!a[2]) f[2]=1;
        for (int i=3;i<=n;++i)
        {
                if (a[i]) continue;
                f[i]=(f[i]+f[i-1])%mod;
                f[i]=(f[i]+f[i-2])%mod;
        }
        cout<<f[n];
        return 0;
}
