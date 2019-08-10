#include <bits/stdc++.h>
#define oo 100000000;
using namespace std;
int a[1001],f[1001][51],n,k;
int main()
{
    //freopen("qbseq.inp","r",stdin);
    //freopen("qbseq.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        a[i]=a[i]%k;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=k-1;j++)
            f[i][j]=-oo;
    f[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=k-1;j++)
            f[i][j]=max(f[i-1][j],f[i-1][(k+j-a[i])%k]+1);
    }
    cout<<f[n][0];
    return 0;
}
