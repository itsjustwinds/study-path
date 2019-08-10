#include<bits/stdc++.h>
#define maxn 100005
#define mod 2111992
using namespace std;
int f[maxn][2],k,bit[maxn][2],n;
int main()
{
    freopen("CTNBULLS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    f[1][0]=1;
    f[1][1]=1;
    for (int i=2;i<=k+1;i++)
    {
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        f[i][1]=1;
    }
    for (int i=k+2; i<=n; i++)
    {
        //f[i][0] is cows
        //f[i][1] is bulls
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        f[i][1]=f[i-k][0]%mod;
    }
    int res=(f[n][0]+f[n][1])%mod;
    cout<<res;
    return 0;
}
