#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
ll f[maxn/3][maxn][4];
int a[maxn],n,k;
int main()
{
        freopen("TKSEQ.inp","r",stdin);
        freopen("TKSEQ.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1; i<=n; ++i)
                cin>>a[i];
        for (int i=0; i<=n; ++i)
                for (int j=0; j<=k; ++j)
                        for (int h=1; h<=3; ++h)
                                f[i][j][h]=-1e18;
        f[0][0][3]=0;
        for (int i=1;i<=n;++i)
                f[i][0][3]=0;
        for (int j=1; j<=k; ++j)
        {
                for (int i=1; i<=n; ++i)
                {
                        for (int h=1; h<=3; ++h)
                        {
                                if (h==1) f[i][j][h]=max(f[i-1][j][h],f[i-1][j-1][3]+a[i]);
                                if (h==2) f[i][j][h]=max(f[i-1][j][h],f[i-1][j][1]-a[i]);
                                if (h==3) f[i][j][h]=max(f[i-1][j][h],f[i-1][j][2]+a[i]);
                        }
                }
        }
        cout<<f[n][k][3];
        return 0;
}
