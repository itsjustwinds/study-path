#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,m,a[maxn];
long long f[maxn][501][2],res;
int main()
{
    freopen("taytruc.inp","r",stdin);
    //freopen("taytruc.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        f[i][0][0]=max(f[i-1][1][0],f[i-1][0][0]);
        f[i][1][1]=f[i-1][0][0];
        for (int j=2;j<=m;j++)
        {
                f[i][j][0]=f[i-1][j+1][0];
                f[i][j][1]=f[i-1][j-1][1]+a[i];
        }
    }
    res=max(f[n][0][0],f[n][0][1]);
    for (int j=1;j<=m;j++)
        res=max(res,max(f[n][j][0],f[n][j][1]));
    cout<<res;
    return 0;
}
