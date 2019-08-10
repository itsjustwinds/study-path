#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][maxn],n,m,a[maxn],b[maxn];
int main()
{
    freopen("lnacs.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];

    for (int i=1; i<=n; i++)
        if(a[i]==b[1]) f[i][1]=1;
        else f[i][1]=f[i-1][1];

    for (int i=1; i<=m; i++)
        if(a[1]==b[i]) f[1][i]=1;
        else f[1][i]=f[1][i-1];

    for (int i=2; i<=n; i++)
        for (int j=2; j<=m; j++)
        {
            f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i][j-1]));
            if (a[i]==b[j]) f[i][j]=max(f[i][j],f[i-2][j-2]+1);
        }
    cout<<f[n][m];
    return 0;
}
