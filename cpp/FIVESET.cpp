#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll f[6][100005];
int n,w1,w2,a[maxn];
int main()
{
        freopen("FIVESET.inp","r",stdin);
        //freopen("FIVESET.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>w1>>w2;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        f[1][0]=-1e18;
        for (int i=1;i<=n;++i)
                f[1][i]=max(f[1][i-1],1ll*a[i]*w1);
        f[2][0]=-1e18;
        for (int i=1;i<=n;++i)
                f[2][i]=max(f[2][i-1],f[1][i-1]+1ll*a[i]*w2);
        f[3][0]=-1e18;
        for (int i=1;i<=n;++i)
                f[3][i]=max(f[3][i-1],f[2][i-1]+1ll*a[i]);
        f[4][0]=-1e18;
        for (int i=1;i<=n;++i)
                f[4][i]=max(f[4][i-1],f[3][i-1]+1ll*a[i]*w2);
        f[5][0]=-1e18;
        for (int i=1;i<=n;++i)
                f[5][i]=max(f[5][i-1],f[4][i-1]+1ll*a[i]*w1);
        cout<<f[5][n];
        return 0;
}
