#include<bits/stdc++.h>
#define maxn 1005
#define mod 1000000007
#define ll long long
using namespace std;
int f[maxn][maxn];
int n,a[maxn];
int main()
{
      freopen("DOITIEN.inp","r",stdin);
      freopen("DOITIEN.out","w",stdout);
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n;
      for (int i=1;i<=n;++i)
        cin>>a[i];
      for (int i=1;i<=n;++i)
        f[0][i]=1;
        f[0][0]=1;
      for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
                f[i][j]=(f[i-1][j-1]+f[i][j-1])%mod;
      ll res=0;
      for (int i=1;i<=n;++i)
        res=(res+f[i][n])%mod;
      cout<<res;
      return 0;
}

