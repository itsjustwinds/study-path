#include<bits/stdc++.h>
#define maxn 1005
#define oo 1000000000000000LL
#define ll long long
using namespace std;
ll f[maxn][maxn][3],c[maxn][maxn];
int n,m;
int main()
{
    freopen("STMERGE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                cin>>c[i][j];
        f[1][1][1]=c[1][1];
        f[1][1][2]=c[1][1];
        for (int i=2;i<=n;i++)
        {
            f[i][1][2]=c[i][1];
            f[i][1][1]=min(f[i-1][1][1],f[i-1][1][2]+c[i][1]);
        }
        for (int i=2;i<=m;i++)
        {
            f[1][i][1]=c[1][i];
            f[1][i][2]=min(f[1][i-1][2],f[1][i-1][1]+c[1][i]);
        }
        for (int i=2; i<=n; i++)
            for (int j=2; j<=m; j++)
            {
                f[i][j][1]=min(f[i-1][j][1],f[i-1][j][2]+c[i][j]);

                f[i][j][2]=min(f[i][j-1][2],f[i][j-1][1]+c[i][j]);
            }
        cout<<min(f[n][m][1],f[n][m][2])<<"\n";
    }
    return 0;
}
