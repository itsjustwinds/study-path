#include<bits/stdc++.h>
#define maxn 30
using namespace std;
int f[maxn][4],a[maxn][4],n;
int main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=3; j++)
                cin>>a[i][j];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=3; j++) f[i][j]=1000000000;
        f[1][1]=a[1][1];
        f[1][2]=a[1][2];
        f[1][3]=a[1][3];
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=3; j++)
                for (int k=1; k<=3; k++)
                {
                    if (j==k) continue;
                    f[i][j]=min(f[i-1][k]+a[i][j],f[i][j]);
                }
        }
        cout<<min(f[n][1],min(f[n][2],f[n][3]))<<"\n";
    }
    return 0;
}
