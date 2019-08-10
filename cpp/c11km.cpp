#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][maxn],n,a[maxn],cnt[maxn];
int main()
{
    freopen("c11km.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        f[i][j]=1000000000;
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+(a[i]>100);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=cnt[i];j++)
        {
            if (j<=cnt[i-1]) f[i][j]=f[i-1][j]+a[i];
            if (j<cnt[i-1]) f[i][j]=min(f[i][j],f[i-1][j+1]);
            if (j>0&&a[i]>100) f[i][j]=min(f[i][j],f[i-1][j-1]+a[i]);
        }
    }
    int res=1000000000;
    for (int i=0;i<=cnt[n];i++)
        res=min(res,f[n][i]);
    cout<<res;
    return 0;
}
