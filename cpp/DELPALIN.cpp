#include<bits/stdc++.h>
#define maxn 305
using namespace std;
int f[maxn][maxn],dp[maxn][maxn],n;
char s[maxn];
void solve()
{
    for (int i=1; i<=n; ++i)
        f[i][i]=1;
    for (int i=1; i<n; ++i)
        if (s[i]==s[i+1])
            f[i][i+1]=1;
        else
            f[i][i+1]=2;
    for (int k=2;k<=n;++k)
    for (int i=k-1;i>=1;--i){
        if (s[i]==s[k]) f[i][k]=min(f[i][k],f[i+1][k-1]);
        for (int j=i;j<k;++j)
            f[i][k]=min(f[i][k],f[i][j]+f[j+1][k]);
    }
    cout<<f[1][n]<<"\n";
}
int main()
{
    freopen("DELPALIN.inp","r",stdin);
    //freopen("DELPALIN.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--) {
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1; i<=n+1; ++i) {
            for (int j=1; j<=n+1; ++j){
                f[i][j]=1e9;
            }
        }
        solve();
    }
}
