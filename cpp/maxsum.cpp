#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,a[maxn];
long long f[maxn][maxn],g[maxn][maxn],res,res1;
int main()
{
    //freopen("maxsum.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    res=-100000000000007;
    for (int i=1;i<=n;i++)
    {
        res1=-100000000000007;
    for (int j=i;j<=n;j++)
    {
        f[i][j]=f[i][j-1]+a[j];
        g[i][j]=g[i][j-1]+abs(a[j]);
        res1=max(res1,g[i][j]+f[i][j]);
    }
    res=max(res,res1);
    }
    cout<<res;
}
