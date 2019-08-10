#include <bits/stdc++.h>
#define maxn 3005
#define oo 1000000007
using namespace std;
int n,m;
int doc[maxn][maxn],ngang[maxn][maxn],cheo1[2*maxn],cheo2[2*maxn],a[maxn][maxn];
void khoitao()
{
    for (int i=1;i<=m;i++)
        doc[1][i]=a[1][i];
    for (int i=1;i<=n;i++)
        ngang[i][1]=a[i][1];
    for (int i=2;i<=n;i++)
        for (int j=2;j<=m;j++)
        {
            doc[i][j]=doc[i-1][j]+a[i][j];
            ngang[i][j]=ngang[i][j-1]+a[i][j];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cheo1[i+j-1]+=a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cheo2[maxn+j-i]+=a[i][j];
}
int main()
{
    freopen("queen.inp","r",stdin);
    freopen("queen.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];
    khoitao();
    int res=-oo;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
    {
        res=max(res,doc[n][j]+ngang[i][m]+cheo1[i+j-1]+cheo2[maxn+j-i]-3*a[i][j]);
    }
    cout<<res;
    return 0;
}
