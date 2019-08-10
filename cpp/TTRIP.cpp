#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int a[maxn][maxn],f[maxn][maxn],n,dd[maxn];
long long res;
int main()
{
        freopen("TTRIP.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                {
                        cin>>a[i][j];
                }
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                if (a[i][j]) f[i][j]=a[i][j];
        else f[i][j]=1e9;
        for (int k=1;k<=n;++k)
                for (int u=1;u<=n;++u)
                for (int v=1;v<=n;++v)
                f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
        for (int i=1;i<=n;++i)
                f[i][i]=0;
        int u=1;
        dd[1]=1;
        while(1)
        {
                int k=0;
                int minn=1e9;
                for (int v=1;v<n;++v)
                {
                        if (dd[v]) continue;
                        if (minn>f[u][v])
                        {
                                minn=f[u][v];
                                k=v;
                        }
                }
                if (k==0) break;
                res+=minn;
                u=k;
                dd[u]=1;
        }
        res+=f[u][n];
        cout<<res;
        return 0;
}
