#include<bits/stdc++.h>
#define oo 1000000000
#define maxn 105
using namespace std;
int f[maxn][maxn],a[maxn][maxn],n,m;
int main()
{
    freopen("qbmax.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];
    for (int i=1;i<=m;i++)
    {
        f[0][i]=-oo;
        f[n+1][i]=-oo;
    }
    for (int i=1;i<=n;i++)
    {
        f[i][0]=-oo;
        f[i][m+1]=-oo;
    }
    for (int i=1;i<=n;i++)
        f[i][1]=a[i][1];
    for (int j=2;j<=m;j++)
        for(int i=1;i<=n;i++)
        f[i][j]=max(f[i-1][j-1],max(f[i][j-1],f[i+1][j-1]))+a[i][j];
    int res=-oo;
    for (int i=1;i<=n;i++)
        res=max(res,f[i][m]);
    cout<<res;
    return 0;
}
