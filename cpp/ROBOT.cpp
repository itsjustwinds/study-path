#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int f[maxn][maxn][205],n,m,p,k,dd[maxn][maxn];
char s[205];
bool check(int i,int j)
{
    return dd[i][j]||i==0||i==n+1||j==0||j==m+1;
}
int main()
{
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p>>k;
    cin>>(s+1);
    for (int i=1;i<=p;++i)
    {
        int x,y;
        cin>>x>>y;
        dd[x][y]=1;
    }
    for (int h=0;h<=k;++h)
        for (int i=0;i<=n+1;++i)
        for (int j=0;j<=m+1;++j)
        f[i][j][h]=1e9;
    f[1][1][0]=0;
    for (int h=1;h<=k;++h)
        for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    {
        if (dd[i][j]) continue;
        if (s[h]=='U')
        {
            f[i][j][h]=min(f[i][j][h],f[i][j][h-1]+1);
            f[i][j][h]=min(f[i][j][h],f[i+1][j][h-1]);
            if (check(i-1,j)) f[i][j][h]=min(f[i][j][h],f[i][j][h-1]);
        }
        if (s[h]=='D')
        {
            f[i][j][h]=min(f[i][j][h],f[i][j][h-1]+1);
            f[i][j][h]=min(f[i][j][h],f[i-1][j][h-1]);
            if (check(i+1,j)) f[i][j][h]=min(f[i][j][h],f[i][j][h-1]);
        }
        if (s[h]=='L')
        {
            f[i][j][h]=min(f[i][j][h],f[i][j][h-1]+1);
            f[i][j][h]=min(f[i][j][h],f[i][j+1][h-1]);
            if (check(i,j-1)) f[i][j][h]=min(f[i][j][h],f[i][j][h-1]);
        }
        if (s[h]=='R')
        {
            f[i][j][h]=min(f[i][j][h],f[i][j][h-1]+1);
            f[i][j][h]=min(f[i][j][h],f[i][j-1][h-1]);
            if (check(i,j+1)) f[i][j][h]=min(f[i][j][h],f[i][j][h-1]);
        }
    }
    cout<<f[n][m][k];
}
