#include<bits/stdc++.h>
#define maxn 1111111
#define fs first
#define sc second
#define ll long long
using namespace std;
int a[25][25],n;
typedef pair<int,ll> II;
II f[25][maxn];
int main()
{
    freopen("maugiao.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    f[0][0]=II(0,1);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int k=0; k<(1<<n); k++)
                if (f[i-1][k].sc!=0)
                {
                    if (k&(1<<(j-1))) continue;
                    int nw=k|(1<<(j-1));
                    if (f[i][nw].fs<f[i-1][k].fs+a[i][j])
                    {
                        f[i][nw].fs=f[i-1][k].fs+a[i][j];
                        f[i][nw].sc=f[i-1][k].sc;
                        continue;
                    }
                    if (f[i][nw].fs==f[i-1][k].fs+a[i][j])
                    {
                        f[i][nw].sc+=f[i-1][k].sc;
                        continue;
                    }
                }
    cout<<f[n][(1<<n)-1].fs<<" "<<f[n][(1<<n)-1].sc;
    return 0;
}
