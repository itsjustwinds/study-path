#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int cost[maxn][maxn],n,f[maxn][maxn][maxn],res;
int main() {
    freopen("DISNEY1.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>cost[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            for (int k=1; k<=n; ++k)
                f[i][j][k]=1e9;
    f[1][1][1]=0;
    for (int k=2; k<=n; ++k) {
        for (int i=1; i<=k-1; ++i) {
            // k-1 to k
            f[k][k][i]=min(f[k][k][i],f[k-1][k-1][i]+cost[k-1][k]);
            f[k][i][k]=min(f[k][i][k],f[k-1][i][k-1]+cost[k-1][k]);
            // i to k
            f[k][k-1][k]=min(f[k][k-1][k],f[k-1][k-1][i]+cost[i][k]);
            f[k][k][k-1]=min(f[k][k][k-1],f[k-1][i][k-1]+cost[i][k]);
        }
    }
    res=1e9;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (f[n][i][j]+cost[i][1]+cost[j][1]<res)
            res=f[n][i][j]+cost[i][1]+cost[j][1];
    cout<<res;
}
