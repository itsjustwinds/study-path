#include<bits/stdc++.h>
#define maxn 606
using namespace std;
int f[maxn][maxn],g[maxn][maxn],a[maxn][maxn],n,m,res,ok;
int main()
{
        freopen("11499.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        while(cin>>n>>m)
        {
                for (int i=1;i<=n;++i)
                        for (int j=1;j<=m;++j)
                        cin>>a[i][j];
                for (int i=1;i<=n;++i)
                        for (int j=1;j<=m;++j)
                        g[i][j]=1;
                for (int i=1;i<=n;++i)
                        for (int j=1;j<=m;++j)
                {
                        int tmp=1;
                        for (int k=j+1;k<=m;++k)
                        if (a[k][j]>a[k-1][j]) ++tmp;
                        else break;
                        res=max(res,tmp);
                }
                for (int k=2;k<=n;++k)
                {
                        for (int i=1;i<=n-k+1;++i)
                        for (int j=1;j<=m;++j)
                        {
                                if (!g[i][j]) continue;
                                if(a[i+k-1][j]>a[i+k-2]) g[i][j]=1;
                                else g[i][j]=0;
                        }
                        for (int i=1;i<=n-k+1;++i)
                        for (int j=1;j<=m;++j)
                        f[i][j]=g[i][j];
                        for (int h=2;h<=m;++h)
                        {

                        }
                }
        }
}
